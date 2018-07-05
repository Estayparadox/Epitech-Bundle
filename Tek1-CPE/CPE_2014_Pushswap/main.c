/*
** main.c for main in /home/pereni_j/rendu/CPE_2014_Pushswap
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Dec  6 13:40:15 2014 Pereniguez Joseph
** Last update Sun Dec 14 20:10:08 2014 Pereniguez Joseph
*/

#include <stdlib.h>
#include <stdio.h>
#include "pushswap.h"

int		main(int argc, char **argv)
{
  int		i;
  t_elem	*tmp;
  t_elem	*l_a;
  t_elem	*l_b;

  tmp = l_a;
  l_b = NULL;
  *l_a = my_init_list(my_getnbr(argv[1]));
  *tmp = my_new_end_elem(my_getnbr(argv[2]), l_a);
  i = 3;
  while (i < argc)
    {
      *tmp = my_new_end_elem(my_getnbr(argv[i]), tmp);
      i = i + 1;
    }
  i = argc - 2;
  if ((my_check_list(l_a)) == 1)
    my_putstr("list sorted right\n");
  while ((my_check_list(l_a)) != 1)
    {
      my_algo(argc, &l_a, &l_b);
    }
  return (0);
}
