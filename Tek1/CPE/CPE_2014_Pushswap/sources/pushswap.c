/*
** push.c for push in /home/pereni_j/rendu/CPE_2014_Pushswap
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Dec  6 13:53:37 2014 Pereniguez Joseph
** Last update Sun Dec 14 18:49:36 2014 Pereniguez Joseph
*/

#include <stdlib.h>
#include "pushswap.h"

void		my_push(t_list **p, int Val)
{
  t_list	*element;

  element = malloc(sizeof(t_list));
  if (element == NULL)
    exit(EXIT_FAILURE);
  element->valeur = Val;
  element->prec = *p;
  *p = element;
}

void		my_clear(t_list **p)
{
    t_list	*tmp;

    while (*p) {
        tmp = (*p)->prec;
        free(*p);
        *p = tmp;
    }
}

int	    my_length(t_list *p)
{
    int	n;

    n = 0;
    while (p) {
        n = n + 1;
        p = p->prec;
    }
    return (n);
}

int	    my_is_empty(t_list *p)
{
    if (!p)
        return -1;
    else
        return (0);
}

void	my_var_ini(int *i, int *pos, int flag, t_list *p)
{
    if (flag == 1) {
        my_putchar(' ');
        *pos = *pos - 1;
    }
    if (flag == 2) {
        *i = 0;
        *pos = 0;
        if (my_is_empty(p) != -1)
	        my_putchar(' ');
    }
}
