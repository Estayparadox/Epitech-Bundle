/*
** my_nbr.c for eval_expr in /home/pereni_j/Piscine-C-eval_expr/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "include/my.h"
#include "doop.h"

int		            my_bool_int(unsigned int nbr, char bool)
{
    unsigned int	max;
    unsigned int	min;

    max = 2147483647;
    min = 2147483648;
    if ((nbr > max && bool != 1) || (nbr > min && bool == 1))
        return (1);
    return (0);
}

void	rec_my_put_nbr(unsigned int nbr)
{
    if (nbr <= 9)
        my_putchar('0' + nbr);
    else
    {
        rec_my_put_nbr(nbr / 10);
        my_putchar ('0' + (nbr % 10));
    }
}
