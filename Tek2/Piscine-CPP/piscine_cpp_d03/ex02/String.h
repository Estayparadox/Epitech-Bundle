/*
** String.h for String in /home/pereni_j/Rendu/piscine_cpp_d03/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan  8 09:02:42 2016 pereniguez joseph
** Last update Sat Jan  9 09:22:12 2016 pereniguez joseph
*/

#ifndef STRING_H_ 
#define STRING_H_

#include <string.h>

typedef struct	String
{
  char	*str;

  void		(*assign_s)(struct String*, struct String const *);
  void		(*assign_c)(struct String*, char const *);
  void		(*append_s)(struct String*, struct String const*);
  void		(*append_c)(struct String*, char const*);

}		String;

void    StringInit(String*, char const*);
void    StringDestroy(String*);

#endif
