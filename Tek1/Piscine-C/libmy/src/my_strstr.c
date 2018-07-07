/*
** my_strstr.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    "../include/my.h"

char        *my_strstr(char * str , char const *to_find)
{
    int       i;
    int       j;
    char      *str1;

    i = 0;
    while (str[i] != '\0')
    {
        i = i + 1;
        j = 0;
        if (str[i] == str[j] && str[j] != '\0')
        {
            i = i + 1;
            str1 = &str[1];
            if (str[i] == str[j] && str[j] != '\0')
            {
                j = j + 1;
                return (str1);
            }
            else
                i = i + 1;
        }
    }
    return (str1);
}
