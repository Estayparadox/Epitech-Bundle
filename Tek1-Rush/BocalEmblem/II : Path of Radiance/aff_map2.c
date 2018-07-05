/*
** aff_map2.c for aff_map2.c in /home/pereni_j/Rendu/BocalEmblem/II : Path of Radiance
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Sun May 17 16:06:32 2015 joseph pereniguez
** Last update Sun May 17 21:16:44 2015 Jade Kadri
*/

#include "playradiance.h"

int		count_y(t_map map, int nbr_elem)
{
  int		i;

  i = 0;
  while (i < nbr_elem)
    i = i + 1;
  return (map.y[i - 1]);
}

void		aff_name(char *str)
{
  int		i;

  i = 0;
  while (i < my_strlen(str) - 4)
    my_putchar(str[i++]);
}

void		aff_size(t_val val, int y)
{
  my_putstr("The ");
  aff_name(val.name);
  my_putstr(" is ");
  my_put_nbr(val.x);
  my_putstr(" on ");
  my_put_nbr(y);
  my_putchar('.');
  my_putchar('\n');
}
