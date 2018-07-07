/*
** my_str.c for colle2 in /home/pereni_j/Piscine-C-colles-Semaine_02/subject5/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    <stdlib.h>
#include    "my.h"

int         my_while(char *str, int i, int max, int size)
{
    if (size != - 1)
    {
        while (i < max)
        {
            str[size - i - 1] = ' ';
            i += 1;
        }
    }
    else
    {
        while (i < max)
        {
            str[i] = ' ';
            i += 1;
        }
    }
    return (i);
}

char        *my_revnewstr(char *str, int pos_star, int pos_word, int size)
{
    int     i;
    char    *my_str;
    int     j;

    my_str = malloc(size);
    i = 0;
    i = my_while(my_str, 0, pos_star + 1, size);
    my_str[size - i - 1] = '*';
    i += 1;
    i = my_while(my_str, i, pos_word + 1, size);
    j = 0;
    while (str[j] != '\0')
    {
        my_str[size - i - 1] = str[my_strlen(str) - j - 1];
        j += 1;
        i += 1;
    }
    i = my_while(my_str, i, size, size);
    my_str[size - 2] = '|';
    my_str[size - 1] = '\0';
    return (my_str);
}

char        *my_newstr(char *str, int pos_star, int pos_word, int size)
{
    int     i;
    char    *my_str;
    int     j;

    my_str = malloc(size);
    i = 0;
    i = my_while(my_str, i, pos_star - 1, - 1);
    my_str[i] = '*';
    i += 1;
    i = my_while(my_str, i, pos_word - 1, - 1);
    j = 0;
    while (str[j] != '\0')
    {
        my_str[i] = str[j];
        j += 1;
        i += 1;
    }
    i = my_while(my_str, i, size - 1, - 1);
    my_str[size - 2] = '|';
    my_str[size - 1] = '\0';
    return (my_str);
}
