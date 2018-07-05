/*
** my_strlen.c for my_strlen in /home/pereni_j/rendu/PSU_2014_my_select
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jan  7 11:29:33 2015 Pereniguez Joseph
** Last update Sun Jan 11 15:40:45 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
      i = i + 1;
  return (i);
}
