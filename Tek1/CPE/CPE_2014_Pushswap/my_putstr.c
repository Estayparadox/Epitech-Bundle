/*
** my_putstr.c for my_putstr in /home/pereni_j/rendu/Piscine_C_J04
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Oct  2 16:28:10 2014 joseph pereniguez
** Last update Sun Dec 14 20:29:59 2014 Pereniguez Joseph
*/

#include <stdlib.h>
#include <stdio.h>
#include "pushswap.h"

int	my_putstr(char *str)
{
  char	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
