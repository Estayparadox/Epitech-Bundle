/*
** my_char_to_low.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

char     my_char_to_low(char c)
{
  if (c >= 'A' && c <= 'Z')
    return ('a' + c - 'A');
  else
    return (c);
}
