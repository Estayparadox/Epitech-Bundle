/*
** String.c for String in /home/pereni_j/Rendu/piscine_cpp_d03/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan  8 09:02:50 2016 pereniguez joseph
** Last update Fri Jan  8 22:19:06 2016 pereniguez joseph
*/

#include "String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void	assign_s(String*, String const*);
static void	assign_c(String*, char const*);
static void	append_s(String*, String const*);
static void	append_c(String*, char const*);

void		StringInit(String* this, char const *s)
{
  this->str = strdup(s);
  this->assign_s = &assign_s;
  this->assign_c = &assign_c;
  this->append_s = &append_s;
  this->append_c = &append_c;
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

static void	append_s(String* this, String const* ap)
{
  append_c(this, ap->str);
}

static void	append_c(String* this, char const* ap)
{
  if (ap)
    {
      this->str = realloc(this->str, ((strlen(this->str) + strlen(ap) + 2) * sizeof(char)));
      strcat(this->str, ap);
    }
}
