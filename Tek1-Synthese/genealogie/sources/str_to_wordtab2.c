/*
** wordtab_str.c for wordtab_str in /home/pereni_j/Rendu/agenda/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jun 30 10:14:34 2015 joseph pereniguez
** Last update Thu Jul  2 18:22:19 2015 joseph pereniguez
*/

#include "genealogie.h"

int             ret_char2(char c)
{
  if (c != ' ')
    return (0);
  else
    return (-1);
}

int             my_nb_word2(char *str)
{
  int           c;
  int           ret;

  c = 0;
  ret = 1;
  while (str[c])
    {
      if (ret_char2(str[c]) == -1)
        {
          ret++;
          c++;
        }
      else
        c++;
    }
  return (ret);
}

int             my_nb_carac2(char *str)
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

char            **my_str_to_wordtab2(char *str)
{
  char  **tab;
  int   i;
  int   t;
  int   c;

  i = 0;
  t = 0;
  tab = malloc(sizeof(char *) * (my_nb_word2(str) + 1));
  while (str[i] != '\0')
    {
      c = 0;
      tab[t] = malloc(sizeof(char) * (my_nb_carac2(&str[i]) + 1));
      while ((str[i] != '\0') && (ret_char2(str[i]) == 0))
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
