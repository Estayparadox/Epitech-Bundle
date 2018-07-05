/*
** my_strlen.c for my_strlen in /home/pereni_j/rendu/CPE_2014_bsq
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jan 14 13:58:10 2015 Pereniguez Joseph
** Last update Sun Jan 18 19:26:15 2015 Pereniguez Joseph
*/

#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i = i + 1;
    }
  return (i);
}
