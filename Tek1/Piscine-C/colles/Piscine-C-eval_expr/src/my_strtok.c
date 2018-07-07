/*
** my_strtok.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    <stdlib.h>
#include    "../include/my.h"

int	        my_getword(char *str, char *bdd, int flag)
{
    int     i;
    int     word;

    i = -1;
    word = 0;
    while (str[++i])
    {
        if (i == 0 && my_check_base(str[i], bdd) == flag)
            word++;
        if (i > 0 && (my_check_base(str[i], bdd) == flag &&
            my_check_base(str[i - 1], bdd) != flag))
        word++;
    }
    return (word);
}

int	        my_getchar(char *str, char *bdd, int *k, int flag)
{
    int     letter;
    int     i;

    letter = 0;
    while (my_check_base(str[*k], bdd) != flag)
        *k = *k + 1;
    i = *k;
    while (my_check_base(str[i], bdd) == flag && str[i] != '\0')
    {
        i++;
        letter++;
    }
    return (letter);
}

char	    *my_putword(char *str, char *bdd, int *k, int flag)
{
    char      *word;
    int       len;
    int       i;

    i = 0;
    len = my_getchar(str, bdd, k, flag) + 1;
    word = malloc(len * sizeof(*word));
    while (my_check_base(str[*k], bdd) == flag && str[*k] != '\0')
    {
        word[i] = str[*k];
        i++;
        *k = *k + 1;
    }
    word[i] = '\0';
    return (word);
}

char	    **my_strtok(char *str, char *bdd, int flag)
{
    char      **tab;
    int       len;
    int       i;
    int       k;

    k = 0;
    i = 0;
    len = my_getword(str, bdd, flag) + 1;
    tab = malloc(len * sizeof(*tab));
    while (i < (len - 1))
    {
        tab[i] = my_putword(str, bdd, &k, flag);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}
