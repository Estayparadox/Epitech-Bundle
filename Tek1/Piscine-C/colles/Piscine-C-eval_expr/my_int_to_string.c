/*
** my_int_to_string.c for eval_expr in /home/pereni_j/Piscine-C-eval_expr/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    <stdlib.h>
#include    "include/my.h"
#include    "doop.h"

int	        my_size_int(int n)
{
    if (n < 10)
        return (1);
    else
        return (1 + my_size_int (n / 10));
}

char	    *my_decstr(char *str)
{
    int	    i;

    i = 1;
    while (str[i] != 0)
        i += 1;
    str[i + 1] = '\0';
    while (i > 0)
    {
        str[i] = str[i - 1];
        i -= 1;
    }
    str[0] = '-';
    return (str);
}

char	    *my_revstr_malus(char *str, char neg)
{
    int	    i;
    char	c;
    int	    count;

    i = 0;
    count = my_strlen(str);
    while (i < count / 2)
    {
        c = str[i];
        str[i] = str[count - i - 1];
        str[count - i - 1] = c;
        i += 1;
    }
    if (neg)
        return (my_decstr(str));
    return (str);
}

char        *my_int_to_string(int n)
{
    char	*str;
    int	    i;
    long	nbr;

    nbr = n < 0 ? -n : n;
    str = malloc(my_size_int(nbr) * sizeof(char) + 1);
    if (str == NULL)
        return (NULL);
    i = 0;
    while (nbr > 9)
    {
        str[i] = '0' + nbr % 10;
        nbr = nbr / 10;
        i += 1;
    }
    str[i] = '0' + nbr;
    my_revstr_malus(str, n < 0);
    return (str);
}
