/*
** my_op.c for my_op in /home/pereni_j/Rendu/SBMLparser/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Mon Jun 15 17:36:13 2015 joseph pereniguez
** Last update Tue Jun 16 14:32:27 2015 joseph pereniguez
*/

#include "sbmlparser.h"

void		my_compartment(char **tab, char *op)
{
  int		i;

  i = 0;
  printf("List of species in compartment %s\n", op);
  while (tab[i])
    {
      if ((my_strcmp(tab[i], op)) == 0 &&
	  (my_strcmp(tab[i - 1], "compartment")) == 0 &&
	  (my_strcmp(tab[i + 1], "name")) == 0)
	{
	  i = i + 2;
	  printf("----->");
	  while ((my_strcmp(tab[i], "id")) != 0)
	    {
	      printf("%s", tab[i]);
	      i++;
	      if ((my_strcmp(tab[i + 1], "id")) == 0)
		printf(" ");
	    }
	  printf("\n");
	}
      i++;
    }
}

int		my_species2(char **tab, int i, int j)
{
  while ((my_strcmp(tab[i], "id")) != 0)
    {
      i--;
      if ((my_strcmp(tab[i], "id")) == 0)
	{
	  printf("----->%s ", tab[i + 1]);
	  i = j;
	  while ((my_strcmp(tab[i], "stoichiometry")) != 0)
	    {
	      i--;
	      if ((my_strcmp(tab[i], "stoichiometry")) == 0)
		{
		  printf("(%s)\n", tab[i + 1]);
		  return (0);
		}
	    }
	}
    }
  return (0);
}

int		my_species(char **tab, char *op)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  printf("List of reactions consuming species %s (quantities)\n", op);
  while (tab[i])
    {
      if ((my_strcmp(tab[i], op)) == 0 &&
	  (my_strcmp(tab[i - 1], "species")) == 0)
	{
	  j = i;
	  my_species2(tab, i, j);
	  return (0);
	}
      i++;
    }
  return (0);
}

int		my_product(char **tab, char *op, int i)
{
  printf("List of products of reaction %s\n", op);
  while ((my_strcmp(tab[i], "listOfReactions")) != 0)
    {
      if ((my_strcmp(tab[i], "reaction")) == 0)
	{
	  while ((my_strcmp(tab[i], "lisOfReactants")) != 0)
	    {
	      if ((my_strcmp(tab[i], "species")) == 0)
		printf("----->%s\n", tab[i + 1]);
	      if ((my_strcmp(tab[i], "listOfReactants")) == 0)
		return (0);
	      i--;
	    }
	}
      i++;
    }
  return (0);
}

int		my_reactan(char **tab, char *op)
{
  int		i;

  i = 0;
  printf("List of reactants of reaction %s\n", op);
  while (tab[i])
    {
      if ((my_strcmp(tab[i], op)) == 0 &&
	  (my_strcmp(tab[i + 1], "listOfReactants")) == 0)
	{
	  while ((my_strcmp(tab[i], "listOfProducts")) != 0)
	    {
	      i++;
	      if ((my_strcmp(tab[i], "species")) == 0)
		printf("----->%s\n", tab[i + 1]);
	      if ((my_strcmp(tab[i], "listOfProducts")) == 0)
		{
		  my_product(tab, op, i);
		  return (0);
		}
	    }
	}
      i++;
    }
  return (0);
}
