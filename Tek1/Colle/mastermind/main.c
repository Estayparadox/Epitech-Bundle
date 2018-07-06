/*
** main.c for main in /home/pereni_j/Colle4
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu May 21 21:13:57 2015 joseph pereniguez
** Last update Thu May 21 21:53:11 2015 joseph pereniguez
*/

#include "mastermind.h"

int		my_loop(t_code code)
{
  char		buffer[4096];
  int		i;
  int		max;

  i = 1;
  if (code.try == 0)
    max = 11;
  else if (code.try != 0)
    max = code.try + 1;
  while (42)
    {
      my_prompt(i);
      read(0, buffer, 4096);
      if (my_strlen(buffer) > code.slot)
	my_puterror_loop("Too much slot in your code!\n", code);
      if (buffer[0] != '\0' && buffer[0] != '\n')
	{
	  search_code(buffer, code);
	  i = i + 1;
	  if (i == max)
	    exit(0);
	}
    }
  return (0);
}

void		my_prep()
{
  t_code	code;

  code.code = "6241\0";
  code.pawn = "01234567";
  code.slot = 4;
  my_loop_no_op(code);
}

int             my_loop_no_op(t_code code)
{
  char          buffer[4096];
  int           i;

  i = 1;
  while (42)
    {
      my_putstr("Round ");
      my_put_nbr(i);
      my_putstr("\n>");
      read(0, buffer, 4096);
      if (buffer[0] != '\0' && buffer[0] != '\n')
        {
          search_code(buffer, code);
          i = i + 1;
          if (i == 11)
            exit(0);
        }
    }
  return (0);
}

void		pars_argv(char **argv)
{
  int		i;
  t_code	op;

  i = 1;
  while (argv[i])
    {
      if (argv[i][0] == '-' && argv[i][1] == 'c' && argv[i + 1])
	op.code = argv[i + 1];
      if (argv[i][0] == '-' && argv[i][1] == 'p' && argv[i + 1])
	op.pawn = argv[i + 1];
      if (argv[i][0] == '-' && argv[i][1] == 't' && argv[i + 1])
	op.try = my_get_nbr(argv[i + 1]);
      if (argv[i][0] == '-' && argv[i][1] == 's' && argv[i + 1])
	op.slot = my_get_nbr(argv[i + 1]);
      i = i + 1;
    }
  if (op.code == NULL)
    op.code = "6543";
  if (op.pawn == NULL)
    op.code = "01234567";
  if (op.slot == 0)
    op.slot = 4;
  my_loop(op);
}

int		main(int argc, char **argv)
{
  if (argc == 1)
    {
      my_putstr("Trouverez-vous le code secret ?\n\n");
      my_prep();
    }
  else if (argc > 1)
    {
      my_putstr("Trouverez-vous le code secret ?\n\n");
      pars_argv(argv);
    }
  else
    return (-1);
  return (0);
}
