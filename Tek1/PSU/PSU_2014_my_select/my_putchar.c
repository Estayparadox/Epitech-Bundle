/*
** my_putchar.c for my_putchar in /home/pereni_j/rendu/PSU_2014_my_select
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jan  7 11:31:11 2015 Pereniguez Joseph
** Last update Sun Jan 11 15:38:41 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
