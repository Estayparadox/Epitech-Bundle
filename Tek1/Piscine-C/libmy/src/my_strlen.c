/*
** my_strlen.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

int		    my_strlen(const char *str)
{
  int		length;

  length = 0;
  while ((str != 0) && (str[length] != '\0'))
    {
      length = length + 1;
    }
  return (length);
}
