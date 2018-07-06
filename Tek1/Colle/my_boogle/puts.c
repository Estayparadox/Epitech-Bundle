/*
** puts.c for puts in /home/pereni_j/Colle_6
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jun  2 18:26:28 2015 joseph pereniguez
** Last update Tue Jun  2 21:21:59 2015 joseph pereniguez
*/

#include "my_boogle.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
