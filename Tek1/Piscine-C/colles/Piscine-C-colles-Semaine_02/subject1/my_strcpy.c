/*
** my_strcpy.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    "my.h"

char		*my_strcpy(char *dest, const char *src)
{
  char		*ptr;

  ptr = dest;
  while (*src != 0)
    *ptr++ = *src++;
  *ptr = 0;
  return (dest);
}
