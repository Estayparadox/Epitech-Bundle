/*
** my_putnbr_base.c for my_putnbr_base in /home/pereni_j/Rendu/palindrome/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jun 26 18:32:32 2015 joseph pereniguez
** Last update Sat Jun 27 08:26:51 2015 joseph pereniguez
*/

#include "palindrome.h"

char            *my_putnbr_base(int nbr, char *base)
{
  int           res;
  int           div;
  int           size;
  int           i;
  char          *str;

  i = 0;
  str = malloc(sizeof(char) * 4096);
  size = my_strlen(base);
  div = 1;
  while ((nbr / div) >= size)
    div = div * size;
  while (div > 0)
    {
      res = (nbr / div) % size;
      str[i] = base[res];
      i++;
      div = div / size;
    }
  return (str);
}
