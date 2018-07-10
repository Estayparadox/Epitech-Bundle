/*
** my_putstr.c for 42sh in /home/arrazo_p/rendu/Piscine_C_J04
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Thu Oct  2 20:59:26 2014 arrazolaleon pedroantonio
** Last update Sun May 24 14:52:37 2015 Vatinelle Maxime
*/

#include "../42sh.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
