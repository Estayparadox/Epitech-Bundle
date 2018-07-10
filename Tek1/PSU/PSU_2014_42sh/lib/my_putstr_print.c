/*
** my_putstr_print.c for my_printf in /home/arrazo_p/PSU_2014_my_printf
** 
** Made by pedroantonio arrazolaleon
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sun Nov 16 14:11:48 2014 pedroantonio arrazolaleon
** Last update Fri Jan 23 15:43:15 2015 pedroantonio arrazolaleon
*/

#include "my_printf.h"

void    my_putstr_print(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_putchar_print(str[i]);
      i = i + 1;
    }
}
