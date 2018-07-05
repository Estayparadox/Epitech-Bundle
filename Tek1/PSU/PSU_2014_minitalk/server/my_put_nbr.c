/*
** my_put_nbr.c for my_put_nbr in /home/pereni_j/rendu/PSU_2014_minitalk/includes
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Mar 17 13:45:53 2015 Pereniguez Joseph
** Last update Sun Mar 22 10:42:48 2015 Pereniguez Joseph
*/

#include "my_server.h"

void		my_put_nbr(int nb)
{
  int		div;
  int		i;

  div = 1;
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  if (nb < 0 || nb >= 10)
    {
      i = nb % 10;
      div = nb / 10;
      my_put_nbr(div);
      my_putchar(i + '0');
    }
  else
    my_putchar(nb + '0');
}
