/*
** my_strcat.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

char		*my_strcat(char *dest, const char *src)
{
  int		i;
  int		len;

  i = 0;
  len = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[i + len] = src[i];
      i += 1;
    }
  dest[i + len] = '\0';
  return (dest);
}
