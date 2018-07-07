/*
** String.h for String in /home/pereni_j/Rendu/piscine_cpp_d03/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan  8 09:02:42 2016 pereniguez joseph
** Last update Fri Jan  8 17:14:46 2016 pereniguez joseph
*/

#ifndef STRING_H_ 
#define STRING_H_

typedef struct	String
{
  char	*str;

  void		(*assign_s)(struct String *this, struct String const * str);
  void		(*assign_c)(struct String *this, char const * s);
  void		(*append_s)(struct String* this, struct String const* ap);
  void		(*append_c)(struct String* this, char const* ap);
  char		(*at)(struct String* this, size_t pos);
  void		(*clear)(struct String* this);
  int		(*size)(struct String* this);
  int		(*compare_s)(struct String *this, const String* str);
  int		(*compare_c)(String *this, char const* str);
  size_t	(*copy)(struct String* this, char* s, size_t n, size_t pos);
  char const*	(*c_str) (struct String * this);
  int		(*empty) (struct String* this);
  void		(*aff)(struct String * this);
  int		(*find_s) (struct String* this, const String *str, size_t pos);
  int		(*find_c) (struct String* this, char const* str, size_t pos);
  void		(*insert_c)(struct String * this, size_t pos, char const* str);
  void		(*insert_s)(struct String * this, size_t pos,struct String const* str);
  int		(*to_int)(struct String * this);
  String*	(*split_s)(struct String* this, char separator);
  char**	(*split_c)(struct String* this, char separator);

}	String;

void    StringInit(String* this, char const * s);
void    StringDestroy(String* this);

#endif
