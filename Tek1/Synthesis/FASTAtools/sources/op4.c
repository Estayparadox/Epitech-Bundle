/*
** op4.c for op4 in /home/pereni_j/Rendu/FASTAtools/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jun 25 09:10:28 2015 joseph pereniguez
** Last update Thu Jun 25 11:10:06 2015 joseph pereniguez
*/

#include "fastatools.h"

char		*maj_tab(char *str)
{
  int		i;
  int		j;
  char		*copy;

  i = 0;
  j = 0;
  copy = malloc(sizeof(char) * (my_strlen(str)));
  while (str[i])
    {
      if (str[i] == 'a' || str[i] == 'c' || str[i] == 'g' || str[i] == 't')
	copy[j++] = str[i] - 32;
      if (str[i] == 'A' || str[i] == 'C' || str[i] == 'G' || str[i] == 'T')
	copy[j++] = str[i];
      i++;
    }
  return (copy);
}

void		option2_4(char **tab, char *km)
{
  tab = tab;
  km = km;
  return;
}

void		option_4(char *file, char *km)
{
  int		i;
  char		**tab;

  i = 0;
  tab = my_strtowordtab(file);
  while (tab[i])
    {
      if (tab[i][0] != '>')
	tab[i] = maj_tab(tab[i]);
      i++;
    }
  option2_4(tab, km);
}
