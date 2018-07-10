/*
** my_put_nbr.c for  in /home/arrazo_p/PSU_2014_my_printf/b
** 
** Made by pedroantonio arrazolaleon
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sun Nov 16 18:11:49 2014 pedroantonio arrazolaleon
** Last update Fri Jan 23 15:53:38 2015 pedroantonio arrazolaleon
*/

#include "my_printf.h"

int     my_put_nbr(int nb)
{
  unsigned int   div;

  if (nb < 0)
    {
      if (nb == -2147463648)
        {
          return (0);
        }
      nb = nb * -1;
      my_putchar('-');
    }
  div = 1;
  while (nb / div >= 10)
    {
      div = div * 10;
    }
  while (div >= 1)
    {
      my_putchar(nb / div + '0');
      nb = nb % div;
      div = div /10;
    }
  return (0);
}
