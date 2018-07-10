/*
** my_strlen.c for 42sh in /home/arrazo_p/semestre2/SystemeUnix/PSU_2014_minishell2/sources
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Thu Feb 12 18:39:37 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:53:18 2015 Vatinelle Maxime
*/

#include "../42sh.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
