/*
** my_compute_square_root.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    "../include/my.h"

int			my_find_square(int nb, int bi, int bf)
{
  int			mil;

  if (bi * bi == nb)
    return (bi);
  mil = (bi + (bf - bi) / 2);
  if (bi < bf)
    {
      if (mil * mil == nb)
	return (mil);
      else
	{
	  if (mil * mil > nb)
	    return (my_find_square(nb, bi, mil - 1));
	  else
	    return (my_find_square(nb, mil + 1, bf));
	}
    }
  return (0);
}

int			my_compute_square_root(int nb)
{
  if (nb <= 0)
    return (0);
  return (my_find_square(nb, 1, 46340));
}