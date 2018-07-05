/*
** str_to_wordtab3.c for str_to_wordtab3 in /home/pereni_j/Rendu/genealogie/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jul  3 10:10:17 2015 joseph pereniguez
** Last update Fri Jul  3 10:17:11 2015 joseph pereniguez
*/

#include "genealogie.h"

int             ret_char3(char c)
{
  if ((c != '\n') && (c != ' ') &&
      (c != '\t'))
    return (0);
  else
    return (-1);
}

int             my_nb_word3(char *str)
{
  int           c;
  int           ret;

  c = 0;
  ret = 1;
  while (str[c])
    {
      if ((str[c] == ' ' || str[c] == '\t' ||
	   str[c] == '\n') && ret_char3(str[c]) == -1)
	ret++;
      while (str[c] == ' ' || str[c] == '\t' ||
	     str[c] == '\n')
	c++;
      c++;
    }
  return (ret);
}

int             my_nb_carac3(char *str)
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

char            **my_str_to_wordtab3(char *str)
{
  char  **tab;
  int   i;
  int   t;
  int   c;

  i = 0;
  t = 0;
  tab = malloc(sizeof(char *) * (my_nb_word3(str) + 1));
  while (str[i] != '\0')
    {
      c = 0;
      tab[t] = malloc(sizeof(char) * (my_nb_carac3(&str[i]) + 1));
      while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' &&
	     str[i] != '\n' && ret_char3(str[i]) == 0)
	tab[t][c++] = str[i++];
      while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
	i++;
      tab[t][c] = '\0';
      if (tab[t][0] != '\0')
        t++;
      c++;
    }
  tab[t] = '\0';
  return (tab);
}
