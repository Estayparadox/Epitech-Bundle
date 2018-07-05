/*
** main.c for main in /home/pereni_j/rendu/minilibx
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Mon Oct 27 14:22:21 2014 joseph pereniguez
** Last update Mon Oct 27 15:00:16 2014 joseph pereniguez
*/

#include <mlx.h>

int    main()
{
  void *mlx_ptr;
  void *win_ptr;
  
  mlx_ptr = mlx_init();
  win_ptr = mlx_new_window(mlx_ptr,320,320,"My first window");
  mlx_pixel_put(mlx_ptr,win_ptr,250,250,0xFFFFFF);
  while (42);
}
