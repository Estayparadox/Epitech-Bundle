/*
** aff_elem.c for elem in /home/kadri_j/BocalEmblem/The Sacred Stones
** 
** Made by Jade Kadri
** Login   <kadri_j@epitech.net>
** 
** Started on  Sat May 16 12:57:04 2015 Jade Kadri
** Last update Sun May 17 16:49:09 2015 Jade Kadri
*/

#include "strategic.h"

void		aff_name_file(char *str)
{
  int		i;

  i = 0;
  while (i < ((my_strlen(str) - 4)))
    {
      my_putchar(str[i]);
      i++;
    }
}

void            aff_size(char *file, int x, int y)
{
  my_putstr("The ");
  aff_name_file(file);
  my_putstr(" is ");
  my_put_nbr(x);
  my_putstr(" on ");
  my_put_nbr(y);
  my_putchar('.');
  my_putchar('\n');
}

void		aff_blue_sold(int sold, int x, int y)
{
  my_putstr("The blue unit ");
  my_put_nbr(sold);
  my_putstr(" is in ");
  my_put_nbr(x);
  my_putstr("/");
  my_put_nbr(y);
  my_putchar('.');
  my_putchar('\n');
}

void		aff_red_sold(int sold, int x, int y)
{
  my_putstr("The red unit ");
  my_put_nbr(sold);
  my_putstr(" is in ");
  my_put_nbr(x);
  my_putstr("/");
  my_put_nbr(y);
  my_putchar('.');
  my_putchar('\n');
}
