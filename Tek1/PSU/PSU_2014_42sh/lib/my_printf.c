/*
** my_printf.c for my_printf in /home/arrazo_p/PSU_2014_my_printf/b
** 
** Made by pedroantonio arrazolaleon
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sun Nov 16 18:29:45 2014 pedroantonio arrazolaleon
** Last update Fri Jan 23 15:37:57 2015 pedroantonio arrazolaleon
*/

#include "my_printf.h"

int	my_space(const char *format, int index, int nb)
{
  while (format[index] == ' ')
    index = index + 1;
  if (nb == 0)
    return (my_tab(format, index));
  return (index);
}

int	my_tab(const char *format, int index)
{
  if (format[index] == 'c')
    return (0);
  if (format[index] == 's')
    return (1);
  if (format[index] == 'd' || format[index] == 'i')
    return (2);
  if (format[index] == 'p')
    return (3);
  if (format[index] == 'b')
    return (4);
  if (format[index] == 'o')
    return (5);
  if (format[index] == 'S')
    return (7);
  if (format[index] == 'X')
    return (8);
  if (format[index] == '%')
    return (9);
  if (format[index] == 'x')
    return (6);
  if (format[index] == 'u')
    return (10);
  if (format[index] == ' ')
    return (my_space(format, index, 0));
  return (-1);
}

int	my_vaarg(const char *format, int index, va_list list)
{
  void	(*val[11])(va_list);
  int	temp;

  val[0] = &my_char;
  val[1] = &my_str;
  val[2] = &my_nbr;
  val[3] = &my_ptr;
  val[4] = &my_binary;
  val[5] = &my_octal;
  val[6] = &my_hexa;
  val[7] = &my_super_str;
  val[8] = &my_super_hexa;
  val[9] = &my_percent;
  val[10] = &my_unbr;
  temp = my_tab(format, index);
  if (temp == -1)
    return (-1);
  val[temp](list);
  if (format[index] == ' ')
    return (my_space(format, index, 1) - index + 2);
  if (temp == 7)
    return (3);
  return (2);
}

int	my_printf(const char *format, ...)
{
  va_list	list;
  int		index;
  int		val;

  index = 0;
  va_start(list, format);
  while (format[index])
    {
      if (format[index] == '%')
	{
	  if ((val = my_vaarg(format, index + 1, list)) == -1)
	    return (0);
	  index = index + val;
	}
      else
	{
	  my_putchar_print(format[index]);
	  index = index + 1;
	}
    }
  va_end(list);
  return (my_count() - 1);
}
