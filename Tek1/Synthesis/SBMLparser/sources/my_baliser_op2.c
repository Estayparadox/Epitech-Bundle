/*
** my_baliser_op2.c for my_baliser_op2.c in /home/pereni_j/Rendu/SBMLparser/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jun 16 16:36:13 2015 joseph pereniguez
** Last update Tue Jun 16 16:36:47 2015 joseph pereniguez
*/

#include "sbmlparser.h"

int             baliser_speRef(char **tab, int i)
{
  static int    e;

  if ((my_strcmp(tab[i], "<speciesReference")) == 0)
    {
      e = e + 1;
      if (e <= 1)
        i = aff_baliser(tab, i);
      else
        {
          i++;
          return (i);
	}
    }
  else
    {
      i = aff_baliser(tab, i);
      return (i);
    }
  return (i);
}
