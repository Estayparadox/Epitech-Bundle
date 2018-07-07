/*
** my_getnbr_base.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include        "../include/my.h"

int		        my_getnbr_base(char *str, char *base)
{
    char        *start;
    int		    result;
    int		    len;
    int		    i;

    if (str[0] == '\0' || base[0] == '\0')
        return (0);
    start = my_find_first_digit(str, base);
    result = my_get_digit_weight(*start, base);
    start += 1;
    len = my_strlen(base);
    i = 0;
    while (start[i] != '\0' && my_is_valid_digit(start[i], base))
    {
        result = result * len + my_get_digit_weight(start[i], base);
        i += 1;
    }
    if (str[0] == '-')
        result = -result;
    return (result);
}
