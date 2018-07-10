/*
** check_error_double_redi_right.c for 42sh in /home/Blaack-Out/rendu/42sh/PSU_2014_42sh
** 
** Made by VATINELLE maxime
** Login   <Blaack-Out@epitech.net>
** 
** Started on  Thu May 14 12:33:41 2015 VATINELLE maxime
** Last update Sun May 24 14:15:28 2015 Vatinelle Maxime
*/

#include "../42sh.h"

int	check_error_double_redi_right2(t_mini *shell, int i)
{
  if (shell->command[i + 2] == '~')
    {
      printf("42sh: %s: est un dossier\n", my_parse_env("HOME=", shell->env));
      return (0);
    }
  else if (shell->command[i + 2] == '/')
    {
      printf("42sh: %c: est un dossier", shell->command[i + 2]);
      return (0);
    }
  else
    double_redi_right(shell);
  return (0);
}

int	check_error_double_redi_right(t_mini *shell, int i)
{
  if (shell->command[i + 2] == '&' || shell->command[i + 2] == '#' ||
      shell->command[i + 2] == '(' || shell->command[i + 2] == ')' ||
      shell->command[i + 2] == '|' || shell->command[i + 2] == ';')
    {
      printf("42sh: syntax error near unexpected token %c\n",
	     shell->command[i + 1]);
      return (0);
    }
  else if (shell->command[i + 2] == '*' || shell->command[i + 2] == '.'
	   || shell->command[i + 2] == '?')
    {
      printf("42sh: %c: ambigous redirect\n", shell->command[i + 2]);
      return (0);
    }
  else
    check_error_double_redi_right2(shell, i);
  return (0);
}
