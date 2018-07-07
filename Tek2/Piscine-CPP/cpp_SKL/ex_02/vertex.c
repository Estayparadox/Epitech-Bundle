/*
** vertex.c for ex02 in /home/vatine_m/piscineTek2/cpp_SKL/ex_02
** 
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
** 
** Started on  Sat Jan  9 14:42:33 2016 vatinelle maxime
** Last update Sat Jan  9 21:22:39 2016 vatinelle maxime
*/

#include "vertex.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include "raise.h"

typedef struct
{
  Class base;
  int x, y, z;
} VertexClass;

static void Vertex_ctor(Object* self, va_list *args)
{
  ((VertexClass*)self)->x = va_arg(args, int);
  ((VertexClass*)self)->y = va_arg(args, int);
  ((VertexClass*)self)->z = va_arg(args, int);
}

static void Vertex_dtor(Object* self)
{
  ((VertexClass*)self)->x = 0;
  ((VertexClass*)self)->y = 0;
  ((VertexClass*)self)->z = 0;
}

static	char const* Vertex_to_string(Object* self) {
  char	*tmp;

  if ((tmp = malloc(sizeof(char) * 100)) == NULL)
    raise("Out of memory");
  snprintf(tmp, 100, "<%s (%i, %i, %i)>", ((VertexClass*)self)->base.__name__, ((VertexClass*)self)->x, ((VertexClass*)self)->y, ((VertexClass*)self)->z);
  return(tmp);
}

static VertexClass _description = {
  { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_to_string },
  0, 0, 0
};

Class* Vertex = (Class*) &_description;
