/*
** free.c for free in /home/pereni_j/Rendu/PSU_2015_malloc
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri Feb  5 09:55:29 2016 pereniguez joseph
** Last update Sun Feb 14 20:59:31 2016 pereniguez joseph
*/

#include "malloc.h"

void		free(void *ptr)
{
  t_list	*list;
  char		*str;

  list = sbrk(sizeof(t_list));
  if (ptr < sbrk(0) && ptr != NULL)
    {
      str = ptr;
      str -= (list->size - 1);
      ptr = str;
      list = ptr;
      list->befree = 1;
    }
}
