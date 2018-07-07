/*
** tab_to_2dtab.c for tab_to_2dtab in /home/pereni_j/Rendu/piscine_cpp_d02m/ex02
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Thu Jan  7 11:13:28 2016 pereniguez joseph
** Last update Sat Oct  1 11:40:03 2016 pereniguez joseph
*/

#include <stdlib.h>
#include <stdio.h>

void	tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int	**tabtab = malloc((length) * sizeof(int*));
  int	value;
  int	x;
  int	y = 0;

  while (y < length)
    {
      x = 0;
      tabtab[y] = malloc((width) * sizeof(int));
      while (x < width)
	{
	  tabtab[y][x] = tab[value];
	  x++;
	  value++;
	}
      y++;
    }
  *res = tabtab;
}
