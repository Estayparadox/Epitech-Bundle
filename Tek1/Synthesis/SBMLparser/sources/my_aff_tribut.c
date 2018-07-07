/*
** my_aff_tribut.c for my_aff_tribut in /home/pereni_j/Rendu/SBMLparser/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "sbmlparser.h"

void		aff_attribut(char **tab, int i)
{
  char		*str;
  int		j;
  int		k;

  j = 0;
  k = 0;
  str = malloc(sizeof(char) * (my_strlen(tab[i]) - 1));
  while (tab[i][k] != '=')
    {
      str[j] = tab[i][k];
      j++;
      k++;
    }
  printf("----->%s\n", str);
}

int		aff_baliser(char **tab, int i)
{
  char		*str;
  int		j;
  int		k;

  j = 0;
  k = 1;
  str = malloc(sizeof(char) * (my_strlen(tab[i]) - 1));
  while (tab[i][k] != '\0')
    {
      str[j] = tab[i][k];
      j++;
      k++;
    }
  printf("%s\n", str);
  while (tab[i][0] != '>')
    {
      if (tab[i][my_strlen(tab[i]) - 1] == '=')
        aff_attribut(tab, i);
      i++;
    }
  return (i);
}

void		my_baliser(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if (tab[i][0] == '<' && tab[i][my_strlen(tab[i]) - 1] != '>' &&
	  tab[i][1] != '\0')
	i = baliser_sbml(tab, i);
      i++;
    }
}
