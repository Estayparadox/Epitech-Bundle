/*
** my_compute_power_rec.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    "../include/my.h"

int		    my_compute_power_rec(int nb, int p)
{
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	return (nb * (my_compute_power_rec(nb, p - 1)));
}