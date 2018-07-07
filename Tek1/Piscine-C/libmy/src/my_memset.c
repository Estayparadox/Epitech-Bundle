/*
** my_memset.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    "../include/my.h"

void        *my_memset(void *ptr, int value, int size)
{
    char	*current;

    current = ptr;
    while (size-- > 0)
        *current++ = value;
    return (ptr);
}
