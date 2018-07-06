/*
** the_grid.c for the_grid in /home/pereni_j/Colle_6
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jun  2 18:45:18 2015 joseph pereniguez
** Last update Tue Jun  2 21:22:34 2015 joseph pereniguez
*/

#include "my_boogle.h"

void            print_line4(char *str)
{
  int   j;

  j = 12;
  my_putstr("| ");
  while (j != 16)
    {
      my_putchar(str[j]);
      my_putstr(" ");
      j++;
    }
  my_putstr("|\n");
}

void            print_line3(char *str)
{
  int   j;

  j = 8;
  my_putstr("| ");
  while (j != 12)
    {
      my_putchar(str[j]);
      my_putstr(" ");
      j++;
    }
  my_putstr("|\n");
}

void            print_line2(char *str)
{
  int   j;

  j = 4;
  my_putstr("| ");
  while (j != 8)
    {
      my_putchar(str[j]);
      my_putstr(" ");
      j++;
    }
  my_putstr("|\n");
}

void		print_line1(char *str)
{
  int		j;

  j = 0;
  my_putstr("| ");
  while (j != 4)
    {
      my_putchar(str[j]);
      my_putstr(" ");
      j++;
    }
  my_putstr("|\n");
}

void		print_grid(char *str)
{
  my_putstr("+---------+\n");
  print_line1(str);
  print_line2(str);
  print_line3(str);
  print_line4(str);
  my_putstr("+---------+\n");
}
