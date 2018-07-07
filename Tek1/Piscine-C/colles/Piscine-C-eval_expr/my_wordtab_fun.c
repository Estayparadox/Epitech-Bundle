/*
** my_wordtab_fun.c for eval_expr in /home/pereni_j/Piscine-C-eval_expr/
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

char    my_is_alphanumeric(int i, char *str)
{
    if (str[i] >= 'a' && str[i] <= 'z')
        return (1);
    if (str[i] >= 'A' && str[i] <= 'Z')
        return (1);
    if (str[i] >= '0' && str[i] <= '9')
        return (1);
    if (str[i] == '-' || str[i] == '+')
        return (1);
    if (str[i] == '/' || str[i] == '*')
        return (1);
    if (str[i] == '%')
        return (1);
    return (0);
}

int	    my_size_to_tab(char *str)
{
    int	i;
    int	count;

    i = 0;
    count = 0;
    while (str[i] != '\0')
    {
        if (my_is_alphanumeric(i, str))
        {
            while (str[i] != '\0' && my_is_alphanumeric(i, str))
                i += 1;
            count += 1;
        }
        i += 1;
    }
    return (count);
}

int	    my_answer(char **arr, char *str, int i, int count)
{
    int	j;

    j = 0;
    while (str[i] != '\0' && my_is_alphanumeric(i, str))
    {
        arr[count][j] = str[i];
        i += 1;
        j += 1;
    }
    arr[count][j] = '\0';
    return (i);
}

char	    **my_str_to_wordtab(char *str)
{
    char	**arr;
    int	    i;
    int	    count;

    count = 0;
    i = 0;
    if (str == NULL)
        return (NULL);
    arr = malloc(my_size_to_tab(str) * sizeof(str));
    if (arr == NULL)
        return (NULL);
    while (str[i] != '\0')
    {
        if (my_is_alphanumeric(i, str))
        {
            arr[count] = malloc(sizeof(*str));
            i = my_answer(arr, str, i, count);
            count += 1;
            i -= 1;
        }
        i += 1;
    }
    arr[count] = 0;
    return (arr);
}

char	    **my_sub_arr(char **arr, int begin, char *nbr)
{
    char	**my_arr;
    int	    i;

    my_arr = arr;
    i = 0;
    while (i < begin)
    {
        my_arr[i] = arr[i];
        i += 1;
    }
    my_arr[i] = nbr;
    i += 1;
    while (arr[i + 2] != 0)
    {
        my_arr[i] = arr[i + 2];
        i += 1;
    }
    my_arr[i] = 0;
    arr = my_arr;
    return (my_arr);
}
