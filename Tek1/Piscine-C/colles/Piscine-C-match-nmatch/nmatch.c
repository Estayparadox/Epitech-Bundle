/*
** nmatch.h for match-nmatch in /home/pereni_j/match-nmatch/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include <stdlib.h>

int	    nmatch_rec(char *s1, char *s2)
{
    if (s2[0] == '*')
    {
        if (s1[0] != 0)
            return (nmatch_rec(&s1[1], s2) + nmatch_rec(s1, &s2[1]));
        if (s1[0] == 0)
            return (nmatch_rec(s1, &s2[1]));
    }
    if (s1[0] == s2[0])
    {
        if (s1[0] != 0)
            return (nmatch_rec(&s1[1], &s2[1]));
        if (s1[0] == '\0')
            return (1);
    }
    return (0);
}

int	    nmatch(char *s1, char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (0);
    return (nmatch_rec(s1, s2));
}
