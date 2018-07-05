/*
** show_alloc_mem.c for  in /home/vatine_m/PSU/PSU_2015_malloc
**
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
**
** Started on  Wed Feb 10 13:37:12 2016 vatinelle maxime
** Last update Sun Feb 14 21:02:15 2016 pereniguez joseph
*/

#include "malloc.h"

t_list		*my_global = NULL;

void            show_alloc_mem()
{
  t_list        *tmp;

  tmp = my_global;
  printf("break : %p\n", sbrk(0));
  if (tmp != NULL)
    {
      while (tmp)
        {
          if (tmp->befree == 0 && tmp->addr != NULL
	      && (tmp->addr + tmp->size) != NULL)
            printf("%p - %p : %zu bytes\n", tmp->addr,
		   tmp->addr + tmp->size, tmp->size);
          tmp = tmp->next;
        }
    }
}
