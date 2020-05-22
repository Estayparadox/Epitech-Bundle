/*
** my_power_rec.c for my_power_rec in /home/pereni_j/rendu/CPE_2014_Pushswap
**
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri Dec 12 17:11:58 2014 Pereniguez Joseph
** Last update Fri Dec 12 17:22:25 2014 Pereniguez Joseph
*/

#include "pushswap.h"

int	    get_res(int nb, int power, int res, int i)
{
    if (power < 0)
        return (0);

    if (power == 0)
        return (1);

    if (i < power) {
        res = res * nb;
        i = i + 1;
        if (i > 12)
	        return (0);
        get_res(nb, power, res, i);

    }
    return (res);
}

int	    my_power_rec(int nb, int power)
{
    int     i;
    int     res;

    i = 0;
    res = get_res(nb, power, 1, i);
    return (res);
}
