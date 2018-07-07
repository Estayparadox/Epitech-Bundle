/*
** my_strdub.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    <stdlib.h>
#include    "../include/my.h"

char		*my_strdup(char *str)
{
    int		size;
    char    *new_str;

    size = my_strlen(str) + 1;
    new_str = my_xmalloc(size);
    if (new_str == 0)
        return (0);
    my_strcpy(new_str, str);
    return (new_str);
}
