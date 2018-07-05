/*
** ft_min.c for ft_min in /home/pereni_j/rendu/CPE_2014_bsq
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Jan 17 10:33:49 2015 Pereniguez Joseph
** Last update Sun Jan 18 18:37:59 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include "bsq.h"

int		ret_coord(int x, int y)
{
  if (x < y)
    return (x);
  return (y);
}
