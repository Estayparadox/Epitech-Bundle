/*
** match.h for match-nmatch in /home/pereni_j/match-nmatch/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include <stdlib.h>

char	*my_check_letter(char *str, char c)
{
    int	i;
    int	pos;

    i = 0;
    pos = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            pos = i;
        i += 1;
    }
    return (&str[pos]);
}

char    match(char *s1, char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (0);
    if (s2[0] == '*')
    {
        while (s2[0] == '*')
            s2 = &s2[1];
        if (s2[0] == '\0') return (1);
            while (s1[0] != '\0' && s1[0] != s2[0])
                s1 = &s1[1];
        s1 = my_check_letter(s1, s2[0]);
        return (match(s1, s2) && s1[0] != '\0');
    }
    else if (s2[0] == '\0' || s1[0] == '\0')
        return (s2[0] == s1[0]);
    else if (s2[0] == s1[0] || s2[0] == '?')
        return (match(&s1[1], &s2[1]));
    else
        return (0);
}
