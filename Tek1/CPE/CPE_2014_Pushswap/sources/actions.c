/*
** actions.c for actions in /home/pereni_j/rendu/CPE_2014_Pushswap
**
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri Dec 12 17:11:58 2014 Pereniguez Joseph
** Last update Fri Dec 12 17:22:25 2014 Pereniguez Joseph
*/

#include <stdlib.h>
#include "pushswap.h"

int	    my_min_doc(t_list *p, int *pos)
{
  int	min;
  int	i;

  *pos = 0;
  i = 1;
  if (my_is_empty(p) == -1)
    return (-1);
  min = p->valeur;
  p = p->prec;
  while (p)
    {
      if (min > p->valeur)
	{
          min = p->valeur;
	  *pos = i;
        }
      p = p->prec;
      i = i + 1;
    }
  return (min);
}

void		my_delete_first(t_list **p, t_list **stack2)
{
  t_list	*tmp;
  int		save;

  tmp = *p;
  save = tmp->valeur;
  tmp = tmp->prec;
  free(*p);
  *p = tmp;
  my_push(stack2, save);
  my_putstr("pb");
}

void		my_reverse_doc(t_list **p)
{
  t_list	*tmp;
  t_list	*lc;

  tmp = NULL;
  lc = NULL;
  tmp = *p;
  while (tmp)
    {
      my_push(&lc, tmp->valeur);
      tmp = tmp->prec;
    }
  my_clear(&tmp);
  *p = lc;
}

void	my_clear_all(t_list *tmp, t_list *lc)
{
  my_clear(&lc);
  my_clear(&tmp);
}

void		my_rotate(t_list **p)
{
  t_list	*tmp;
  int		first;
  t_list	*lc;
  t_list	*ld;

  lc = NULL;
  ld = NULL;
  tmp = *p;
  first = tmp->valeur;
  tmp = tmp->prec;
  while (tmp)
    {
      my_push(&lc, tmp->valeur);
      tmp = tmp->prec;
    }
  my_push(&lc, first);
  tmp = lc;
  while (tmp)
    {
      my_push(&ld, tmp->valeur);
      tmp = tmp->prec;
    }
  my_putstr("ra");
  my_clear_all(tmp, lc);
  *p = ld;
}
