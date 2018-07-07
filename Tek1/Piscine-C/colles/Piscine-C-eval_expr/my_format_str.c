/*
** my_format_str.c for eval_expr in /home/pereni_j/Piscine-C-eval_expr/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include <stdlib.h>
#include "doop.h"
#include "include/my.h"

char	*my_new_minus(char *str, char *my_new_str, unsigned int i, unsigned int *j)
{
    my_new_str[*j] = ' ';
    my_new_str[*j + 1] = str[i];
    my_new_str[*j + 2] = ' ';
    my_new_str[*j + 3] = str[i + 1];
    if (str[i + 2] == '(')
    {
        my_strcat(&my_new_str[*j + 4], "1 * ");
        *j += 4;
    }
    return (my_new_str);
}

char	*my_new_op(char *str, char *my_new_str, unsigned int *i, unsigned int *j)
{
    if (*i == 0 && str[*i] == '-' && str[*i + 1] == '(')
    {
        my_strcat(&my_new_str[*j], "-1 * (");
        *j += 6;
        *i += 2;
    }
    else if (str[*i + 1] == '-')
    {
        my_new_str = my_new_minus(str, my_new_str, *i, j);
        *i += 2;
        *j += 4;
    }
    else
    {
        my_new_str[*j] = ' ';
        my_new_str[*j + 1] = str[*i];
        my_new_str[*j + 2] = ' ';
        *i += 1;
        *j += 3;
    }
    return (my_new_str);
}

char                *where_is_my_space(char *str)
{
    char		    *my_str;
    unsigned int	i;
    unsigned int	j;

    i = 0;
    j = 0;
    my_str = malloc(my_strlen(str));
    if (my_str == NULL)
        return (NULL);
    while (str[i] != 0)
    {
        while (str[i] != 0 && (str[i] == ' ' || str[i] == '\t'))
            i += 1;
        while (str[i] != 0 && str[i] != ' ' && str[i] != '\t')
        {
            my_str[j] = str[i];
            i += 1;
            j += 1;
        }
    }
    return (my_str);
}

char		        *my_str_powa(char *str)
{
    unsigned int	i;
    unsigned int	j;
    char		    *my_new_str;

    my_new_str = malloc(my_strlen(str) * 4);
    if (my_new_str == NULL)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i] != 0 && str[i + 1] != 0)
    {
        if (my_is_op(str[i]) && !(i > 0 && str[i - 1] == '('))
        {
            my_new_str = my_new_op(str, my_new_str, &i, &j);
        }
        else
        {
            my_new_str[j] = str[i];
            i += 1;
            j += 1;
        }
    }
    my_new_str[j] = str[i];
    my_new_str[j + 1] = 0;
    return (my_new_str);
}
