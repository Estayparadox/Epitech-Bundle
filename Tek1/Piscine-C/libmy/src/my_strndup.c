/*
** my_strndup.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    "../include/my.h"

char		*my_strndup(char *src, int n)
{
    char	*dest;
    int		i;

    dest = my_xmalloc(my_strlen(src) + 1);
    i = 0;
    while (src[i] != 0 && i < n)
    {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = 0;
    return (dest);
}
