/*
** commands.c for commands in /home/pereni_j/Rendu/BocalEmblem/Path of Radiance
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat May 16 11:56:46 2015 joseph pereniguez
** Last update Sun May 17 21:11:26 2015 Jade Kadri
*/

#include "playradiance.h"

int             count_elem(char *str)
{
  int           i;
  int           j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if ((str[i] >= '0' && str[i] <= '9') &&
          (str[i + 1] == ' ' || str[i + 1] == '\n'))
        j++;
      i++;
    }
  return (j);
}

void		my_strategic(char *buffer, t_map map, int nbr_elem, t_val val)
{
  if (my_strcmp("strategic", buffer) == 0)
    try_aff(map, nbr_elem, val);
  else
    my_pass(buffer, map, nbr_elem);
}

void		my_pass(char *buffer, t_map map, int nbr_elem)
{
  if (my_strcmp("pass", buffer) == 0)
    {
    }
  else
    my_unit(buffer, map, nbr_elem);
}

int		my_count_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i = i + 1;
  if (i != 4)
    return (-1);
  return (0);
}

void		my_unit(char *buffer, t_map map, int nbr_elem)
{
  char		**tab;

  map = map;
  nbr_elem = nbr_elem;
  tab = my_str_to_wordtab(buffer, ' ');
  if (my_count_tab(tab) == -1)
    my_rule_radiance();
  else
    if (my_strcmp("move", tab[1]) == 0 &&
	my_strcmp("to", tab[2]) == 0)
      {
	if (my_strcmp("bottom", tab[3]) == 0)
	  move_down(tab, map, nbr_elem);
	else if (my_strcmp("top", tab[3]) == 0)
	  move_up(tab, map, nbr_elem);
	else if (my_strcmp("right", tab[3]) == 0)
	  move_right(tab, map, nbr_elem);
	else if (my_strcmp("left", tab[3]) == 0)
	  move_left(tab, map, nbr_elem);
	else
	  my_rule_radiance();
      }
    else
      my_rule_radiance();
}
