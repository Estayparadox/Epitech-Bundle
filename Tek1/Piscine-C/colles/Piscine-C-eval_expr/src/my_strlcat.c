/*
** my_strlcat.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    "../include/my.h"

int		    my_strlcat(char *dest, char *src, int size)
{
    int		i;
    int		remain;
    char	*ptr;
    int		dest_len;
    int		src_len;

    i = 0;
    dest_len = my_strlen(dest);
    src_len = my_strlen(src);
    remain = size - dest_len - 1;
    ptr = dest + dest_len;
    while (i < remain)
    {
        ptr[i] = src[i];
        i += 1;
    }
    ptr[i] = '\0';
    return (dest_len + src_len);
}
