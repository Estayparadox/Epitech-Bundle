/*
** my_putnbr_base.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

int		    my_putnbr_base(int nbr, char *base)
{
  int		size;
  int		mod;

  size = 0;
  while (base[size] != '\0')
    size += 1;
  if (size <= 1)
    return (nbr);
  mod = nbr % size;
  if (mod < 0)
    mod = -mod;
  if (nbr / size == 0)
    {
      if (nbr < 0)
	  my_putchar('-');
      my_putchar(base[mod]);
      return (nbr);
    }
  my_putnbr_base(nbr / size, base);
  my_putchar(base[mod]);
  return (nbr);
}
