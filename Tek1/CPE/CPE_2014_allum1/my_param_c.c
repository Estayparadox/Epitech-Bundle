/*
** my_param_c.c for my_param_c in /home/pereni_j/rendu/CPE_2014_allum1/new_allum1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Mon Feb 16 15:58:12 2015 Pereniguez Joseph
** Last update Sat Feb 21 10:19:27 2015 Pereniguez Joseph
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "allum.h"

void		param_c1(char *buffer, int h)
{
  int		u;
  int		*tabx;

  u = 0;
  tabx = malloc(sizeof(int) * 7);
  tabx[0] = 0;
  tabx[1] = 0;
  tabx[2] = 0;
  tabx[3] = 1;
  tabx[4] = 0;
  tabx[5] = 0;
  tabx[6] = 0;
  if (h == 2)
    my_tab1(tabx, buffer[2], h);
  else
    {
      if (buffer[2] == '1')
	my_tab1(tabx, buffer[2], u);
      else
	my_putstr(">[Please retry]<\n");
    }
}

void		param_c2(char *buffer, int h)
{
  int		u;
  int		*tabx;

  tabx = malloc(sizeof(int) * 7);
  tabx[0] = 0;
  tabx[1] = 0;
  tabx[2] = 1;
  tabx[3] = 1;
  tabx[4] = 1;
  tabx[5] = 0;
  tabx[6] = 0;
  if (h == 2)
    my_tab2(tabx, buffer[2], h);
  else
    {
      u = 0;
      if (buffer[2] >= '1' && buffer[2] <= '3')
	my_tab2(tabx, buffer[2], u);
      else if (buffer[2] <= '1' || buffer[2] >= '3')
	my_putstr(">[Please retry]<\n");
      else
	my_putstr(">[Please retry]<\n");
    }
}

void		param_c3(char *buffer, int h)
{
  int		u;
  int		*tabx;

  tabx = malloc(sizeof(int) * 7);
  tabx[0] = 0;
  tabx[1] = 1;
  tabx[2] = 1;
  tabx[3] = 1;
  tabx[4] = 1;
  tabx[5] = 1;
  tabx[6] = 0;
  if (h == 2)
    my_tab3(tabx, buffer[2], h);
  else
    {
      u = 0;
      if (buffer[2] >= '1' && buffer[2] <= '5')
	my_tab3(tabx, buffer[2], u);
      else if (buffer[2] <= '1' || buffer[2] >= '5')
	my_putstr(">[Please retry]<\n");
      else
	my_putstr(">[Please retry]<\n");
    }
}

void		param_c4(char *buffer, int h)
{
  int		u;
  int		*tabx;

  tabx = malloc(sizeof(int) * 7);
  tabx[0] = 1;
  tabx[1] = 1;
  tabx[2] = 1;
  tabx[3] = 1;
  tabx[4] = 1;
  tabx[5] = 1;
  tabx[6] = 1;
  if (h == 2)
    my_tab4(tabx, buffer[2], h);
  else
    {
      u = 0;
      if (buffer[2] >= '1' && buffer[2] <= '7')
	my_tab4(tabx, buffer[2], u);
      else if (buffer[2] <= '1' || buffer[2] >= '7')
	my_putstr(">[Please retry]<\n");
      else
	my_putstr(">[Please retry]<\n");
    }
}
