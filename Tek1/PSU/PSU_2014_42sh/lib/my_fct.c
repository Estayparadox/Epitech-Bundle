/*
** my_fct.c for my_printf in /home/arrazo_p/PSU_2014_my_printf
** 
** Made by pedroantonio arrazolaleon
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sat Nov 15 17:46:52 2014 pedroantonio arrazolaleon
** Last update Fri Jan 23 15:26:37 2015 pedroantonio arrazolaleon
*/

#include <stdarg.h>
#include "my_printf.h"

void	my_char(va_list list)
{
  char	c;

  c = (char)va_arg(list, int);
  my_putchar_print(c);
}

void	my_str(va_list list)
{
  char	*str;

  str = va_arg(list, char*);
  my_putstr_print(str);
}

void	my_nbr(va_list list)
{
  int	nb;

  nb = va_arg(list, int);
  my_put_nbr_print(nb);
}

void	my_ptr(va_list list)
{
  int	ptr;

  ptr = va_arg(list, int);
  if (ptr < 0)
    my_putstr_print("NULL");
  else
    {
      if (ptr < 16777215)
	my_putstr_print("0x");
      else if (ptr < 26843545)
	my_putchar_print(0);
      my_putnbr_base(ptr, "0123456789abcdef");
    }
}

void	my_binary(va_list list)
{
  int	nb;

  nb = va_arg(list, int);
  my_putnbr_base(nb, "01");
}
