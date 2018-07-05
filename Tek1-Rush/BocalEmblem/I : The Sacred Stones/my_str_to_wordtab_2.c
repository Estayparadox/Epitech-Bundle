/*
** my_str_to_wordtab_2.c for double in /home/kadri_j/rush3/lol/BocalEmblem/I : The Sacred Stones
** 
** Made by Jade Kadri
** Login   <kadri_j@epitech.net>
** 
** Started on  Sat May 16 19:28:21 2015 Jade Kadri
** Last update Sat May 16 19:45:02 2015 Jade Kadri
*/

#include "strategic.h"

int		number_of_space_2(char *str, char c1, char c2)
{
  int           index;
  int           count;

  index = 0;
  count = 1;
  index = 0;
  count = 1;
  while (str[index])
    {
      if ((str[index] == c1 && str[index + 1] && str[index + 1] != c1) ||
	  (str[index] == c2 && str[index + 1] && str[index + 1] != c2) ||
	  (str[index] == c1 && str[index + 1] && str[index + 1] != c2) ||
	  (str[index] == c2 && str[index + 1] && str[index + 1] != c1))
        count++;
      index++;
    }
  return (count + 1);
}

char		**my_str_to_wordtab_2(char *str, char c1, char c2)
{
  int		i;
  char		**tab;
  int		cursor;
  int		nb;
  int		count;

  tab = xmalloc(sizeof(char *) * number_of_space_2(str, c1, c2));
  i = 0;
  count = 0;
  while (str[i])
    {
      cursor = 0;
      nb = i;
      while (str[nb] && str[nb] != c1 && str[nb] != c2)
        nb++;
      tab[count] = xmalloc(sizeof(char) * (nb - i + 1));
      while (i != nb)
        tab[count][cursor++] = str[i++];
      tab[count][cursor] = 0;
      tab[count + 1] = NULL;
      count++;
      i++;
    }
  return (tab);
}
