/*
** main.c for eval_expr in /home/pereni_j/Piscine-C-eval_expr/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    <stdlib.h>
#include    "doop.h"
#include    "include/my.h"

char	*operation(char **arr)
{
    int	nbr;
    int	j;

    while (arr[1] != 0)
    {
        j = 1;
        while (arr[j] != 0 && arr[j][0] != '*' && arr[j][0] != '/'
            && arr[j][0] != '%')
        j += 1;
        if (arr[j] != 0)
        {
            nbr = my_calc(my_getnbr(arr[j - 1]),
            my_getnbr(arr[j + 1]), arr[j][0]);
            arr =  my_sub_arr(arr, j - 1, my_int_to_string(nbr));
        }
        else
        {
            nbr = my_calc(my_getnbr(arr[0]), my_getnbr(arr[2]), arr[1][0]);
            arr = my_sub_arr(arr, 0, my_int_to_string(nbr));
        }
    }
    return (arr[0]);
}

char	    *what_operation(char *str, int begin, int end, char parenth)
{
    char	**arr;
    char	*my_str;

    if (parenth)
        arr = my_str_to_wordtab(my_sub_string(str, begin, end));
    else
        arr = my_str_to_wordtab(str);
    my_str = operation(arr);
    if (parenth)
        return (my_newstring(str, my_str, begin, end));
    else
        return (my_str);
}

int	    eval_expr(char *str)
{
    int	i;

    str = where_is_my_space(str);
    str = my_str_powa(str);
    if (str == NULL)
    {
        my_putstr("Error: Malloc");
        return (0);
    }
    while (anyparent(str))
    {
        i = backparent(str);
        str = what_operation(str, firstparent(str, i), i, anyparent(str));
    }
    str = what_operation(str, 0, my_strlen(str), 0);
    return (my_getnbr(str));
}

int	    main(int ac, char **av)
{
    if (ac > 1)
    {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
    }
    return (0);
}
