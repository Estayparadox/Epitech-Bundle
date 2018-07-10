/*
** my_putchar.c for my_putchar.c in /home/arrazo_p/PSU_2014_my_printf/b
** 
** Made by pedroantonio arrazolaleon
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sun Nov 16 18:13:48 2014 pedroantonio arrazolaleon
** Last update Fri Jan 23 15:50:08 2015 pedroantonio arrazolaleon
*/

#include "my_printf.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
