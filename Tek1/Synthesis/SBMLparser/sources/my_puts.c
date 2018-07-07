/*
** my_puts.c for my_puts in /home/pereni_j/Rendu/SBMLparser/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Mon Jun 15 10:08:42 2015 joseph pereniguez
** Last update Mon Jun 15 13:19:20 2015 joseph pereniguez
*/

#include "sbmlparser.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int     my_strcmp(char *s1, char *s2)
{
  int   i;

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
