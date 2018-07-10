/*
** my_strlen_tab.c for 42sh in /home/arrazo_p/semestre2/SystemeUnix/PSU_2014_minishell2/sources
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sun Mar  8 01:46:10 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:53:27 2015 Vatinelle Maxime
*/

#include "../42sh.h"

int     my_strlen_tab(char **str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
