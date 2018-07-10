/*
** my_putchar_print.c for my_printf in /home/arrazo_p/PSU_2014_my_printf
** 
** Made by pedroantonio arrazolaleon
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sun Nov 16 14:09:57 2014 pedroantonio arrazolaleon
** Last update Fri Jan 23 15:39:25 2015 pedroantonio arrazolaleon
*/

#include "my_printf.h"

void	my_putchar_print(char c)
{
  write(1, &c, 1);
  my_count();
}
