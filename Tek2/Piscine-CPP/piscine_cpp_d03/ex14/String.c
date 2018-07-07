/*
** String.c for String in /home/pereni_j/Rendu/piscine_cpp_d03/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan  8 09:02:50 2016 pereniguez joseph
** Last update Fri Jan  8 17:18:34 2016 pereniguez joseph
*/

#include "String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	assign_s (String *this, String const * str);
static void	assign_c (String *this, char const * s);
static void	append_s(String* this, String const* ap);
static void	append_c(String* this, char const* ap);
static char	at(String* this, size_t pos);
static void	clear(String* this);
static int	size(String* this);
static int	compare_s(String *this, const String* str);
static int	compare_c(String *this, char const* str);
static size_t	copy(String* this, char* s, size_t n, size_t pos);
static char const* c_str (String * this);
static int	empty (String* this);
static void	aff(String * this);
static int	find_s (String* this, const String *str, size_t pos);
static int      find_c (String* this, char const* str, size_t pos);
static void     insert_c(String * this, size_t pos, char const* str);
static void     insert_s(String * this, size_t pos, String const* str);
static int      to_int(String * this);
static String*  split_s(String* this, char separator);
static char**   split_c(String* this, char separator);

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
  this->copy = &copy;
  this->c_str = &c_str;
  this->empty = &empty;
  this->find_s = &find_s;
  this->find_c = &find_c;
  this->insert_c = &insert_c;
  this->insert_s = &insert_s;
  this->to_int = &to_int;
  this->split_s = &split_s;
  this->split_c = &split_c;
}

void		StringDestroy(String* this)
{
  memset(this, 0, sizeof(String));
}

static void	assign_s (String *this, String const * str)
{
  assign_c(this, str->str);
  //free(this->str);
}

static void	assign_c (String *this, char const * s)
{
  StringDestroy(this);
  StringInit(this, s);
}

static void	append_s(String* this, String const* ap)
{
  append_c(this, str->str);
  //free(this->str);
}

static void	append_c(String* this, char const* ap)
{
  char        *str;

  if ((str = malloc(strlen(this->str) + strlen(ap))) == NULL)
    exit(0);
  str =strcat(str, ap);
  str =strcat(str, this->str);
  this->str = str;
}

static char	at(String* this, size_t pos)
{
  int		i = 0;

  while (this->str[i])
    {
      if (this->str[i] == this->str[pos])
	return (this->str[i]);
      i++;
    }
  return (-1);
}

static void	clear(String* this)
{
  memset(this, 0, sizeof(String));
}

static int	size(String* this)
{
  if (strlen(this->str) == NULL)
    return (-1);
  else
    return (strlen(this->str))
}

static int	compare_s(String *this, const String* str)
{
  return (compare_c(this, str->str));
}

static int	compare_c(String *this, char const* str)
{
  return (strcmp(this->str, str));
}

static size_t	copy(String* this, char* s, size_t n, size_t pos)
{
  int		i = 0;

  while (n-- > 0 && pos < strlen(this->str))
    {
      s[i++] = this->str[pos++];
    }
  s[i] = '\0';
  return (i);
}

static char const* c_str (String * this)
{
  return (this->str);
}

static int	empty (String* this)
{
  if (this->str == NULL && this == NULL)
    return (1);
  return (-1);
}

static int	find_s (String* this, const String *str, size_t pos)
{
  return (0);
}

static int	find_c (String* this, char const* str, size_t pos)
{
  return (0);
}

static void	insert_c(String * this, size_t pos, char const* str)
{
}

static void	insert_s( String * this, size_t pos, String const* str)
{
}

static int	to_int(String * this)
{
  return (0);
}

static String*	split_s(String* this, char separator)
{
  return (this->str);
}

static char**	split_c(String* this, char separator)
{
  char		**koala = *koala;

  return (koala);
}

static void	aff(String * this)
{
  int		i = 0;

  while (this->str[i])
    {
      printf("%c", this->str[i]);
      i++;
    }
}
