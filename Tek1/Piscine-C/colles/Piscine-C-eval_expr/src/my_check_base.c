/*
** my_check_base.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    "../include/my.h"

int	        my_check_base(char c, char *bdd)
{
    int     i;

    i = -1;
    while (bdd[++i])
        if (bdd[i] == c)
          return (1);
    return (0);
}
