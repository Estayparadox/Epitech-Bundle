/*
** move.c for move in /home/pereni_j/Rendu/BocalEmblem/II : Path of Radiance
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Sun May 17 16:23:01 2015 joseph pereniguez
** Last update Sun May 17 20:18:49 2015 Jade Kadri
*/

#include "playradiance.h"

void		move_down(char **tab, t_map map, int nbr_elem)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < nbr_elem)
    {
      if (map.elem[i] == my_getnbr(tab[0]))
	{
	  while (j < nbr_elem)
	    {
	      if ((map.y[j] == map.y[i] + 1) && (map.x[j] == map.x[i]))
		{
		  if (map.elem[j] == 1 || (map.elem[j] >= 11 && map.elem[j] <= 70))
		    i = error_check(i, nbr_elem);
		  else
		    map.elem[j] = map.elem[i];
		}
	      j++;
	    }
	  map.elem[i] = 0;
	  i = nbr_elem;
	}
      i++;
    }
}

void		move_up(char **tab, t_map map, int nbr_elem)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < nbr_elem)
    {
      if (map.elem[i] == my_getnbr(tab[0]))
	{
	  while (j < nbr_elem)
	    {
	      if ((map.y[j] == map.y[i] - 1) && (map.x[j] == map.x[i]))
		{
		  if (map.elem[j] == 1 || (map.elem[j] >= 11 && map.elem[j] <= 70))
		    i = error_check(i, nbr_elem);
		  else
		    map.elem[j] = map.elem[i];
		}
	      j++;
	    }
	  map.elem[i] = 0;
	  i = nbr_elem;
	}
      i++;
    }
}

void		move_right(char **tab, t_map map, int nbr_elem)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < nbr_elem)
    {
      if (map.elem[i] == my_getnbr(tab[0]))
	{
	  while (j < nbr_elem)
	    {
	      if ((map.y[j] == map.y[i]) && (map.x[j] == map.x[i] + 1))
		{
		  if (map.elem[j] == 1 || (map.elem[j] >= 11 && map.elem[j] <= 70))
		    i = error_check(i, nbr_elem);
		  else
		    map.elem[j] = map.elem[i];
		}
	      j++;
	    }
	  map.elem[i] = 0;
	  i = nbr_elem;
	}
      i++;
    }
}

void		move_left(char **tab, t_map map, int nbr_elem)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < nbr_elem)
    {
      if (map.elem[i] == my_getnbr(tab[0]))
	{
	  while (j < nbr_elem)
	    {
	      if ((map.y[j] == map.y[i]) && (map.x[j] == map.x[i] - 1))
		{
		  if (map.elem[j] == 1 || (map.elem[j] >= 11 && map.elem[j] <= 70))
		    i = error_check(i, nbr_elem);
		  else
		    map.elem[j] = map.elem[i];
		}
	      j++;
	    }
	  map.elem[i] = 0;
	  i = nbr_elem;
	}
      i++;
    }
}

int		error_check(int i, int nbr_elem)
{
  my_putstr("There is an error on your command.\n");
  i = nbr_elem;
  return (i);
}
