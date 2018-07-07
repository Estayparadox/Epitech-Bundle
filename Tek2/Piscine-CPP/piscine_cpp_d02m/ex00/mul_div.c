/*
** mul_div.c for mul_div in /home/pereni_j/Rendu/piscine_cpp_d02m/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jan  7 09:02:40 2016 pereniguez joseph
** Last update Thu Jan  7 09:49:22 2016 pereniguez joseph
*/

#include <stdio.h>
#include <stdlib.h>

void	add_mul_4param(int first, int second, int *add, int *mul)
{
  *add = first + second;
  *mul = first * second;
}

void	add_mul_2param(int *first, int *second)
{
  int	i = (*first);
  int	j = (*second);
  
  (*first) = i + j;
  (*second) = i * j;
}
