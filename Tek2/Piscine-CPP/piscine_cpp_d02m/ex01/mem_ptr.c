/*
** mem_ptr.c for mem_ptr in /home/pereni_j/Rendu/piscine_cpp_d02m/ex01
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jan  7 09:50:43 2016 pereniguez joseph
** Last update Thu Jan  7 17:37:51 2016 pereniguez joseph
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mem_ptr.h"

void	add_str(char *str1, char *str2, char **res)
{
  char	*str;

  if ((str = malloc(strlen(str1) + strlen(str2))) == NULL)
    exit(0);
  str = strcat(str, str1);
  str = strcat(str, str2);
  *res = str;
}

void	add_str_struct(t_str_op *str_op)
{
  char	*str;

  if ((str = malloc(strlen(str_op->str1) + strlen(str_op->str2))) == NULL)
    exit(0);
  str = strcat(str, str_op->str1);
  str = strcat(str, str_op->str2);
  str_op->res = str;
} 
