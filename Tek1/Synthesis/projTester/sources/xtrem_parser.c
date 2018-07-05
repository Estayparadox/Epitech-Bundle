/*
** xtrem_parser.c for xtrem_parser in /home/pereni_j/Rendu/projTester/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jun 19 00:09:55 2015 joseph pereniguez
** Last update Fri Jun 19 15:18:50 2015 joseph pereniguez
*/

#include "projtester.h"

void		my_looptofail()
{
  printf("! Fichier mal formaté !\n");
}

void		my_dashe(char **tab, char **argv)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if ((my_strcmp(tab[i], "ARGS")) == 0 &&
	  (my_strcmp(tab[i + 1], "-e")) == 0)
	{
	  i = i + 2;
	  while ((my_strcmp(tab[i], "ARGS")) != 0)
	    {
	      if ((option_e(tab, argv, i)) == 0)
		return;
	      i++;
	    }
	}
      if ((my_strcmp(tab[i], "ARGS")) == 0 &&
	  (my_strcmp(tab[i + 1], "-e")) != 0)
	{
	  i = i + 1;
	  while ((my_strcmp(tab[i], "ARGS")) != 0)
	    {
	      if ((no_option(tab, argv, i)) == 0)
		return;
	      i++;
	    }
	}
      i++;
    }
}

int		call_checker(char **tab, char **argv)
{
  if ((check_arg(tab)) == -1)
    return (-1);
  else if ((check_arg(tab)) == 1)
    my_looptofail();
  else
    my_dashe(tab, argv);
  return (0);
}

int		check_arg(char **tab)
{
  int		i;

  i = 0;
  if ((my_strcmp(tab[0], "ARGS")) != 0 || ((my_strcmp(tab[i], "ARGS")) == 0 &&
					   tab[i + 1] == NULL))
    {
      printf("! Fichier mal formaté !\n");
      return (-1);
    }
  while (tab[i])
    {
      if ((my_strcmp(tab[i], "ARGS")) == 0 &&
	  (my_strcmp(tab[i + 1], "ENTREE")) == 0)
	return (1);
      if ((my_strcmp(tab[i], "ARGS")) == 0 &&
	  (my_strcmp(tab[i + 1], "ARGS")) == 0)
	{
	  printf("! Fichier mal formaté !\n");
	  return (-1);
	}
      i++;
    }
  return (0);
}
