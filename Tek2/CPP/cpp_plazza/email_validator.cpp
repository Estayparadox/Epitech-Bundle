//
// email_validator.cpp for email_validator in /home/pereni_j/Transfert
//
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
//
// Started on  Tue Apr 12 10:57:28 2016 pereniguez joseph
// Last update Sun Apr 24 23:05:54 2016 pereniguez joseph
//

#include "Parser.hpp"

Parser::Parser()
{}

Parser::~Parser()
{}

bool	Parser::isCharacter(const char Character)
{
  return ( (Character >= 'a' && Character <= 'z') || (Character >= 'A' && Character <= 'Z'));
}

bool		Parser::isNumber(const char Character)
{
  return ( Character >= '0' && Character <= '9');
}

bool		Parser::isValidIPAddress(char *st)
{
  int		num;
  int		i;
  int		len;
  char		*ch;
  int		quadsCnt = 0;

  len = strlen(st);

  if(len<7 || len>15)
    return false;

  ch = strtok(st, ".");
  while (ch != NULL)
    {
      quadsCnt++;
      num = 0;
      i = 0;
      while(ch[i]!='\0')
        {
          num = num*10;
          num = num+(ch[i]-'0');
          i++;
        }

      if(num<0 || num>255)
	{
	  return false;
	}

      if( (quadsCnt == 1 && num == 0) || (quadsCnt == 4 && num == 0))
	{
	  return false;
	}
      ch = strtok(NULL, ".");
    }

  if(quadsCnt!=4)
    {
      return false;
    }
  return true;
}


bool		Parser::isValidEmailAddress(const char * EmailAddress)
{
  if(!EmailAddress)
    return 0;
  if(!isCharacter(EmailAddress[0]))
    return 0;

  int		AtOffset = -1;
  int		DotOffset = -1;
  unsigned int	Length = strlen(EmailAddress);

  for(unsigned int i = 0; i < Length; i++)
    {
      if(EmailAddress[i] == '@')
	AtOffset = (int)i;
      else if(EmailAddress[i] == '.')
	DotOffset = (int)i;
    }
  if(AtOffset == -1 || DotOffset == -1)
    return 0;
  if(AtOffset > DotOffset)
    return 0;
  return !(DotOffset >= ((int)Length-1));
}

int		Parser::parserEA(std::string file, std::string catgr)
{
  char		*myFile = (char *)file.c_str();
  std::ifstream	flux(myFile);
  int		itsOk = 0;
  std::string	polo;
  std::string	fileWord1;
  std::string	mailto;
  int		length;
  std::vector<std::string> vector;
  int		i(0);

  if (flux)
    {
      std::string	fileWord;

      while (flux >> fileWord)
	{
	  if (isValidEmailAddress(fileWord.c_str()))
	    {
	      replace(fileWord.begin(), fileWord.end(), '<', ' ');
	      replace(fileWord.begin(), fileWord.end(), '>', ' ');
	      replace(fileWord.begin(), fileWord.end(), '"', ' ');
	      replace(fileWord.begin(), fileWord.end(), ':', ' ');

	      std::istringstream cpy1(fileWord);

	      while (getline(cpy1, mailto, ' '))
		{
		  vector.push_back(mailto);
		}

	      for (std::vector<std::string>::iterator it = vector.begin(); it != vector.end(); ++it)
		{
		  if (*it == "mailto")
		    {
		      std::cout << it[i + 1] << std::endl;
		    }
		}

	      itsOk = 1;
	      return 0;
	    }
	}

      if (itsOk == 0)
	return (-1);
    }
  else
    return (-1);
}

int		Parser::parserIA(std::string file, std::string catgr)
{
  char          *myFile = (char *)file.c_str();
  std::ifstream	flux(myFile);
  int           itsOk = 0;

  if (flux)
    {
      std::string	fileWord;

      while (flux >> fileWord)
	{
	  char	*st = (char *)fileWord.c_str();

	  if (isValidIPAddress(st))
	    {
	      std::cout << fileWord << std::endl;
	      itsOk = 1;
	      return 0;
	    }

	  if (itsOk == 1)
	    return 0;

	}
      if (itsOk == 0)
	return  (-1);
    }
  else
    return (-1);
}
