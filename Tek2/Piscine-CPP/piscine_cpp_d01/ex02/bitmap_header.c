/*
** bitmap_header.c for bitmap_header in /home/pereni_j/Rendu/piscine_cpp_d01/ex02
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jan  6 16:29:40 2016 pereniguez joseph
** Last update Wed Jan  6 18:33:23 2016 pereniguez joseph
*/

#include "bitmap.h"

void	make_bmp_header(t_bmp_header *header, size_t size)
{
  int	i;

  i = 1;
  if (*(char*) & i == 1)
    header->magic = 0x4D42;
  else
    header->magic = 0x424D;
  header->size = size * size * sizeof(int) + sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
  header->_app1 = 0;
  header->_app2 = 0;
  header->offset = sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
}

void	make_bmp_info_header(t_bmp_info_header *header, size_t size)
{
  header->size = 40;
  header->width = size;
  header->height = size;
  header->planes = 1;
  header->bpp = 32;
  header->compression = 0;
  header->raw_data_size = size * size *4;
  header->h_resolution = 0;
  header->v_resolution = 0;
  header->palette_size = 0;
  header->important_colors = 0;
}
