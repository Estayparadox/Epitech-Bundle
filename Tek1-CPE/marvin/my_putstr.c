/*
** my_putstr.c for my_putstr in /home/valent_g/travail/pis4/tests
** 
** Made by georges valentin
** Login   <valent_g@epitech.net>
** 
** Started on  Thu Oct  2 17:32:41 2014 georges valentin
** Last update Sun Jan  4 23:39:11 2015 georges valentin
*/

#include "my.h"

void	my_putstr(char *str)
{
  int	i;
  
  i = 0;
  while(str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
