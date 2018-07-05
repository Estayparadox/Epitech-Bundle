/*
** my_puts.c for my_puts in /home/pereni_j/rendu/MUL_2014_rtv1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Mar 12 16:07:26 2015 Pereniguez Joseph
** Last update Thu Mar 12 16:11:01 2015 Pereniguez Joseph
*/

#include "mlx.h"
#include "rtv1.h"

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
      i = i + 1;
    }
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}
