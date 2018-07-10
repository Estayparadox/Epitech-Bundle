/*
** xputstr.c for 42sh in /home/arrazo_p/Systeme_Unix/PSU_2014_minishell1/sources
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Fri Jan 30 11:35:54 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:55:39 2015 Vatinelle Maxime
*/

#include "../42sh.h"

void	my_xputchar(char c)
{
  write(2, &c, 1);
}

int	my_xputstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_xputchar(str[i]);
      i++;
    }
  return (0);
}
