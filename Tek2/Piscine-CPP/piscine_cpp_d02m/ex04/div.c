/*
** div.c for div in /home/pereni_j/Rendu/piscine_cpp_d02m/ex04
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Thu Jan  7 15:54:02 2016 pereniguez joseph
** Last update Sat Oct  1 12:04:24 2016 pereniguez joseph
*/

#include "castmania.h"

int	integer_div(int a, int b)
{
  int	i;

  if (b == 0)
    return (0);
  else
    i = a / b;
  return (i);
}

float	decimale_div(int a, int b)
{
  float	i;

  if (b)
    {
      i = (float)a / (float)b;
      return (i);
    }
  return (0);
}

void	exec_div(t_div *operation)
{
  if (operation->div_type == INTEGER)
    {
      ((t_integer_op*) operation->div_op)->res = integer_div(((t_integer_op*) operation->div_op)->a, ((t_integer_op*) operation->div_op)->b);
    }
  else if (operation->div_type == DECIMALE)
    {
      ((t_integer_op*) operation->div_op)->res = decimale_div(((t_integer_op*) operation->div_op)->a, ((t_integer_op*) operation->div_op)->b);
    }
}
