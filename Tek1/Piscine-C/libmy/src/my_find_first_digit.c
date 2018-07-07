/*
** my_find_first_digit.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    "../include/my.h"

char        *my_find_first_digit(char *str, char *base)
{
    int          i;

    i = 0;
    while (str[i] != '\0')
    {
        if (my_is_valid_digit(str[i], base))
            return (&str[i]);
        i += 1;
    }
    return (0);
}
