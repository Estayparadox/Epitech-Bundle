/*
** xmalloc.c for 42sh in /home/arrazo_p/semestre2/SystemeUnix/PSU_2014_minishell2/sources
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Thu Feb 12 18:28:18 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:54:23 2015 Vatinelle Maxime
*/

#include "../42sh.h"

void	*xmalloc(int len)
{
  void	*str;

  if ((str = malloc(len)) == NULL)
    {
      my_xputstr("Error malloc\n");
      exit(1);
    }
  return (str);
}
