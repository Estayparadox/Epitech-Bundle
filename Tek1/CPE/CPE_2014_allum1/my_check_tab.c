/*
** my_check_tab.c for my_check_tab in /home/pereni_j/rendu/CPE_2014_allum1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Feb 18 13:27:22 2015 Pereniguez Joseph
** Last update Fri Feb 20 10:06:16 2015 Pereniguez Joseph
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "allum.h"

void		my_check_tab1(char c, int *tab)
{
  int		i;
  int		j;
  int		nb;
  int		a;

  a = 0;
  i = 0;
  j = 0;
  nb = c - '0';
  while (tab[i] <= 6)
    {
      i = i + 1;
      if (tab[i] == 1)
	j = j + 1;
    }
  if (nb <= j || nb == j)
    {
      a = j - nb;
      my_funct1(c, a, tab);
    }
  else
    my_putstr(">[Please retry]<\n");
}

void		my_check_tab2(char c, int *tab)
{
  int		i;
  int		j;
  int		nb;
  int		a;

  a = 0;
  i = 0;
  j = 0;
  nb = c - '0';
  while (tab[i] <= 6)
    {
      i= i + 1;
      if (tab[i] == 1)
        j = j + 1;
    }
  if (nb <= j || nb == j)
    {
      a = j - nb;
      my_funct2(c, a, tab);
    }
  else
    my_putstr(">[Please retry]<\n");
}

void		my_check_tab3(char c, int *tab)
{
  int		i;
  int		j;
  int		nb;
  int		a;

  a = 0;
  i = 0;
  j = 0;
  nb = c - '0';
  while (tab[i] <= 6)
    {
      i= i + 1;
      if (tab[i] == 1)
        j = j + 1;
    }
  if (nb <= j || nb == j)
    {
      a = j - nb;
      my_funct3(c, a, tab);
    }
  else
    my_putstr(">[Please retry]<\n");
}

void		my_check_tab4(char c, int *tab)
{
  int		i;
  int		j;
  int		nb;
  int		a;

  a = 0;
  i = 0;
  j = 0;
  nb = c - '0';
  if (tab[0] == 1)
    j = 1;
  while (tab[i] <= 6)
    {
      i= i + 1;
      if (tab[i] == 1)
        j = j + 1;
    }
  if (nb <= j || nb == j)
    {
      a = j - nb;
      my_funct4(c, a, tab);
    }
  else
    my_putstr(">[Please retry]<\n");
}
