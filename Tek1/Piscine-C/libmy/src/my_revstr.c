/*
** my_revstr.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

char		*my_revstr(char *str)
{
  int		len;
  int		i;

  i  = 0;
  len = my_strlen(str);
  while (i < len / 2)
    {
      my_revstr_swap(&str[i], &str[len - 1 - i]);
      i += 1;
    }
  str[len] = '\0';
  return (str);
}
