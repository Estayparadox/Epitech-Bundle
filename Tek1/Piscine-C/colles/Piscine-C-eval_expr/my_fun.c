/*
** my_fun.c for eval_expr in /home/pereni_j/Piscine-C-eval_expr/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    <unistd.h>
#include    "doop.h"
#include    "include/my.h"

char	    my_is_num(char c)
{
  return (c >= '0' && c <= '9');
}

char	    my_is_op(char c)
{
  return (c == '-' || c == '+' || c == '/' || c == '*' || c == '%');
}
