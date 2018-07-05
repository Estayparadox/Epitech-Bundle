/*
** lib.c for  lib in /home/kadri_j/rush3/BocalEmblem/I : The Sacred Stones
** 
** Made by Jade Kadri
** Login   <kadri_j@epitech.net>
** 
** Started on  Sat May 16 15:25:40 2015 Jade Kadri
** Last update Sat May 16 15:42:42 2015 Jade Kadri
*/

#include "strategic.h"

void		my_putchar(char c)
{
  write (1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int		my_getnbr(char *str)
{
  int		nbr;
  int		s;
  int		i;

  nbr = 0;
  i = 0;
  s = 1;
  while (str[i] != '\0')
    {
      if (str[i] == '-')
        s = s * -1;
      if (str[i] >= '0' && str[i] <= '9')
        {
          nbr = nbr * 10 + str[i] - '0';
          if (str[i + 1] < '0' || str[i + 1] > '9')
            return (nbr * s);
        }
      if (nbr < 0)
        return (0);
      i = i + 1;
    }
  return (nbr + s);
}

int		my_put_nbr(int n)
{
  int		div;

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
