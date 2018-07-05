/*
** my_put_pixel.c for my_put_pixel in /home/pereni_j/rendu/MUL_2014_wolf3d
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Dec 19 13:03:41 2014 Pereniguez Joseph
** Last update Thu Mar 12 16:06:27 2015 Pereniguez Joseph
*/

#include "mlx.h"
#include "rtv1.h"

void            mlx_put_pixel_to_image(t_elem *mlx, int x, int y, int z)
{
  int           i;

  i = x * 4 + y * mlx->size_line;
  mlx->img[i] = (z & 0xFF);
  mlx->img[i + 1] = (z & 0xFF00) >> 8;
  mlx->img[i + 2] = (z & 0xFF0000) >> 16;
}
