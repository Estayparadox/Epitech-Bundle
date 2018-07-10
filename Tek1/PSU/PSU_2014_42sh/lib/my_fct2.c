/*
** my_fct2.c for my_printf in /home/arrazo_p/PSU_2014_my_printf
** 
** Made by pedroantonio arrazolaleon
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sat Nov 15 21:15:44 2014 pedroantonio arrazolaleon
** Last update Fri Jan 23 15:47:31 2015 pedroantonio arrazolaleon
*/

#include "my_printf.h"

void	my_octal(va_list list)
{
  int	nb;

  nb = va_arg(list, unsigned int);
  my_putnbr_base(nb, "01234567");
}

void	my_hexa(va_list list)
{
  int	nb;

  nb = va_arg(list, int);
  my_putnbr_base(nb, "0123456789abcdef");
}

void	my_super_hexa(va_list list)
{
  int	nb;

  nb = va_arg(list, int);
  my_putnbr_base(nb, "0123456789ABCDEF");
}

void	my_percent()
{
  my_putchar_print('%');
}
