/*
** my_puts.c for my_puts in /home/pereni_j/rendu/PSU_2014_minitalk/client
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Mar 18 11:38:24 2015 Pereniguez Joseph
** Last update Wed Mar 18 11:40:03 2015 Pereniguez Joseph
*/

#include "my_client.h"

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
