/*
** my_strcmp.c for my_strcmp in /home/pereni_j/rendu/Piscine_C_J06/ex_05
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Oct  7 10:28:11 2014 joseph pereniguez
** Last update Fri Jan 30 15:44:47 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include "minishell.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] < s1[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      i = i + 1;
    }
  if (s1[i] < s2[i])
    return (-1);
  else if (s1[i] > s2[i])
    return (1);
  return (0);
}
