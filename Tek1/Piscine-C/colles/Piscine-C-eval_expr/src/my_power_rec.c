/*
** my_power_rec.c for libmy in /home/pereni_j/libmy/sources
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    "../include/my.h"

int	        my_power_rec(int nb, int power)
{
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    int result = nb * my_power_rec(nb, power - 1);
    return (result);
}
