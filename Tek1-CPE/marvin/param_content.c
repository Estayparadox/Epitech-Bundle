/*
** param_content.c for param_content in /home/pereni_j/rendu/marvin
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sun Jan  4 17:56:05 2015 Pereniguez Joseph
** Last update Sun Jan  4 23:14:52 2015 georges valentin
*/

#include "my.h"

int	param_content(char *str)
{
  int	a;
  int	b;
  int	i;

  i = 0;
  while (str[i])
    {
      while (str[i] != '(')
	{
	  i = i + 1;
	}
      a = i + 1;
      while (str[i] != ')')
	{
	  i = i + 1;
	}
      b = i;
      i = i + 1;
    }
  while (a != b)
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}
