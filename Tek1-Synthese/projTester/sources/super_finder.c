/*
** super_finder.c for super_finder in /home/pereni_j/Rendu/projTester/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jun 19 10:04:40 2015 joseph pereniguez
** Last update Fri Jun 19 11:23:22 2015 joseph pereniguez
*/

#include "projtester.h"

int		option_e(char **tab, char **argv, int i)
{
  char		*str;

  str = " ";
  if (tab[i + 1] && (my_strcmp(tab[i + 1], "ARGS")) != 0)
    my_readerer(argv[1], str_cat(tab[i], str));
  if ((tab[i + 1] && (my_strcmp(tab[i + 1], "ARGS")) == 0) ||
      !tab[i + 1])
    {
      my_readerer(argv[1], tab[i]);
      printf("\n");
    }
  if ((my_strcmp(tab[i], "ARGS")) == 0 && i != 0)
    printf("\n");
  if (!tab[i + 1])
    return (0);
  return (1);
}

int		no_option(char **tab, char **argv, int i)
{
  char		*str;

  str = " ";
  if (tab[i + 1] && (my_strcmp(tab[i + 1], "ARGS")) != 0)
    my_reader(argv[1], str_cat(tab[i], str));
  if ((tab[i + 1] && (my_strcmp(tab[i + 1], "ARGS")) == 0) ||
      !tab[i + 1])
    {
      my_reader(argv[1], tab[i]);
      printf("\n");
    }
  if ((my_strcmp(tab[i], "ARGS")) == 0 && i != 0)
    printf("\n");
  if (!tab[i + 1])
    return (0);
  return (1);
}
