/*
** my_str.c for eval_expr in /home/pereni_j/Piscine-C-eval_expr/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include <stdlib.h>
#include "include/my.h"
#include "doop.h"

char	    *my_sub_string(char *str, int begin, int end)
{
    char	*my_sub;
    int	    i;

    i = 0;
    my_sub = malloc((end - begin) * sizeof(char));
    begin += 1;
    while (begin < end)
    {
        my_sub[i] = str[begin];
        begin += 1;
        i += 1;
    }
    my_sub[i] = '\0';
    return (my_sub);
}

char	    *my_start_string(char *str, char *start, char *nbr, int begin)
{
    int	    i;
    int	    j;

    i = 0;
    while (str[i] != 0 && i < begin)
    {
        start[i] = str[i];
        i += 1;
    }
    start[i] = ' ';
    j = 0;
    i += 1;
    while (nbr[j] != 0)
    {
        start[i] = nbr[j];
        i += 1;
        j += 1;
    }
    start[i + 1] = '\0';
    return (start);
}

char	    *my_newstring(char *str, char *nbr, int begin, int end)
{
    char	*my_start;
    char	*my_end;
    int	    i;

    my_start = malloc((my_strlen(str) + my_strlen(nbr)) * sizeof(char) + 3);
    my_start = my_start_string(str, my_start, nbr, begin);
    my_end = malloc(my_strlen(str));
    i = 0;
    while (str[end + i + 1] != 0)
    {
        my_end[i] = str[end + i + 1];
        i += 1;
    }
    my_end[i] = '\0';
    return (my_strcat(my_start, my_end));
}
