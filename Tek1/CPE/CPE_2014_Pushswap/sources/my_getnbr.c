/*
** my_getnbr.c for my_getnbr in /home/pereni_j/rendu/CPE_2014_Pushswap
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Dec 12 17:11:58 2014 Pereniguez Joseph
** Last update Fri Dec 12 17:22:25 2014 Pereniguez Joseph
*/

#include "pushswap.h"

int	nbr_comp(char *str)
{
    int	comp;
    int operators;

    operators = find_operator(str);
    comp = operators;
    while (str[comp] >= '0' && str[comp] <= '9') {
        comp = comp + 1;
    }
    comp = comp - operators;
    return (comp);
}

int     find_operator(char *str)
{
    int   i;
    int   z;

    i = 0;
    z = 0;
    while (str[i]) {
        if (str[i] == '+' || str[i] == '-')
            z = z + 1;
        i = i + 1;
    }
    return (z);
}

int	my_getnbr(char *str)
{
    int	i;
    int	s;
    int	lon;
    int	n;

    i = find_operator(str);
    s = 0;
    n = 0;
    lon = nbr_comp(str) - 1;
    while (str[i] >= '0' && str[i] <= '9') {
        s = (str[i] - 48) * my_power_rec(10, lon);
        n = n + s;
        lon = lon - 1;
        i = i + 1;
    }
    i = 0;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
	        n = n * (- 1);
        i = i + 1;
    }
    return (n);
}
