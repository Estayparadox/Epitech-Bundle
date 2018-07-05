/*
** my_strtowordtab.c for my_strtowordtab in /home/pereni_j/Rendu/projTester/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jun 18 11:47:39 2015 joseph pereniguez
** Last update Thu Jun 18 18:32:57 2015 joseph pereniguez
*/

#include "projtester.h"

int             ret_char(char c)
{
  if ((c != ':') && (c != '\n') &&
      (c != '"'))
    return (0);
  else
    return (-1);
}

int             my_nb_word(char *str)
{
  int           c;
  int           ret;

  c = 0;
  ret = 1;
  while (str[c])
    {
      if ((str[c] == ':' || str[c] == '\n' ||
	   str[c] == '"') && ret_char(str[c]) == -1)
	ret++;
      while (str[c] == ':' || str[c] == '\n' ||
	     str[c] == '"')
	c++;
      c++;
    }
  return (ret);
}

int             my_nb_carac(char *str)
{
  int           c;
  int           ret;

  c = 0;
  ret = 0;
  while (str[c] != '\0')
    {
      ret++;
      c++;
    }
  return (ret);
}

char            **my_strtowordtab(char *str)
{
  char		**tab;
  int		i;
  int		t;
  int		c;

  i = 0;
  t = 0;
  tab = malloc(sizeof(char *) * (my_nb_word(str) + 1));
  while (str[i] != '\0')
    {
      c = 0;
      tab[t] = malloc(sizeof(char) * (my_nb_carac(&str[i]) + 1));
      while (str[i] != '\0' && str[i] != ':' && str[i] != '"' &&
	     str[i] != '\n' && ret_char(str[i]) == 0)
        tab[t][c++] = str[i++];
      while (str[i] == '\n' || str[i] == ':' || str[i] == '"')
	i++;
      tab[t][c] = '\0';
      if (tab[t][0] != '\0')
        t++;
      c++;
    }
  tab[t] = '\0';
  return (tab);
}
