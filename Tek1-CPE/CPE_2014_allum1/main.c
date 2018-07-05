/*
** main.c for main in /home/pereni_j/rendu/CPE_2014_allum1/new_allum1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Feb 13 18:46:43 2015 Pereniguez Joseph
** Last update Fri Feb 20 10:16:34 2015 Pereniguez Joseph
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "allum.h"

char                    *my_memset(char *str)
{
  int                   i;

  i = -1;
  while (i <= 4096)
    {
      i = i + 1;
      str[i] = 0;
    }
  return (str);
}

int			main()
{
  char			*buffer;

  buffer = malloc(sizeof(char)* 4096);
  buffer = my_memset(buffer);
  my_putstr("\n\033[32;01m'exit'to quit\033[00m\n");
  my_putchar('\n');
  my_putstr("1>\033[31;05m    |\033[00m\n");
  my_putstr("2>\033[31;05m   |||\033[00m\n");
  my_putstr("3>\033[31;05m  |||||\033[00m\n");
  my_putstr("4>\033[31;05m |||||||\033[00m\n");
  my_putstr("\n");
  my_putstr("X  1234567\n");
  my_putchar('\n');
  while (1)
    {
      buffer = my_memset(buffer);
      my_allum(buffer);
    }
  return (0);
}
