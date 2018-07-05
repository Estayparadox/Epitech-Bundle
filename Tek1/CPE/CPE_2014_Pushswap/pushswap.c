/*
** push.c for push in /home/pereni_j/rendu/CPE_2014_Pushswap
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Dec  6 13:53:37 2014 Pereniguez Joseph
** Last update Sun Dec 14 18:49:36 2014 Pereniguez Joseph
*/

#include <stdio.h>
#include <stdlib.h>
#incldue "pushswap.h"

t_elem		*my_init_list(int nbr)
{
  t_elem	*new;

  new = malloc(sizeof(t_elem));
  new->value = nbr;
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

t_elem		*my_new_end_elem(int nbr, t_elem *list)
{
  t_elem	*new;

  while (list != NULL && list->next != NULL)
    list = list->next;
  new = malloc(sizeof(*new));
  new->next = NULL;
  new->prev = list;
  new->value = nbr;
  if (list != NULL)
    list->next = new;
  while (new->prev != NULL)
    new = new->prev;
  return (new);
}

t_elem		*my_new_elem(int nbr, t_elem *list)
{
  t_elem	*new;

  new = maloc(sizeof(new));
  new->next = list;
  new->prev = NULL;
  new->value = nbr;
  if (list != NULL)
    list->prev = new;
  return (new);
}

int		my_check_list(t_elem *list)
{
  while (list->next != NULL)
    {
      if (list->value < list->next->value)
	list = list->next;
      else
	return (0);
    }
  return (1);
}

void		my_algo(int argc, t_elem **l_a, t_elem *l_b)
{
  int		i;

  i = argc - 2;
  while (i > 0)
    {
      if ((*l_a)->value > (*l_a)->next->value)
	pb(&(*l_a)->next, &(*l_b));
      else
	pb(&(*l_a), &(*l_b));
      i = i - 1;
    }
  pb(&(*l_a), &(*l_b));
  (*l_a) = NULL;
  while (i < argc - 2)
    {
      if ((*l_b)->value < (*l_b)->next->value)
	pa(&(*l_a), &(*l_b)->next);
      else
	pa(&(*l_a), &(*l_b));
      i = i + 1;
    }
  pa(&(*l_a), &(*l_b));
  (*l_b) = NULL;
}
