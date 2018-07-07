/*
** doop.c for eval_expr in /home/pereni_j/Piscine-C-eval_expr/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    "include/my.h"
#include    "doop.h"

t_opp	    g_opptab[] = {{"+", &my_add}, {"-", &my_sub}, {"/", &my_div},
                        {"*", &my_mul}, {"%", &my_mod}, {"", &my_usage}};

int	    my_own_strcmp(char *str1, char *str2)
{
    int	i;

    i = 0;
    while (str1[i] != 0 && str2[i] != 0 && str1[i] == str2[i])
        i += 1;
    return (!(str2[i] == 0 || str1[i] == 0));
}

int	    find_my_op(char op)
{
    int	i;

    i = 0;
    while (i < 5 && g_opptab[i].str[0] != op)
        i += 1;
    return (i);
}

int	    my_usage(int a, int b)
{
    int	i;

    (void)a;
    (void)b;
    i = 0;
    my_putstr("error: only [ ");
    while (i < 5)
    {
        my_putstr(g_opptab[i].str);
        my_putchar(' ');
        i += 1;
    }
    my_putstr("] are supported");
    return (0);
}

int	    my_calc(int a, int b, char op)
{
    int	i;

    i = find_my_op(op);
    return (g_opptab[i].fun(a, b));
}
