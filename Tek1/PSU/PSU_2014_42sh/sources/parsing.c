/*
** parsing.c for 42sh in /home/pereni_j/Rendu/PSU_2014_42sh
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue May 19 09:18:49 2015 joseph pereniguez
** Last update Sun May 24 20:04:38 2015 paul rosset
*/

#include "../42sh.h"

int 		check_double_redi_right(t_mini *shell)
{
  int		i;

  i = 0;
  if (shell->command[0] == '>' && shell->command[1] == '>'
      && shell->command[2] == '\0')
    {
      printf("42sh: syntax error near unexpected token `newline'\n");
      return (0);
    }
  while (shell->command[i])
    {
      if (shell->command[i] == '>' && shell->command[i + 1] == '>')
	{
	  check_error_double_redi_right(shell, i);
	  return (1);
	}
      else
      	check_redi_right(shell, i);
      i++;
    }
  return (0);
}

int 		check_redi_right(t_mini *shell, int i)
{
  i = 0;
  if (shell->command[0] == '>' && shell->command[2] == '\0')
    {
      printf("42sh: syntax error near unexpected token `newline'\n");
      return (0);
    }
  while (shell->command[i])
    {
      if (shell->command[i] == '>'&& shell->command[i + 1] != '>' &&
	  shell->command[i - 1] != '>')
	{
	  check_error_redi_right(shell, i);
	  return (1);
	}
      else
	check_redi_left(shell, i);
      i++;
    }
  return (0);
}

int		check_redi_left(t_mini *shell, int i)
{
  i = 0;
  if (shell->command[0] == '<' && shell->command[2] == '\0')
    {
      printf("42sh: syntax error near unexpected token `newline'\n");
      return (0);
    }
  while (shell->command[i])
    {
      if (shell->command[i] == '<'&& shell->command[i + 1] != '<')
	{
	  check_error_redi_left(shell, i);
	  return (1);
	}
      i++;
    }
  return (0);
}
