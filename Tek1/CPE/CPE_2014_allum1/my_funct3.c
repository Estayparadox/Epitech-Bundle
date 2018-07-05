/*
** my_funct3.c for my_funct3 in /home/pereni_j/rendu/CPE_2014_allum1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Feb 20 09:26:10 2015 Pereniguez Joseph
** Last update Fri Feb 20 10:08:57 2015 Pereniguez Joseph
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "allum.h"

void            my_funct4_2(char c, int a, int *tab)
{
  int           s;

  s = 1;
  c = c;
  if (a == 1)
    {
      tab[0] = 0;
      tab[1] = 0;
      tab[2] = 0;
      tab[3] = 1;
      tab[4] = 0;
      tab[5] = 0;
      tab[6] = 0;
      my_tab4(tab, c, s);
    }
  else
    my_funct4_3(c, a, tab);
}

void            my_funct4_3(char c, int a, int *tab)
{
  int           s;

  s = 1;
  c = c;
  if (a == 2)
    {
      tab[0] = 0;
      tab[1] = 0;
      tab[2] = 1;
      tab[3] = 1;
      tab[4] = 0;
      tab[5] = 0;
      tab[6] = 0;
      my_tab4(tab, c, s);
    }
  else
    my_funct4_4(c, a, tab);
}

void            my_funct4_4(char c, int a, int *tab)
{
  int           s;

  s = 1;
  c = c;
  if (a == 3)
    {
      tab[0] = 0;
      tab[1] = 0;
      tab[2] = 1;
      tab[3] = 1;
      tab[4] = 1;
      tab[5] = 0;
      tab[6] = 0;
      my_tab4(tab, c, s);
    }
  else
    my_funct4_5(c, a, tab);
}

void            my_funct4_5(char c, int a, int *tab)
{
  int           s;

  s = 1;
  c = c;
  if (a == 4)
    {
      tab[0] = 0;
      tab[1] = 1;
      tab[2] = 1;
      tab[3] = 1;
      tab[4] = 1;
      tab[5] = 0;
      tab[6] = 0;
      my_tab4(tab, c, s);
    }
  else
    my_funct4_6(c, a, tab);
}

void		my_funct4_6(char c, int a, int *tab)
{
  int		s;

  c = c;
  s = 1;

  if (a == 5)
    {
      tab[0] = 0;
      tab[1] = 1;
      tab[2] = 1;
      tab[3] = 1;
      tab[4] = 1;
      tab[5] = 1;
      tab[6] = 0;
      my_tab4(tab, c, s);
    }
  else
    my_funct4_7(c, a, tab);
}
