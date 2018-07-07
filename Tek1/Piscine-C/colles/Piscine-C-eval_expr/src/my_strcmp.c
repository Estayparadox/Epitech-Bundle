/*
** my_strcmp.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

int		my_strcmp(const char *s1, const char *s2)
{
  int		i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      i += 1;
    }
  if (s1[i] != '\0' && s2[i] == '\0')
    return (1);
  else if (s2[i] != '\0' && s1[i] == '\0')
    return (-1);
  return (0);
}
