/*
** my_putstr.c for my_putstr in /home/pereni_j/rendu/PSU_2014_my_select
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jan  7 11:31:52 2015 Pereniguez Joseph
** Last update Sun Jan 11 15:40:04 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
