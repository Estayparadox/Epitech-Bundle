/*
** my_strncat.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

char        *my_strncat(char *dest , char const *src , int nb)
{
  int		i;
  char		*ptr;

  i = 0;
  ptr = dest + my_strlen(dest);
  while (i < nb && src[i] != '\0')
    {
      ptr[i] = src[i];
      i += 1;
    }
  ptr[i] = '\0';
  return (dest);
}
