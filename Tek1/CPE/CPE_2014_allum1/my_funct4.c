/*
** my_funct4.c for my_funct4 in /home/pereni_j/rendu/CPE_2014_allum1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Feb 20 09:30:45 2015 Pereniguez Joseph
** Last update Fri Feb 20 10:09:05 2015 Pereniguez Joseph
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "allum.h"

void            my_funct4_7(char c, int a, int *tab)
{
  int           s;

  c = c;
  s = 1;
  if (a == 6)
    {
      tab[0] = 1;
      tab[1] = 1;
      tab[2] = 1;
      tab[3] = 1;
      tab[4] = 1;
      tab[5] = 1;
      tab[6] = 0;
      my_tab4(tab, c, s);
    }
}
