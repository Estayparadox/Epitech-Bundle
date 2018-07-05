/*
** list.c for list in /home/vatine_m/PSU/PSU_2015_malloc
**
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
**
** Started on  Tue Feb  2 15:31:04 2016 vatinelle maxime
** Last update Sun Feb 14 20:59:58 2016 pereniguez joseph
*/

#include "malloc.h"

void		my_put_in_list(t_list **list, size_t size)
{
  t_list	*new;
  t_list	*tmp;

  tmp = *list;
  if (list != NULL)
    {
      new = (t_list *)(intptr_t)sbrk(sizeof(t_list) + size);
      tmp->size = size;
      new->prev = tmp;
      new->next = NULL;
      tmp->next = new;
      tmp->prev = NULL;
      tmp->befree = 0;
    }
}
