/*
** my_get_digit_weight.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    "../include/my.h"

int         my_get_digit_weight(char c, char *base)
{
    int     i;

    i = 0;
    while (base[i] != '\0')
    {
        if (base[i] == c)
            return (i);
        i += 1;
    }
    return (-1);
}
