/*
** new.c for ex_01 in /home/vatine_m/piscineTek2/cpp_SKL/ex_01
** 
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
** 
** Started on  Sat Jan  9 11:32:11 2016 vatinelle maxime
** Last update Sat Jan  9 21:02:39 2016 vatinelle maxime
*/

#include "new.h"
#include <string.h>
#include "raise.h"
#include "vertex.h"

Object  *new(Class *class, ...) {
  va_list       ap;

  va_start(ap, class);
  return (va_new(class, &ap));
}

void    delete(Object *ptr) {
  if (((Class*)ptr)->__del__)
    ((Class*)ptr)->__del__(ptr);
  free(ptr);
}

Object  *va_new(Class* class, va_list* ap) {
  Class *obj;

  if ((obj = malloc(class->__size__)) == NULL)
    raise("Out of memory");
  memcpy(obj, class, class->__size__);
  if (class->__init__)
    class->__init__(obj, ap);
  va_end(*ap);
  return (obj);
}
