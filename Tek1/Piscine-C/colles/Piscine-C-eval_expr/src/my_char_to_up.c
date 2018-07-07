/*
** my_char_to_up.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

char     my_char_to_up(char c)
{
  if (c >= 'a' && c <= 'z')
    return ('A' + c - 'a');
  else
    return (c);
}
