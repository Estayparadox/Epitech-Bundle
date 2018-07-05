/*
** my_recap_aff.c for my_recap_aff in /home/pereni_j/rendu/CPE_2014_allum1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Feb 19 11:56:41 2015 Pereniguez Joseph
** Last update Sun Feb 22 21:33:25 2015 Pereniguez Joseph
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "allum.h"

void		my_recap_aff1(int *tab)
{
  int		h;
  char		*useless;

  useless = "paradox";
  h = 2;
  my_aff_tab(tab);
  param_c2(useless, h);
  param_c3(useless, h);
  param_c4(useless, h);
  my_putchar('\n');
}

void		my_recap_aff2(int *tab)
{
  int		h;
  char		*useless;

  useless = "paradox";
  h = 2;
  param_c1(useless, h);
  my_aff_tab(tab);
  param_c3(useless, h);
  param_c4(useless, h);
  my_putchar('\n');
}

void		my_recap_aff3(int *tab)
{
  int		h;
  char		*useless;

  useless = "paradox";
  h = 2;
  param_c1(useless, h);
  param_c2(useless, h);
  my_aff_tab(tab);
  param_c4(useless, h);
  my_putchar('\n');
}

void		my_recap_aff4(int *tab)
{
  int		h;
  char		*useless;

  useless = "paradox";
  h = 2;
  param_c1(useless, h);
  param_c2(useless, h);
  param_c3(useless, h);
  my_aff_tab(tab);
  my_putchar('\n');
}
