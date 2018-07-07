/*
** my_strncpy.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

char		*my_strncpy(char *dest, const char *src, int n)
{
  int		i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i += 1;
    }
  while (i < n)
    {
      dest[i] = 0;
      i += 1;
    }
  return (dest);
}
