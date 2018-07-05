/*
** rr_funct.c for rr_funct in /home/pereni_j/rendu/CPE_2014_Pushswap
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Dec 12 10:57:54 2014 Pereniguez Joseph
** Last update Sun Dec 14 18:49:22 2014 Pereniguez Joseph
*/

#include <stdlib.h>
#include <stdio.h>
#include "pushswap.h"

void		rra(t_elem **l_a)
{
  t_elem	*tmp;

  tmp = (*l_a);
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
  tmp->next = (*l_a);
  tmp->prev->next = NULL;
  tmp->prev = NULL;
  (*l_a)->prev = tmp;
  (*l_a) = tmp;
  my_putstr("rra ");
}

void		rrb(t_elem **l_b)
{
  t_elem	tmp;

  tmp = (*l_b);
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
  tmp->next = (*l_b);
  tmp->prev->next = NULL;
  tmp->prev = NULL;
  (*l_b)->prev = tmp;
  (*l_b) = tmp;
  my_putstr("rrb ");
}

void		rrr(t_elem **l_a, t_elem **l_b)
{
  rra(&l_a);
  rrb(&l_b);
  my_putstr("rrr ");
}
