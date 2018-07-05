/*
** fonctions_printf.c for fonctions_printf in /home/pereni_j/rendu/PSU_2014_my_printf
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Nov 14 11:41:44 2014 Pereniguez Joseph
** Last update Sun Nov 16 18:10:26 2014 Pereniguez Joseph
*/

#include <stdarg.h>
#include "my.h"

int	fonction_d(va_list liste)
{
  int	nombre;

  nombre = va_arg(liste, int);
  my_put_nbr(nombre);
}

int	fonction_o(va_list liste)
{
  unsigned int	nombre;
  char	*octal;

  nombre = va_arg(liste, unsigned int);
  octal = "01234567";
  my_putnbr_base(nombre, octal);
}

int	fonction_u(va_list liste)
{
  unsigned int	nombre;
  char	*base;

  nombre = va_arg(liste, unsigned int);
  my_put_nbr(nombre);
}

int	fonction_x(va_list liste)
{
  unsigned int	nombre;
  int	NOMBRE;
  char	*hexa;

  NOMBRE = va_arg(liste, int);
  hexa = "0123456789abcdef";
  if (NOMBRE < 0)
    {
      my_putstr("ffffffff");
      return (0);
    }
  nombre = NOMBRE;
  my_putnbr_base(nombre, hexa);
}

int	fonction_X(va_list liste)
{
  int	nombre;
  unsigned int	NOMBRE;
  char	*HEXA;

  nombre = va_arg(liste, int);
  NOMBRE = va_arg(liste, unsigned int);
  HEXA = "0123456789ABCDEF";
  if (nombre < 0)
    {
      my_putstr("FFFFFFFF");
      return (0);
    }
  NOMBRE = nombre;
  my_putnbr_base(NOMBRE, HEXA);
}
