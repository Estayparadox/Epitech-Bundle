/*
** my_str_to_wordtab.c for Str_to_wordtab in /home/kadri_j/rush3/BocalEmblem/I : The Sacred Stones
** 
** Made by Jade Kadri
** Login   <kadri_j@epitech.net>
** 
** Started on  Sat May 16 15:37:11 2015 Jade Kadri
** Last update Sun May 17 13:47:32 2015 joseph pereniguez
*/

#include "playradiance.h"

int		number_of_space(char *str, char c)
{
  int           index;
  int           count;

  index = 0;
  count = 1;
  while (str[index])
    {
      if (str[index] == c && str[index + 1] && str[index + 1] != c)
        count++;
      index++;
    }
  return (count + 1);
}

char		**my_str_to_wordtab(char *str, char c)
{
  int		i;
  char		**tab;
  int		cursor;
  int		nb;
  int		count;

  tab = xmalloc(sizeof(char *) * number_of_space(str, c));
  i = 0;
  count = 0;
  while (str[i])
    {
      cursor = 0;
      nb = i;
      while (str[nb] && str[nb] != c)
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
