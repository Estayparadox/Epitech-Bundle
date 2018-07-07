/*
** String.c for String in /home/pereni_j/Rendu/piscine_cpp_d03/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan  8 09:02:50 2016 pereniguez joseph
** Last update Sat Jan  9 09:24:13 2016 pereniguez joseph
*/

#include "String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void     assign_s (String*, String const*);
static void     assign_c (String*, char const*);
static void     append_s(String*, String const*);
static void     append_c(String*, char const*);
static char     at(String* this, size_t pos);
static void     clear(String* this);
static int      size(String* this);
static int	compare_s(String *this, const String* str);
static int	compare_c(String *this, char const* str);

void		StringInit(String* this, char const *s)
{
  this->str = strdup(s);
  this->assign_s = &assign_s;
  this->assign_c = &assign_c;
  this->append_s = &append_s;
  this->append_c = &append_c;
  this->at = &at;
  this->clear = &clear;
  this->size = &size;
  this->compare_s = &compare_s;
  this->compare_c = &compare_c;
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

static void     append_c(String* this, char const* ap)
{
  if (ap)
    {
      this->str = realloc(this->str, ((strlen(this->str) + strlen(ap) + 2) * sizeof(char)));
      str =strcat(str, this->str);
    }
}

static char     at(String* this, size_t pos)
{
  if ((pos <= strlen(this->str) - 1))
    return (this->str[pos]);
  return (-1);
}

static void     clear(String* this)
{
  memset(this->str, 0, sizeof(this->str));
}

static int      size(String* this)
{
  if (strlen(this->str) == NULL)
    return (-1);
  return (strlen(this->str));
}

static int	compare_s(String *this, const String* str)
{
  return (compare_c(this, str->str));
}

static int	compare_c(String *this, char const* str)
{
  return (strcmp(this->str, str));
}
