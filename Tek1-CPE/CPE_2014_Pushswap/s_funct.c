/*
** s_funct.c for s_funct in /home/pereni_j/rendu/CPE_2014_Pushswap
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Dec 12 11:15:23 2014 Pereniguez Joseph
** Last update Sun Dec 14 20:04:42 2014 Pereniguez Joseph
*/

#include <stdlib.h>
#include <stdio.h>
#include "pushswap.h"

void            sa(t_elem *l_a)
{
  int           i;

  i = l_a->value;
  l_a->value = l_a->next->value;
  l_a->next->value = i;
}

void            sb(t_elem *l_b)
{
  int           j;

  j = l_b->value;
  l_b->value = l_b->next->value;
  l_b->next->value = j;
}

void            ss(t_elem *l_a, t_elem *l_b)
{
  int           i;
  int           j;

  i = l_a->value;
  l_a->value = l_a->next->value;
  l_a->next->value = i;
  j = l_b->value;
  l_b->value = l_b->next->value;
  l_b->next->value = j;
}
