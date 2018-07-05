/*
** malloc_list.c for malloc_list in /home/pereni_j/rendu/CPE_2014_bsq
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Jan 17 10:10:59 2015 Pereniguez Joseph
** Last update Sun Jan 18 18:41:58 2015 Pereniguez Joseph
*/

#include <stdlib.h>
#include "bsq.h"

t_elem		*malloc_list(char *str)
{
  t_elem	*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (NULL);
  elem->str = str;
  elem->next = NULL;
  return (elem);
}
