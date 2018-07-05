/*
** my_funct2.c for my_funct2 in /home/pereni_j/rendu/CPE_2014_allum1/new_allum1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Feb 17 14:15:23 2015 Pereniguez Joseph
** Last update Fri Feb 20 10:08:19 2015 Pereniguez Joseph
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "allum.h"

void            my_funct3_2(char c, int a, int *tab)
{
  int		s;

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
      my_tab3(tab, c, s);
    }
  else
    my_funct3_3(c, a, tab);
}

void		my_funct3_3(char c, int a, int *tab)
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
      my_tab3(tab, c, s);
    }
  else
    my_funct3_4(c, a, tab);
}

void		my_funct3_4(char c, int a, int *tab)
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
      my_tab3(tab, c, s);
    }
  else
    my_funct3_5(c, a, tab);
}

void            my_funct3_5(char c, int a, int *tab)
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
      my_tab3(tab, c, s);
    }
}

void		my_funct4(char c, int a, int *tab)
{
  int           s;

  s = 1;
  c = c;
  if (a == 0)
    {
      tab[0] = 0;
      tab[1] = 0;
      tab[2] = 0;
      tab[3] = 0;
      tab[4] = 0;
      tab[5] = 0;
      tab[6] = 0;
      my_tab4(tab, c, s);
    }
  else
    my_funct4_2(c, a, tab);
}
