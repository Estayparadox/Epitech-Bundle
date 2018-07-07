/*
** String.c for String in /home/pereni_j/Rendu/piscine_cpp_d03/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan  8 09:02:50 2016 pereniguez joseph
** Last update Fri Jan  8 10:16:35 2016 pereniguez joseph
*/

#include "String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	StringInit(String* this, char const *s)
{
  this->str = strdup(s);
}

void    StringDestroy(String* this)
{
  free(this->str);
}
