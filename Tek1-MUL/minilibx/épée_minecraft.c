/*
** épée_minecraft.c for épée_minecraft in /home/pereni_j/rendu/minilibx
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Mon Oct 27 15:01:09 2014 joseph pereniguez
** Last update Mon Oct 27 16:52:10 2014 joseph pereniguez
*/

#include "mlx.h"

void	bigger_pixel(void *mlx_ptr, void *win_ptr, int a, int b, int color)
{
  int	bb;
  int	aa;
  int	aaa;

  bb = b + 9;
  aaa = a + 10;
  aa = a + 9;
  while (a != aaa)
    {
      mlx_pixel_put(mlx_ptr, win_ptr, a, b, color);
      if (a == aa && b != bb)
	{
	  a = a - 10;
	  b = b + 1;
	}
      a = a + 1;
    }
}

void	screen(void *mlx_ptr, void *win_ptr,int x,int y, int color)
{
  int	bb;
  int	aa;
  int	aaa;
  int	a;
  int	b;

  a = 0;
  b = 0;
  bb = 999;
  aaa = 1000;
  aa = 999;
  while (a != aaa)
    {
      mlx_pixel_put(mlx_ptr, win_ptr, a, b, color);
      if (a == aa && b != bb)
	{
	  a = a - 1000;
	  b = b + 1;
	}
      a = a + 1;
    }
}

int    main()
{
  void *mlx_ptr;
  void *win_ptr;
  
  mlx_ptr = mlx_init();
  win_ptr = mlx_new_window(mlx_ptr,320,320,"My first window");
  screen(mlx_ptr, win_ptr,0,0,0x00FFFFFF);
  while (42)
    {
      bigger_pixel (mlx_ptr, win_ptr,270,50,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,270,60,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,270,70,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,260,50,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,250,50,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,240,60,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,230,70,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,220,80,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,210,90,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,200,100,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,190,110,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,230,110,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,220,120,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,210,130,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,240,100,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,250,90,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,260,80,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,160,110,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,170,120,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,170,130,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,180,140,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,190,150,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,200,150,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,210,160,0x009CA2A1);
      bigger_pixel (mlx_ptr, win_ptr,140,180,0x009CA2A1);
      
      bigger_pixel (mlx_ptr, win_ptr,250,60,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,260,60,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,240,70,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,250,70,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,260,70,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,230,80,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,240,80,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,250,80,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,220,90,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,230,90,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,240,90,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,210,100,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,220,100,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,230,100,0xE9EFEE);   
      bigger_pixel (mlx_ptr, win_ptr,200,110,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,210,110,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,220,110,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,190,120,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,200,120,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,210,120,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,190,130,0xE9EFEE);
      bigger_pixel (mlx_ptr, win_ptr,200,130,0xE9EFEE);

      bigger_pixel (mlx_ptr, win_ptr,150,100,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,160,100,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,150,110,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,170,110,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,160,120,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,160,130,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,180,120,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,180,130,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,170,140,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,190,140,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,200,140,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,180,150,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,190,160,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,200,160,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,210,150,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,220,160,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,210,170,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,220,170,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,130,170,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,140,170,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,130,180,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,130,190,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,140,190,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,150,190,0x000000);
      bigger_pixel (mlx_ptr, win_ptr,150,180,0x000000);
      
      bigger_pixel (mlx_ptr, win_ptr,160,150,0x624200);
      bigger_pixel (mlx_ptr, win_ptr,170,160,0x624200);
      bigger_pixel (mlx_ptr, win_ptr,150,160,0x624200);
      bigger_pixel (mlx_ptr, win_ptr,160,170,0x624200);

      bigger_pixel (mlx_ptr, win_ptr,170,150,0xCE9B35);
      bigger_pixel (mlx_ptr, win_ptr,160,160,0xCE9B35);
      bigger_pixel (mlx_ptr, win_ptr,150,170,0xCE9B35);
    }
}
