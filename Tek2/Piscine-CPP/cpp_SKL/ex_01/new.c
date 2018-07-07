/*
** new.c for ex_01 in /home/vatine_m/piscineTek2/cpp_SKL/ex_01
** 
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
** 
** Started on  Sat Jan  9 11:32:11 2016 vatinelle maxime
** Last update Sat Jan  9 14:29:37 2016 vatinelle maxime
*/

#include "new.h"
#include <string.h>
#include "raise.h"

void	*new(Class *class) {
  Object	*obj;

  if ((obj = malloc(class->__size__)) == NULL)
    raise("Out of memory");
  memcpy(obj, class, class->__size__);
  if (class->__init__)
      class->__init__(obj);
  return (obj);
}

void	delete(Object *ptr) {
  if (((Class*)ptr)->__del__)
    ((Class*)ptr)->__del__(ptr);
  free(ptr);
}
