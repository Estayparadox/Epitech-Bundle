/*
** puts.c for puts in /home/pereni_j/Rendu/BocalEmblem/Path of Radiance
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat May 16 11:43:06 2015 joseph pereniguez
** Last update Sun May 17 11:35:16 2015 joseph pereniguez
*/

#include "playradiance.h"

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
      i = i + 1;
    }
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && s2[i])
    i++;
  if (!s1[i] && !s2[i])
    return (0);
  return (1);
}

int             my_put_nbr(int n)
{
  int           div;

  if (n < 0)
    {
      n = n * -1;
      my_putchar('-');
    }
  div = 1;
  while (n / div >= 10)
    div = div * 10;
  my_putchar(n / div + 48);
  while (div != 1)
    {
      n = n - n / div * div;
      div = div / 10;
      my_putchar(n / div + 48);
    }
  return (0);
}
