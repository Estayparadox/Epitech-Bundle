/*
** my_sphere.c for my_sphere in /home/pereni_j/rendu/MUL_2014_rtv1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Mar 12 15:19:59 2015 Pereniguez Joseph
** Last update Sun Mar 15 12:50:01 2015 Pereniguez Joseph
*/

#include "mlx.h"
#include "rtv1.h"

void		my_init_var(t_elem *mlx, int x, int y)
{
  mlx->r = 100;
  mlx->xo = -300;
  mlx->yo = 0;
  mlx->zo = 50;
  mlx->vx = 100;
  mlx->vy = 500 / 2 - x;
  mlx->vz = 500 / 2 - y;
}

int		my_sphere(t_elem *mlx, int x, int y)
{
  my_init_var(mlx, x, y);
  mlx->a = pow(mlx->vx, 2) + pow(mlx->vy, 2) + pow(mlx->vz, 2);
  mlx->b = 2 * ((mlx->xo * mlx->vx)
		+ (mlx->yo * mlx->vy) + (mlx->zo * mlx->vz));
  mlx->c = pow(mlx->xo, 2) + pow(mlx->yo, 2)
    + pow(mlx->zo, 2) - pow(mlx->r, 2);
  mlx->delta = pow(mlx->b, 2) - (4 * mlx->a * mlx->c);
  if (mlx->delta >= 0)
    return (RED);
  return (BLACK);
}

int             sphere_color(t_elem *mlx, int x, int y)
{
  y = 0;

  while (y != 500)
    {
      x = 0;
      while (x != 550)
	{
          mlx_put_pixel_to_image(mlx, x, y, my_sphere(mlx, x, y));
          x = x + 1;
        }
      y = y + 1;
    }
  return (0);
}
