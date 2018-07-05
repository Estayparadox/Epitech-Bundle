/*
** var_name.c for var_name in /home/pereni_j/rendu/marvin
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Jan  3 14:46:11 2015 Pereniguez Joseph
** Last update Sun Jan  4 14:00:09 2015 georges valentin
*/

#include <unistd.h>
#include "my.h"

void	var_name(char *str)
{
  int i;
  int b;
  int t;
  int j;

  i = 0;
  b = 0;
  while (str)
    {
      if(str[i] == ' ')
	{
	  b = i + 1;
	}
    }
  my_putstr("nomme ");
  while(str[b + 1] =! '\0')
    {
      my_putchar(str[b]);
      b++;
    }
  my_putstr(".\n'");
}
