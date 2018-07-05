/*
** xmalloc.c for xmalloc in /home/kadri_j/rush3/BocalEmblem/I : The Sacred Stones
** 
** Made by Jade Kadri
** Login   <kadri_j@epitech.net>
** 
** Started on  Sat May 16 15:29:34 2015 Jade Kadri
** Last update Sat May 16 15:39:49 2015 Jade Kadri
*/

#include "strategic.h"

void		*xmalloc(int len)
{
  void		*str;

  str = malloc(len);
  return (str);
}
