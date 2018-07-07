/*
** my_is_prime.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

int		my_is_prime(int nbr)
{
  int		i;

  i = 2;
  while (i <= nbr / 2)
    {
      if (nbr % i == 0)
	return (0);
      i += 1;
    }
  return (1);
}
