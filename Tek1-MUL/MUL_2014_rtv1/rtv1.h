/*
** rtv1.h for rtv1 in /home/pereni_j/rendu/MUL_2014_wolf3d
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Dec 16 15:59:02 2014 Pereniguez Joseph
** Last update Sun Mar 15 14:31:27 2015 Pereniguez Joseph
*/

#ifndef RTV1_H_
# define RTV1_H_
# define WIDTH 550
# define WEIGHT 500
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000

typedef struct	s_elem
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  int		size_line;
  int		endian;
  int		bpp;
  char		*img;
  int		x;
  int		y;
  int		z;
  double        r;
  double        xo;
  double        yo;
  double        zo;
  double        vx;
  double        vy;
  double        vz;
  double        a;
  double        b;
  double        c;
  double        delta;
} t_elem;

int		my_sphere(t_elem *mlx, int x, int y);
int		sphere_color(t_elem *mlx, int x, int y);
void		mlx_put_pixel_to_image(t_elem *mlx, int x, int y, int z);
int		manage_sets(t_elem *mlx);
void		my_putstr(char *str);
void		my_putchar(char c);
int		my_strlen(char *str);
void		my_init_var(t_elem *mlx, int x, int y);

#endif
