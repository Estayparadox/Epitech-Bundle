/*
** my_parenth.c for eval_expr in /home/pereni_j/Piscine-C-eval_expr/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "doop.h"
#include "include/my.h"

int	    anyparent(char *str)
{
    if (str[0] == '(')
        return (1);
    else if (str[0] == 0)
        return (0);
    else
        return (anyparent(&str[1]));
}

int	    backparent(char *str)
{
    if (str[0] == 0 || str[0] == ')')
        return (0);
    else
        return (1 + backparent(&str[1]));
}

int	    firstparent(char *str, int i)
{
    if (str[i] == '(' || i == 0)
        return (i);
    else
        return (firstparent(str, i - 1));
}
