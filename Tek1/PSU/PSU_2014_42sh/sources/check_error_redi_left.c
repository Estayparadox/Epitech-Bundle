/*
** check_error_redi_left.c for 42sh in /home/Blaack-Out/rendu/42sh/PSU_2014_42sh
** 
** Made by VATINELLE maxime
** Login   <Blaack-Out@epitech.net>
** 
** Started on  Thu May 14 12:35:39 2015 VATINELLE maxime
** Last update Sun May 24 14:50:06 2015 Vatinelle Maxime
*/

#include "../42sh.h"

int	check_error_redi_left2(t_mini *shell, int i)
{
  if (shell->command[i + 2] == '~')
    {
      printf("bash: %s: est un dossier\n", my_parse_env("HOME=", shell->env));
      return (0);
    }
  else if (shell->command[i + 2] == '/')
    {
      printf("bash: %c: est un dossier", shell->command[i + 2]);
      return (0);
    }
  else
    redi_left(shell);
  return (0);
}

int	check_error_redi_left(t_mini *shell, int i)
{
  if (shell->command[i + 2] == '&' || shell->command[i + 2] == '#' ||
      shell->command[i + 2] == '(' || shell->command[i + 2] == ')' ||
      shell->command[i + 2] == '|' || shell->command[i + 2] == ';')
    {
      printf("bash: syntax error near unexpected token %c\n",
	     shell->command[i + 2]);
      return (0);
    }
  else if (shell->command[i + 2] == '*' || shell->command[i + 2] == '.'
	   || shell->command[i + 2] == '?')
    {
      printf("bash: %c: ambigous redirect\n", shell->command[i + 2]);
      return (0);
    }
  else
    check_error_redi_left2(shell, i);
  return (0);
}
