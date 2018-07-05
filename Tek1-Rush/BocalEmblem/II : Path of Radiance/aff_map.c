/*
** aff_map.c for aff_map in /home/pereni_j/Rendu/BocalEmblem/II : Path of Radiance
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Sun May 17 14:54:04 2015 joseph pereniguez
** Last update Sun May 17 21:13:14 2015 Jade Kadri
*/

#include "playradiance.h"

int             count_x(char *str)
{
  char          **tab;
  char          **tab2;
  int           i;

  i = 0;
  tab = my_str_to_wordtab(str, '\n');
  tab2 = my_str_to_wordtab(tab[0], ' ');
  while (tab2[i])
    {
      free(tab2[i]);
      i++;
    }
  free(tab[0]);
  return (i);
}

void            try_aff(t_map map, int nbr_elem, t_val val)
{
  int           i;

  i = 0;
  aff_size(val, count_y(map, nbr_elem));
  while (i < nbr_elem)
    {
      if (map.elem[i] >= 11 && map.elem[i] <= 40)
        aff_blue_sold(map.elem[i], map.x[i], map.y[i]);
      if (map.elem[i] >= 41 && map.elem[i] <= 70)
        aff_red_sold(map.elem[i], map.x[i], map.y[i]);
      i++;
    }
}

void            aff_blue_sold(int sold, int x, int y)
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

t_map           map_in_tab(char *str)
{
  t_map         map;
  t_value       value;

  value.i = 0;
  value.x = 0;
  value.y = 0;
  value.tab = my_str_to_wordtab_2(str, ' ', '\n');
  map.elem = malloc(sizeof(int) * count_elem(str));
  map.x = malloc(sizeof(int) * count_elem(str));
  map.y = malloc(sizeof(int) * count_elem(str));
  while (value.tab[value.i])
    {
      map.elem[value.i] = my_getnbr(value.tab[value.i]);
      free(value.tab[value.i]);
      map.x[value.i] = value.x;
      map.y[value.i] = value.y;
      if (value.x == count_x(str) - 1)
        {
          value.x = -1;
          value.y = value.y + 1;
        }
      value.x++;
      value.i++;
    }
  return (map);
}
