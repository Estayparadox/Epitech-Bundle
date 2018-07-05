/*
** aff.c for  in /home/vatine_m/PSU/PSU_2015_lemipc
** 
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
** 
** Started on  Sat Mar 26 13:43:57 2016 vatinelle maxime
** Last update Sat Mar 26 13:58:51 2016 vatinelle maxime
*/

#include "lemipc.h"

void		aff(struct s_case c, struct s_case *tab, char *fd)
{
  int		i;
  int		j;

  i = 0;
  j = rand() % c.width;
  while (i < c.width)
    {
      tab[j].x = atoi(fd);
      printf("%d ", tab[i].x);
      i++;
    }
  printf("\n");
}
