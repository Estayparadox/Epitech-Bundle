/*
** my_showstr.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

int         my_showstr(char const *str)
{
  int		i;
  char		*base;
  char		test[2];

  test[1] = '\0';
  base = "0123456789abcdef";
  i = 0;
  while (str[i] != '\0')
  {
    test[0] = str[i];
    if (!my_str_isprintable(test))
  {
    my_putchar('\\');
    if (str[i] < 16)
       my_putchar('0');
    my_putnbr_base(str[i], base);
  }
  else
    my_putchar(str[i]);
    i += 1;
  }
  return (1);
}
