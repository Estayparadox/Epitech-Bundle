/*
** my_baliser_op.c for my_baliser_op in /home/pereni_j/Rendu/SBMLparser/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jun 16 14:40:35 2015 joseph pereniguez
** Last update Tue Jun 16 16:36:52 2015 joseph pereniguez
*/

#include "sbmlparser.h"

int		baliser_sbml(char **tab, int i)
{
  if ((my_strcmp(tab[i], "<sbml")) == 0)
    {
      i = aff_baliser(tab, i);
      return (i);
    }
  else
    baliser_model(tab, i);
  return (i);
}

int		baliser_model(char **tab, int i)
{
  static int	a;

  if ((my_strcmp(tab[i], "<model")) == 0)
    {
      a = a + 1;
      if (a <= 1)
	i = aff_baliser(tab, i);
      else
	{
	  i++;
	  return (i);
	}
    }
  else
    baliser_compartment(tab, i);
  return (i);
}

int		baliser_compartment(char **tab, int i)
{
  static int	b;

  if ((my_strcmp(tab[i], "<compartment")) == 0)
    {
      b = b + 1;
      if (b <= 1)
	i = aff_baliser(tab, i);
      else
	{
	  i++;
	  return (i);
	}
    }
  else
    baliser_species(tab, i);
  return (i);
}

int		baliser_species(char **tab, int i)
{
  static int	c;

  if ((my_strcmp(tab[i], "<species")) == 0)
    {
      c = c + 1;
      if (c <= 1)
	i = aff_baliser(tab, i);
      else
	{
	  i++;
	  return (i);
	}
    }
  else
    baliser_reaction(tab, i);
  return (i);
}

int		baliser_reaction(char **tab, int i)
{
  static int	d;

  if ((my_strcmp(tab[i], "<reaction")) == 0)
    {
      d = d + 1;
      if (d <= 1)
	i = aff_baliser(tab, i);
      else
	{
	  i++;
	  return (i);
	}
    }
  else
    baliser_speRef(tab, i);
  return (i);
}
