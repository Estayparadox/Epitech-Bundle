/*
** my_puts.c for my_puts in /home/pereni_j/rendu/PSU_2014_minishell1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jan 20 10:16:37 2015 Pereniguez Joseph
** Last update Fri Jan 30 15:45:05 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

int	my_call_putchar(int i)
{
  my_putchar(i);
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  exit(0);
}
