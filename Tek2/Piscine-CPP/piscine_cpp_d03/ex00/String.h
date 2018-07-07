/*
** String.h for String in /home/pereni_j/Rendu/piscine_cpp_d03/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan  8 09:02:42 2016 pereniguez joseph
** Last update Sat Jan  9 09:13:14 2016 pereniguez joseph
*/

#ifndef STRING_H_ 
#define STRING_H_

#include <string.h>

typedef struct	String
{
  char	*str;

  void	(*assign_s) (struct String *this, struct String const * str);
  void	(*assign_c) (struct String *this, char const * s);

}		String;

void	StringInit(String* this, char const * s);
void	StringDestroy(String* this);

#endif
