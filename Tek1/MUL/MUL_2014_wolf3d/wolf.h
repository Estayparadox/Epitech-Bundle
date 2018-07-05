/*
** wolf.h for wolf in /home/pereni_j/rendu/MUL_2014_wolf3d
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Dec 16 15:59:02 2014 Pereniguez Joseph
** Last update Sun Dec 21 13:34:50 2014 Pereniguez Joseph
*/

#ifndef WOLF_H_
# define WOLF_H_
#define WIDTH 550
#define WEIGHT 500

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
} t_elem;

void		mlx_put_pixel_to_image(t_elem *mlx, int x, int y, int z);
int		sky_color(t_elem *mlx, int x, int y);
int		ground_color(t_elem *mlx, int x, int y);
int		manage_sets(t_elem *mlx);
void		my_putstr(char *str);
void		my_putchar(char c);

#endif
