/*
 ** my_count_nbr_digits.c for libmy in /home/pereni_j/libmy/src
 **
 ** Made by joseph pereniguez
 ** Login   <pereni_j@epitech.net>
 **
 ** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
 ** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
 */

#include "../include/my.h"

int         my_count_nbr_digits(int n, int base)
{
  int       count;

  if (n == 0)
    return (1);
  count = 0;
  while (n != 0)
    {
      n = n / base;
      count += 1;
    }
  return (count);
}
