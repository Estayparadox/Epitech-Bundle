/*
** my_puts.c for my_puts in /home/pereni_j/Colle4
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu May 21 18:15:40 2015 joseph pereniguez
** Last update Thu May 21 21:59:21 2015 joseph pereniguez
*/

#include "mastermind.h"

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

void		my_put_nbr(int nbr)
{
  int		div;

  div = 1;
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * -1;
    }
  if (nbr < 10)
    my_putchar(nbr / div + 48);
  else if (nbr >= 10)
    {
      while (div < nbr)
	div = div * 10;
      if (div > nbr)
	div = div / 10;
      while (div >= 1)
	{
	  my_putchar(nbr / div % 10 + 48);
	  div = div / 10;
	}
    }
}

int		my_get_nbr(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (str[0] == '-')
    i = i + 1;
  while (str[i])
    {
      str[i] = str[i] - 48;
      j = j + str[i];
      if (str[i + 1] != '\0')
	j = j * 10;
      if (str[0] == '-' && str[i + 1] == '\0')
	j = j * -1;
      i++;
    }
  return (j);
}
