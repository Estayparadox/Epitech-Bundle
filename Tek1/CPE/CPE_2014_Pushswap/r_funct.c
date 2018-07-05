/*
** r_funct.c for r_funct in /home/pereni_j/rendu/CPE_2014_Pushswap
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Dec 12 11:20:57 2014 Pereniguez Joseph
** Last update Sun Dec 14 18:49:09 2014 Pereniguez Joseph
*/

#include <stdlib.h>
#include <stdio.h>
#include "pushswap.h"

void		ra(t_elem **l_a)
{
  t_elem	*tmp;
  t_elem	*tmp1;
  t_elem	*tmp2;

  tmp2 = (*l_a);
  (*l_a) = (*l_a)->next;
  tmp = (*l_a);
  tmp3 = (*l_a);
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
  tmp2->next = NULL;
  tmp2->prev = tmp;
  tmp->next = tmp2;
  (*l_a) = tmp3;
  my_putstr("ra ");
}

void		rb(t_elem **l_b)
{
  t_elem	*tmp;
  t_elem	*tmp1;
  t_elem	*tmp2;

  tmp2 = (*l_b);
  (*l_b) = (*l_b)->next;
  tmp = (*l_b);
  tmp3 = (*l_b);
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
  tmp2->next = NULL;
  tmp2->prev = tmp;
  tmp->next = tmp2;
  (*l_b) = tmp3;
  my_putstr("rb ");
}

void		rr(t_elem **l_a, t_elem **l_b)
{
  ra(l_a);
  rb(l_b);
  my_putstr("rr ");
}
