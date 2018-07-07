/*
** drawing.h for drawing in /home/pereni_j/Rendu/piscine_cpp_d01/ex03
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Thu Jan  7 08:45:37 2016 pereniguez joseph
** Last update Fri Sep 30 12:03:55 2016 pereniguez joseph
*/

#ifndef __DRAWING_H__
# define __DRAWING_H__

# include <stdint.h>
# include <stdlib.h>

typedef struct          s_point
{
  unsigned int          x;
  unsigned int          y;
}                       t_point;

void draw_square(uint32_t ** img, t_point * orig, size_t size, uint32_t color);

#endif /* __DRAWING_H__ */
