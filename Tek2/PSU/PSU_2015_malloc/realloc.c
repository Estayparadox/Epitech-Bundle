/*
** realloc.c for  in /home/vatine_m/PSU/PSU_2015_malloc
**
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
**
** Started on  Wed Feb 10 13:35:04 2016 vatinelle maxime
** Last update Sun Feb 14 21:01:44 2016 pereniguez joseph
*/

#include "malloc.h"

void            *realloc(void *ptr, size_t size)
{
  void          *tmp;

  if (size == 0 && ptr != NULL)
    free(ptr);
  ptr = sbrk(size);
  tmp  = sbrk(size);
  memcpy(ptr, tmp, size);
  return ptr;
}
