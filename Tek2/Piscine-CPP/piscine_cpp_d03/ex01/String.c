/*
** String.c for String in /home/pereni_j/Rendu/piscine_cpp_d03/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan  8 09:02:50 2016 pereniguez joseph
** Last update Fri Jan  8 14:00:05 2016 pereniguez joseph
*/

#include "String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	assign_s (String *this, String const * str);
static void	assign_c (String *this, char const * s);

void		StringInit(String* this, char const *s)
{
  this->str = strdup(s);
  this->assign_s = &assign_s;
  this->assign_c = &assign_c;
}

void		StringDestroy(String* this)
{
  memset(this, 0, sizeof(String));
}

static void	assign_s (String *this, String const * str)
{
  assign_c(this, str->str);
}

static void	assign_c (String *this, char const * s)
{
  StringDestroy(this);
  StringInit(this, s);
}
