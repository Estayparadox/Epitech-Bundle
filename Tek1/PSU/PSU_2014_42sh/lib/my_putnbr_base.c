/*
** my_putnbr_base.c for my_printf in /home/arrazo_p/PSU_2014_my_printf
** 
** Made by pedroantonio arrazolaleon
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sat Nov 15 22:22:21 2014 pedroantonio arrazolaleon
** Last update Fri Jan 23 15:45:47 2015 pedroantonio arrazolaleon
*/

#include "my_printf.h"

void	my_recu(int nbr, int ba, char *base)
{
  if (nbr / ba)
    {
      my_recu(nbr / ba, ba, base);
      my_recu(nbr % ba, ba, base);
    }
  if (nbr / ba == 0)
    my_putchar_print(base[nbr]);
}

int	my_putnbr_base(int nbr, char *base)
{
  int	ba;

  ba = 0;
  if (nbr < 0)
    {
      nbr = - nbr;
      my_putchar_print('-');
    }
  while (base[ba] != '\0')
    ba = ba + 1;
  if (ba == 0)
    return (nbr);
  my_recu(nbr, ba, base);
  return (nbr);
}
