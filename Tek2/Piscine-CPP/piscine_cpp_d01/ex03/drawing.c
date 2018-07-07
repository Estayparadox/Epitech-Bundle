/*
** drawing.c for drawing in /home/pereni_j/Rendu/piscine_cpp_d01/ex03
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Thu Jan  7 08:45:26 2016 pereniguez joseph
** Last update Fri Sep 30 11:56:00 2016 pereniguez joseph
*/

#include "drawing.h"

void		draw_square(uint32_t ** img, t_point * orig, size_t size, uint32_t color)
{
  size_t        i;
  size_t        j;

  i = 0;
  j = 0;
  while (i < size)
    {
      j = 0;
      while (j < size)
	{
	  img[orig->x + i][orig->y + j] = color;
	  j++;
	}
      i++;
    }
}
