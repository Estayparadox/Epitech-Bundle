/*
** my_fct3.c for my_printf in /home/arrazo_p/PSU_2014_my_printf/b
** 
** Made by pedroantonio arrazolaleon
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sun Nov 16 17:26:18 2014 pedroantonio arrazolaleon
** Last update Fri Jan 23 15:49:24 2015 pedroantonio arrazolaleon
*/

#include "my_printf.h"

void	my_unbr(va_list list)
{
  unsigned int	nb;

  nb = va_arg(list, unsigned int);
  my_put_nbr(nb);
}

void	my_super_str(va_list list)
{
  char	*str;
  int	i;

  str = va_arg(list, char *);
  i = 0;
  while (str[i])
    {
      if (str[i] < 7)
        {
          my_putstr_print("\\0");
          my_putnbr_base(str[i], "01234567");
        }
      else if (str[i] < 32 || str[i] >= 127)
        {
          my_putstr_print("\\");
          my_putnbr_base(str[i], "0123467");
        }
      else
        my_putchar_print(str[i]);
      i = i + 1;
    }
}
