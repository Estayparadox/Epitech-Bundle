/*
** point.c for ex02 in /home/vatine_m/piscineTek2/cpp_SKL/ex_02
** 
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
** 
** Started on  Sat Jan  9 21:14:32 2016 vatinelle maxime
** Last update Sat Jan  9 21:23:05 2016 vatinelle maxime
*/


#include <stdio.h>
#include "point.h"
#include <stdlib.h>
#include "raise.h"

typedef struct
{
    Class base;
    int x, y;
} PointClass;

static void Point_ctor(Object* self, va_list *args)
{
  ((PointClass*)self)->x = va_arg(args, int);
  ((PointClass*)self)->y = va_arg(args, int);
}

static void Point_dtor(Object* self)
{
  ((PointClass*)self)->x = 0;
  ((PointClass*)self)->y = 0;
}

static  char const* Point_tostring(Object* self) {
  char  *tmp;

  if ((tmp = malloc(sizeof(char) * 100)) == NULL)
    raise("Out of memory");
  snprintf(tmp, 100, "<%s (%i, %i)>", ((PointClass*)self)->base.__name__, ((PointClass*)self)->x, ((PointClass*)self)->y);
  return(tmp);
}

static PointClass _description = {
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_tostring },
    0, 0
};

Class* Point = (Class*) &_description;
