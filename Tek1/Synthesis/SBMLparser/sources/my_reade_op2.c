/*
** my_reade_op2.c for my_reade_op2 in /home/pereni_j/Rendu/SBMLparser/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jun 16 09:52:25 2015 joseph pereniguez
** Last update Tue Jun 16 09:59:13 2015 joseph pereniguez
*/

#include "sbmlparser.h"

int		check_icompartment(char **tab, char *op, int i)
{
  if ((my_strcmp(tab[i], op)) == 0 &&
      (my_strcmp(tab[i - 1], "compartment")) == 0 &&
      (my_strcmp(tab[i + 1], "name")) == 0)
    return (0);
  else
    return (-1);
  return (-1);
}

int		check_ispecies(char **tab, char *op, int i)
{
  if ((my_strcmp(tab[i], op)) == 0 &&
      (my_strcmp(tab[i - 1], "species")) == 0 &&
      (my_strcmp(tab[i - 3], "stoichiometry")) == 0)
    return (0);
  else
    return (-1);
  return (-1);
}

int		check_ireactan(char **tab, char *op, int i)
{
  if ((my_strcmp(tab[i], op)) == 0 &&
      (my_strcmp(tab[i - 1], "id")) == 0 &&
      ((my_strcmp(tab[i + 1], "listOfReactants")) == 0 ||
       (my_strcmp(tab[i + 1], "listOfProducts")) == 0))
    return (0);
  else
    return (-1);
  return (-1);
}
