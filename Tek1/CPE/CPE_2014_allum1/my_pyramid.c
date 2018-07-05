/*
** my_pyramid.c for my_pyramid in /home/pereni_j/rendu/CPE_2014_allum1/new_allum1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Feb 17 12:22:16 2015 Pereniguez Joseph
** Last update Sat Feb 21 10:30:53 2015 Pereniguez Joseph
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "allum.h"

void            my_aff_tab(int *tab)
{
  int           i;

  i = 0;
  if (tab[0]== 0)
    printf("    ");
  else if (tab[0] == 1)
    printf("   \033[31;05m|\033[00m");
  else
    {
      printf("\033[31;05m>[TAB ERROR]<\033[00m\n");
      exit (0);
    }
  while (tab[i] <= 6)
    {
      i = i + 1;
      if (tab[i] == 0)
        printf(" ");
      else if (tab[i] == 1)
        printf("\033[31;05m|\033[00m");
    }
  printf("\n");
}

void		my_tab1(int *tabx, char c, int indic)
{
  int		*tab;

  tab = malloc(sizeof(int)* 7);
  if (indic == 1)
    {
      tab = tabx;
      my_recap_aff1(tab);
    }
  else if (indic == 0)
    {
      tab = tabx;
      my_check_tab1(c, tab);
    }
  else
    my_aff_tab(tabx);
}

void		my_tab2(int *tabx, char c, int indic)
{
  int		*tab;

  tab = malloc(sizeof(int)* 7);
  if (indic == 1)
    {
      tab = tabx;
      my_recap_aff2(tab);
    }
  else if (indic == 0)
    {
      tab = tabx;
      my_check_tab2(c, tab);
    }
  else
    my_aff_tab(tabx);
}

void		my_tab3(int *tabx, char c, int indic)
{
  int		*tab;

  tab = malloc(sizeof(int)* 7);
  if (indic == 1)
    {
      tab = tabx;
      my_recap_aff3(tab);
    }
  else if (indic == 0)
    {
      tab = tabx;
      my_check_tab3(c, tab);
    }
  else
    my_aff_tab(tabx);
}

void		my_tab4(int *tabx, char c, int indic)
{
  int		*tab;

  tab = malloc(sizeof(int)* 7);
  if (indic == 1)
    {
      tab = tabx;
      my_recap_aff4(tab);
    }
  else if (indic == 0)
    {
      tab = tabx;
      my_check_tab4(c, tab);
    }
  else
    my_aff_tab(tabx);
}
