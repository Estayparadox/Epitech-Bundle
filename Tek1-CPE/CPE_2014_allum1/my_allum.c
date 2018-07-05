/*
** my_allum.c for my_allum in /home/pereni_j/rendu/CPE_2014_allum1/new_allum1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Feb 13 19:01:30 2015 Pereniguez Joseph
** Last update Sat Feb 21 10:20:09 2015 Pereniguez Joseph
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "allum.h"

void		find_column(char *buffer)
{
  int		h;

  h = 1;
  if (buffer[0] == '1')
    param_c1(buffer, h);
  else if (buffer[0] == '2')
    param_c2(buffer, h);
  else if (buffer[0] == '3')
    param_c3(buffer, h);
  else
    param_c4(buffer, h);
}

void		my_second_q(char *buffer)
{
  if (buffer[0] >= '1' && buffer[0] <= '4'
      && buffer[1] == '-' && buffer[2] >= '1'
      && buffer[2] <= '7' && buffer[3] == '\n')
    find_column(buffer);
  else if (buffer[0] == 'e' && buffer[1] == 'x'
	   && buffer[2] == 'i' && buffer[3] == 't'
	   && buffer[4] == '\n')
    exit (0);
  else
    my_putstr(">[Please retry]<\n");
}

void		my_allum(char *buffer)
{
  my_putstr("Please enter the number of the line and the ");
  my_putstr("number of matches you want to delete (as 3-4): ");
  read(0, buffer, 4096);
  my_second_q(buffer);
}
