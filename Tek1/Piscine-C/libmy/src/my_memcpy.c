/*
** my_memcpy.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include            "../include/my.h"

void		        my_memcpy(void *dest, void *src, unsigned int size)
{
    unsigned int	i;
    char		    *p1;
    char		    *p2;

    i = 0;
    p1 = (char *)dest;
    p2 = (char *)src;
    while (i < size)
    {
        p1[i] = p2[i];
        i += 1;
    }
}
