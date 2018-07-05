/*
** my_putstr.c for my_putstr in /home/pereni_j/rendu/CPE_2014_bsq
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jan 14 13:57:21 2015 Pereniguez Joseph
** Last update Sun Jan 18 19:30:13 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_puterror(str[i]);
      i = i + 1;
    }
  return (0);
}
