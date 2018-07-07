#!/usr/bin/php
<?php
/***************************************
****************************************
****************************************
***                                  ***
***   Moulinette du projet Trade     ***
***                           2016   ***
***                                  ***
****************************************
****************************************
****************************************/


define('ENDFILE',	"--END--\n");
define('EXEC',		'./');
define('BUY',		'buy');
define('SELL',		'sell');
define('PASS',		'wait');
define('IN',		0);
define('OUT',		1);
define('SPREAD',	0.15);


/****************************************************************************
***   COLORS
*****************************************************************************/
class	Color
{
	const	RED 				= "\033[31m";
	const	GREEN 			= "\033[32m";
  	const	DEFAULTCOLOR	= "\033[39m";
}



/****************************************************************************
***   ERROR
*****************************************************************************/
class	tradeError
{
	const	INVALIDCMD			= 1;
	const	BADARGUMENT			= 2;
	const	ARGNOTNUMERIC		= 4;
	const	CANTBUY				= 8;
	const	CANTSELL				= 16;
	const	CANTBUYLASTDAY		= 32;
	const	SELLISMANDATORY	= 64;

	static private $a_error = array(self::INVALIDCMD 		=> 'Invalid command',
			  	  							self::BADARGUMENT 		=> 'Bad argument for this command',
				  							self::ARGNOTNUMERIC 		=> 'Argument is not numeric',
											self::CANTBUY 				=> 'You can not buy',
											self::CANTBUYLASTDAY		=> 'You can not buy the last day',
										  	self::CANTSELL 			=> 'You can not sell',
								 		 	self::SELLISMANDATORY	=> 'You should sell your shares the last day');

	static public function getError($i_errorNum)
	{
		if (array_key_exists($i_errorNum, self::$a_error))
      		return (self::$a_error[$i_errorNum]);
    	return (NULL);
  	}
}



/****************************************************************************
***   ARGUMENTS
*****************************************************************************/
/* Checks the number of arguments
** @param	array		$a_param Parameters
** @return	boolean	true if parameter exists. */
function	checkParam($i_argc, $a_argv)
{
	if ($i_argc >= 7)
		return (true);
	echo "\nUsage:\n\t".
			$a_argv[0]." -p prog -f file -m money [-o] [-s]\n".
	     "Description:\n".
			"\t-p\ttrade program\n".
			"\t-f\tstock option values\n".
			"\t-m\tintial money\n".
			"\t-o\tverbose mode\n".
			"\t-s\tshort info\n\n";
	return (false);
}

/* Checks options
** @param	array		$a_opt	Options
** @return	boolean	true if require option exists. */
function	checkOpt($a_opt)
{
	$a_requireOpt	= array("p", "f", "m");
	$s_value			= NULL;

	foreach ($a_requireOpt as $s_value)
		if (array_key_exists($s_value, $a_opt) === false)
		{
			echo "Error: Missing option [".$s_value."]\n";
			return (false);
		}
	return (true);
}

/* Checks file validity.
** @param	string	$s_file	file name
** @return	boolean	true if the file is correct */
function	checkFile($s_file)
{
	if (!file_exists($s_file))
	{
		echo "Error: \"".$s_file."\" doesn't exist.\n";
		return (false);
	}
	if (count(file($s_file)) < 3)
	{
		echo "Error: \"".$s_file."\" is not valid.\n";
		return (false);
	}
	return (true);
}



/****************************************************************************
***   INIT & ASSESSMENT
*****************************************************************************/
/* Initialisation of the trade structure.
** @param	array	&$a_trade	trade information
**				array	&$a_opt		option information
** @return	none */
function	init(&$a_trade, &$a_opt)
{
	$i_sum							= 0;
	$a_trade['money']				= $a_opt['m'];
	$a_trade['currentMoney']	= $a_trade['money'];
	$a_trade['action']			= array();
	$a_trade['actionIndex']		= 0;
	$a_trade['currentDay']		= 0;
	$a_trade['share']				= 0;
	$a_trade['error']				= 0;
	$a_trade['program']			= NULL;
	$a_trade['data'] 				= file($a_opt['f']);
	$a_trade['daysNb']			= count($a_trade['data']) - 1;

	if (strncmp($a_opt['p'], EXEC, 2))
		$a_trade['program'] = EXEC;
	$a_trade['program'] .= $a_opt['p'];
}

/* Sums up information
** @param 	array	$a_trade	trade information
**				array	$a_opt	trade options
** @return	none */
function	tradeInfo($a_trade, $a_opt)
{
	$i_total	= $a_trade['currentMoney'] - $a_trade['money'];
	$f_avg	= round($i_total/$a_trade['daysNb'], 2);
	if (isset($a_opt['s']))
	{
		echo "$f_avg";
		return;
	}
	echo "[PERIOD]\t".$a_trade['daysNb']." days\n";
	echo "[PROFIT]\t".($i_total > 0 ? Color::GREEN.'+' : Color::RED).$i_total.Color::DEFAULTCOLOR;
	echo " (from ".$a_trade['money'].")\n";
   echo "[AVERAGE]\t".($i_total > 0 ? Color::GREEN.'+' : Color::RED).$f_avg.Color::DEFAULTCOLOR." per day\n";
	echo "[ERROR]\t\t";
	if ($a_trade['error'])
		echo Color::RED.tradeError::getError($a_trade['error']).Color::DEFAULTCOLOR."\n";
	else
		echo "none\n";
}



/****************************************************************************
***   COMMAND EXEC
*****************************************************************************/
/* Checks the current action.
** @param	array		&$a_trade	trade information
**				string	$s_buffer	command string
** @return	boolean	false is an error occured. */
function	actionIsValid(&$a_trade, $s_buffer)
{
	$a_cmd	= array(BUY, SELL, PASS);
	$a_data	= array();

	$a_trade['action'][$a_trade['actionIndex']] = $s_buffer;
	++$a_trade['actionIndex'];
	$s_buffer	= trim($s_buffer, "\n");
	$a_data		= explode(' ', $s_buffer);
	$s_cmd		= $a_data[0];
	if (!in_array($s_cmd, $a_cmd))
	{
		$a_trade['error'] = tradeError::INVALIDCMD;
		return (false);
	}
	if ($s_cmd != PASS && !cmdIsValid($a_trade, $s_cmd, $a_data))
		return (false);
	return (true);
}

/* Checks command validity
** @param	array		&$a_trade	trade information
** 			string	$s_cmd		command string
** 			array		$a_argument	command argument
** @return	boolean	false is an error occured.*/
function	cmdIsValid(&$a_trade, $s_cmd, $a_argument)
{
	if (count($a_argument) != 2)
	{
		$a_trade['error'] = tradeError::BADARGUMENT;
		return (false);
	}
	if (!is_numeric($a_argument[1]))
	{
		$a_trade['error'] = tradeError::ARGNOTNUMERIC;
		return (false);
	}
	$i_number = intval($a_argument[1]);
	if ($i_number < 0)
	{
		$a_trade['error'] = tradeError::BADARGUMENT;
		return (false);
	}
	if ($s_cmd == BUY)
	{
		if (($i_number * intval(@$a_trade['data'][$a_trade['currentDay']]) > $a_trade['currentMoney']))
 		{
			$a_trade['error'] = tradeError::CANTBUY;
			return (false);
		}
		if ($a_trade['daysNb'] == $a_trade['currentDay'])
		{
			$a_trade['error'] = tradeError::CANTBUYLASTDAY;
			return (false);
		}
	}
	if ($s_cmd == SELL)
	{
		if ($i_number > $a_trade['share'])
		{
			$a_trade['error'] = tradeError::CANTSELL;
			return (false);
		}
	}
	execCmd($a_trade, $s_cmd, $i_number);
	return (true);
}

/* Executes the command.
** @param	array		&$a_trade	trade information
** 			string	$s_cmd		Command string
**				int		$i_number	Share number
** @return none */
function	execCmd(&$a_trade, $s_cmd, $i_number)
{
	$i_money	= $i_number * intval(@$a_trade['data'][$a_trade['currentDay']]);
	$i_comm	= intval(ceil($i_money * SPREAD /100));
	if ($s_cmd == BUY)
	{
		$a_trade['currentMoney']	+= -$i_money - $i_comm;
		$a_trade['share']				+= $i_number;
	}
	else if ($s_cmd == SELL)
	{
		$a_trade['currentMoney']	+= $i_money - $i_comm;
		$a_trade['share']				-= $i_number;
	}
}




/****************************************************************************
***   PROGRAM
*****************************************************************************/
/* Core trade, calls a process. Send information to this process.
** @param	array	&$a_trade	trade information
**				array	$a_opt		trade option
** @return	none */
function	trade(&$a_trade, $a_opt)
{
	$s_buffer	= NULL;
	$b_start		= false;
	$a_descriptor 	= array(	0 => array('pipe', 'r'),
									1 => array('pipe', 'w'),
									2 => array('file', 'error.file', 'w'));
	$a_pipes		= array();
	$r_fd 		= proc_open($a_trade['program'], $a_descriptor, $a_pipes);
	if (is_resource($r_fd))
	{
		while (true)
		{
			if ($b_start === false)
			{
				$b_start = true;
				fwrite($a_pipes[IN], $a_trade['money']."\n");
				fwrite($a_pipes[IN], $a_trade['daysNb']."\n");
				fwrite($a_pipes[IN], $a_trade['data'][$a_trade['currentDay']]);
			}
			$s_buffer = fgets($a_pipes[OUT]);
 			if ($s_buffer === false)
				break;
			if (@$a_trade['data'][$a_trade['currentDay']] == ENDFILE)
			{
				echo ENDFILE."\n";
				break;
			}
			if (!actionIsValid($a_trade, $s_buffer))
				break;
			if (isset($a_opt['o']))
			{
				echo '['.trim($a_trade['data'][$a_trade['currentDay']], "\n").'] -> ';
				echo trim($a_trade['action'][$a_trade['actionIndex'] - 1], "\n")."\n";
			}
			fwrite($a_pipes[IN], @$a_trade['data'][++$a_trade['currentDay']]);
		}
		if ($a_trade['share'])
			$a_trade['error'] = tradeError::SELLISMANDATORY;
		proc_close($r_fd);
	}
}

/* Main function
** @param	int	$i_argc	number of arguments
**				array	$a_argv	arguments
** @return	none */
function	main($i_argc, $a_argv)
{
  $a_opt			= getopt("of:p:m:s", array());
  $a_trade		= array();

  if (checkParam($i_argc, $a_argv) === false)
    return ;
  if (checkOpt($a_opt) === false)
    return ;
  if (checkFile($a_opt['f']) === false)
    return ;
  init($a_trade, $a_opt);
  trade($a_trade, $a_opt);
  tradeInfo($a_trade, $a_opt);
}

main($argc, $argv);
?>
