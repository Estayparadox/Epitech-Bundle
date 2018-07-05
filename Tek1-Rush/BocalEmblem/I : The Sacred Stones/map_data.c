/*
** map_data.c for map_data.c in /home/kadri_j/BocalEmblem/The Sacred Stones
** 
** Made by Jade Kadri
** Login   <kadri_j@epitech.net>
** 
** Started on  Sat May 16 11:56:52 2015 Jade Kadri
** Last update Sun May 17 16:48:40 2015 Jade Kadri
*/

#include "strategic.h"

void            verify_extension(char *file)
{
  int           len;

  len = my_strlen(file);
  if (file[len - 1] != 'p' && file[len - 2] != 'a' &&
      file[len - 3] != 'm' && file[len - 4] != '.')
    my_puterror("File isn't a [.map] file!\n");
  else if (file[len - 1] == 'p' && file[len - 2] == 'a' &&
	   file[len - 3] == 'm' && file[len - 4] == '.')
    my_putstr("Extension is OK.\n");
}

void		verify_size(char *file, char *str)
{
  int		i;
  t_size	size;

  size.cpt = 0;
  size.x = 0;
  size.y = -1;
  i = 0;
  while (str[i])
    {
      if (str[i] == ' ' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	size.cpt++;
      if (str[i] == '\n')
	{
	  size.y++;
	  if (size.cpt >= size.x)
	    size.x = size.cpt;
	  size.cpt = 0;
	}
      i++;
    }
  aff_size(file, size.x, size.y);
}

int		verify_soldiers(char *str)
{
  t_sold	sold;

  sold.y = 0;
  sold.x = 0;
  sold.line = my_str_to_wordtab(str, '\n');
  while (sold.line[sold.y] != NULL)
    {
      sold.elem = my_str_to_wordtab(sold.line[sold.y], ' ');
      while (sold.elem[sold.x] != NULL)
	{
	  if (verify_elem(sold.line, str) == -1 ||
	      my_getnbr(sold.elem[sold.x]) > 70)
	    return (-1);
	  if (my_getnbr(sold.elem[sold.x]) >= 11 &&
	      my_getnbr(sold.elem[sold.x]) <= 40)
	    aff_blue_sold(my_getnbr(sold.elem[sold.x]), sold.x, sold.y);
	  if (my_getnbr(sold.elem[sold.x]) >= 41 &&
	      my_getnbr(sold.elem[sold.x]) <= 70)
	    aff_red_sold(my_getnbr(sold.elem[sold.x]), sold.x, sold.y);
	  sold.x++;
	}
      sold.x = 0;
      sold.y++;
    }
  return (0);
}

int		verify_double(char *str)
{
  char		**tab;
  int		i;
  int		k;

  tab = my_str_to_wordtab_2(str, ' ', '\n');
  i = 0;
  k = 0;
  while (tab[i])
    {
      if (my_getnbr(tab[i]) >= 11 && my_getnbr(tab[i]) <= 70)
	{
	  k = i + 1;
	  while (tab[k])
	    {
	      if (my_getnbr(tab[i]) == my_getnbr(tab[k]))
		return (-1);
	      k++;
	    }
	}
      k = 0;
      i++;
    }
  return (0);
}

int		verify_elem(char **line, char *str)
{
  char		**first;
  char		**last;
  char		**elem;
  int		i;

  i = 0;
  first = my_str_to_wordtab(line[0], ' ');
  last = my_str_to_wordtab(line[cpt_y(line) - 1], ' ');
  while (first[i] && last[i])
    {
      if ((my_getnbr(first[i]) > 1 || my_getnbr(first[i]) < 1) ||
	  (my_getnbr(last[i]) > 1 || my_getnbr(last[i]) < 1))
	return (-1);
      i++;
    }
  i = 0;
  while (line[i])
    {
      elem = my_str_to_wordtab(line[i], ' ');
      if ((my_getnbr(elem[0]) > 1 || my_getnbr(elem[0]) < 1) ||
	  (my_getnbr(elem[cpt_x(str)]) > 1 || my_getnbr(elem[cpt_x(str)]) < 1))
	return (-1);
      i++;
    }
  return (0);
}
