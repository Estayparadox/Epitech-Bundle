/*
** xmemset.c for 42sh in /home/arrazo_p/Systeme_Unix/PSU_2014_minishell1/sources
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Fri Jan 30 12:02:15 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:54:55 2015 Vatinelle Maxime
*/

#include "../42sh.h"

char	*xmemset(char *str)
{
  int	i;

  i = 0;
  while (i < 4096)
    {
      str[i] = 0;
      i++;
    }
  return (str);
}
