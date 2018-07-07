/*
** ptr_tricks.c for ptr_tricks in /home/pereni_j/Rendu/Tek2-Piscine/piscine_cpp_d02m/ex05
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Sat Oct  1 12:05:10 2016 pereniguez joseph
** Last update Sat Oct  1 12:07:13 2016 pereniguez joseph
*/

#include "ptr_tricks.h"

int		get_array_nb_elem(int *ptr, int *ptr2)
{
  return (ptr2 - ptr1);
}

t_whatever	*get_struct_ptr(int *member_ptr)
{
  t_whatever	base;

  return (void*)member_ptr - ((void*)&base.member - (void*)&base);
}
