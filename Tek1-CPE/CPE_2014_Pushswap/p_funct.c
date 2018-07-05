/*
** p_funct.c for p_funct in /home/pereni_j/rendu/CPE_2014_Pushswap
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Dec 12 11:17:33 2014 Pereniguez Joseph
** Last update Sun Dec 14 20:35:16 2014 Pereniguez Joseph
*/

#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

void		pa(t_elem **l_a, t_elem **l_b)
{
  t_elem	*tmp;
  int		i;

  tmp = (*l_b);
  i = tmp->value;
  if (tmp->next != NULL)
    tmp = tmp->next;
  else if (tmp != NULL)
    tmp->prev = NULL;
  (*l_b) = tmp;
  (*l_a) = my_new_elem(i, *l_a);
  i = i + 1;
  my_putstr("pa ");
}

void		pb(t_elem **l_a, t_elem **l_b)
{
  t_elem	*tmp;
  int		i;

  tmp = (*l_a);
  i = tmp->value;
  if (tmp->next != NULL)
    tmp = tmp->next;
  else if (tmp != NULL)
    tmp->prev = NULL;
  (*l_a) = tmp;
  (*l_b) = my_new_elem(i, *l_b);
  i = i + 1;
  my_putstr("pb ");
}
