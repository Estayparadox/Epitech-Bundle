/*
** prerequis.c for prerequis in /home/pereni_j/Rendu/SBMLparser
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Mon Jun 15 09:20:38 2015 joseph pereniguez
** Last update Mon Oct  2 00:33:47 2017 pereniguez joseph
*/

#include "sbmlparser.h"

int		ret_char(char c)
{
  if ((c >= 'a' && c <= 'z') ||
      (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9') ||
      (c == '-'))
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
      if (str[c] == ' ' && ret_char(str[c]) == -1)
        {
          ret++;
          c++;
        }
      else
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

char            **my_strtowordtab_synthese(char *str)
{
  char  **tab;
  int   i;
  int   t;
  int   c;

  i = 0;
  t = 0;
  tab = malloc(sizeof(char *) * (my_nb_word(str) + 1));
  while (str[i] != '\0')
    {
      c = 0;
      tab[t] = malloc(sizeof(char) * (my_nb_carac(&str[i]) + 1));
      while ((str[i] != '\0') && (str[i] != ' ') && (ret_char(str[i]) == 0))
	tab[t][c++] = str[i++];
      tab[t][c] = '\0';
      if (tab[t][0] != '\0')
	t++;
      i++;
      c++;
    }
  tab[t] = '\0';
  return (tab);
}
