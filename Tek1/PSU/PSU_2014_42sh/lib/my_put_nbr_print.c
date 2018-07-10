/*
** my_put_nbr_printf.c for my_printf in /home/arrazo_p/PSU_2014_my_printf
** 
** Made by pedroantonio arrazolaleon
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sun Nov 16 14:12:42 2014 pedroantonio arrazolaleon
** Last update Fri Jan 23 15:42:31 2015 pedroantonio arrazolaleon
*/

#include "my_printf.h"

int     my_put_nbr_print(int nb)
{
  if (nb > 2147483647)
    nb = -2147483648 + (2147483647 - nb);
  if (nb < 0)
    {
      nb = - nb;
      my_putchar('-');
    }
  if (nb >= 10)
    {
      my_put_nbr_print(nb / 10);
      my_put_nbr_print(nb % 10);
    }
  else
    my_putchar_print(nb + 48);
  return (0);
}
