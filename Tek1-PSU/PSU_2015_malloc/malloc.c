/*
** malloc.c for malloc in /home/vatine_m/PSU/PSU_2015_malloc
**
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
**
** Started on  Tue Feb  2 15:30:49 2016 vatinelle maxime
** Last update Sun Feb 14 21:02:30 2016 pereniguez joseph
*/

#include "malloc.h"

extern t_list		*my_global;
pthread_mutex_t		mutex = PTHREAD_MUTEX_INITIALIZER;

void		*malloc(size_t size)
{
  t_list	*list;

  if (size == 0)
    return NULL;
  size = (size -1) / 4 * 4 + 4;
  pthread_mutex_lock(&mutex);
  list = sbrk(sizeof(t_list) + size);
  list->addr = sbrk(size);
  my_put_in_list(&list, size);
  my_global = list;
  pthread_mutex_unlock(&mutex);
  return (list);
}
