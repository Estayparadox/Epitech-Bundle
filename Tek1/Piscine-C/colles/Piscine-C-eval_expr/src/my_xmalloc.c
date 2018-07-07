/*
** my_xmalloc.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    <stdlib.h>
#include    "../include/my.h"

void		*my_xmalloc(int size)
{
    void	*ptr;

    ptr = malloc(size);
    if (!ptr)
        exit(EXIT_FAILURE);
    return (ptr);
}
