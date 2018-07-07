/*
** add.c for add in /home/pereni_j/Rendu/piscine_cpp_d02m/ex04
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Thu Jan  7 16:37:17 2016 pereniguez joseph
** Last update Sat Oct  1 11:57:51 2016 pereniguez joseph
*/

#include "castmania.h"

int	normal_add(int a, int b)
{
  int	i;

  i = a + b;
  return (i);
}

int	absolute_add(int a, int b)
{
  int	i;

  if (a < 0)
    a = a * (-1);
  if (b < 0)
    b = b * (-1);
  i = a + b;
  return (i);
}

void	exec_add(t_add *operation)
{
  if (operation->add_type == NORMAL)
    {
      operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
    }
  else if (operation->add_type == ABSOLUTE)
    {
      operation->add_op.res = absolute_add(operation->add_op.a, operation->add_op.b);
    }
}
