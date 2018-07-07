/*
** my_getnbr.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    "my.h"

int         my_getnbr(char const *str)
{
    int         i;
    int         negative;
    int         number;

    i = 0;
    negative = 0;
    number = 0;
    while ((str[i] < 48 || str[i] > 57))
    	i++;
    if (str[i] == 45)
    	negative = 1;
    if ((str[i] == 43) || (str[i] == 45))
    	i++;
    while ((str[i] >= 48) && (str[i] <= 57))
    {
    	number *= 10;
    	number += ((int)str[i] - 48);
    	i++;
    }
    if (number == -1342177238 || -number == -1342177238)
    	return (0);
    if (negative == 1)
    {
    	return (-number);
    }
    else
    {
    	return (number);
    }
}