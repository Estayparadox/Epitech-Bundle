/*
** color.c for color in /home/pereni_j/rendu/MUL_2014_wolf3d
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Dec 19 13:03:41 2014 Pereniguez Joseph
** Last update Sun Dec 21 13:38:49 2014 Pereniguez Joseph
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mlx.h"
#include "wolf.h"

void            mlx_put_pixel_to_image(t_elem *mlx, int x, int y, int z);

int		sky_color(t_elem *mlx, int x, int y)
{
  y = 0;
  x = 0;

  while (y != 250)
    {
      x = 0;
      while (x != 550)
	{
	  mlx_put_pixel_to_image(mlx, x, y, 0x03224C);
	  x = x + 1;
	}
      y = y + 1;
    }
  return (0);
}

int		ground_color(t_elem *mlx, int x, int y)
{
  y = 250;

  while (y != 500)
    {
      x= 0;
      while (x != 550)
	{
          mlx_put_pixel_to_image(mlx, x, y, 0x8B6C42);
          x = x + 1;
	}
      y = y + 1;
    }
  return (0);
}

void            mlx_put_pixel_to_image(t_elem *mlx, int x, int y, int z)
{
  int           i;

  i = x * 4 + y * mlx->size_line;
  mlx->img[i] = (z & 0xFF);
  mlx->img[i + 1] = (z & 0xFF00) >> 8;
  mlx->img[i + 2] = (z & 0xFF0000) >> 16;
}
