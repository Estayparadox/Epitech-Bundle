/*
** fonctions_printf2.c for fonctions_printf2 in /home/pereni_j/rendu/PSU_2014_my_printf
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Nov 14 13:13:27 2014 Pereniguez Joseph
** Last update Sun Nov 16 17:48:10 2014 Pereniguez Joseph
*/

#include <stdarg.h>
#include "my.h"

int	fonction_c(va_list liste)
{
  int	c;

  c = va_arg(liste, int);
  my_putchar(c);
}

int	fonction_s(va_list liste)
{
  char	*format;

  format = va_arg(liste, char *);
  my_putstr(format);
}

int	fonction_p(va_list liste)
{
  int	format;

  format = va_arg(liste, int);
  my_putstr("0x");
  my_putnbr_base(format, "0123456789abcdef");
}

int	fonction_b(va_list liste)
{
  unsigned int	nombre;
  char	*bin;

  nombre = va_arg(liste, unsigned int);
  bin = "01";
  my_putnbr_base(nombre, bin);
}

int	fonction_S(va_list liste)
{
  char	*format;
  char	*octal;
  int	i;

  format = va_arg(liste, char *);
  i = 0;
  octal = "01234567";
  while (format[i])
    {
      if (format[i] < 7)
        {
          my_putstr("\\00");
          my_putnbr_base(format[i], octal);
        }
      else if ((format[i] > 7 && format[i] < 32) || format[i] >= 127)
        {
          my_putstr("\\0");
          my_putnbr_base(format[i], octal);
        }
      else
        my_putchar(format[i]);
      i = i + 1;
    }
}
