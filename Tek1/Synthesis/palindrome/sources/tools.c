/*
** tools.c for tools in /home/pereni_j/Rendu/palindrome/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jun 26 10:40:48 2015 joseph pereniguez
** Last update Fri Jun 26 15:58:16 2015 joseph pereniguez
*/

#include "palindrome.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char            *rev_str(char *str)
{
  int           i;
  int           j;
  int           len;
  char          *copy;

  i = 0;
  j = 0;
  copy = malloc(sizeof(char) * (my_strlen(str)));
  len = my_strlen(str) - 1;
  while (str[i])
    {
      if (str[i] == ' ')
        i++;
      else
        copy[j++] = str[len - i++];
    }
  return (copy);
}

int		my_atoi(char *str)
{
  int		val;
  val = 0;
  while (*str)
    {
      if (*str >= '0' && *str <= '9')
        {
          val *= 10;
          val += *str - '0';
        }
      else
        return (val);
      str++;
    }
  return (val);
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] < s1[i])
        return (-1);
      else if (s1[i] > s2[i])
	return (1);
      i = i + 1;
    }
  if (s1[i] < s2[i])
    return (-1);
  else if (s1[i] > s2[i])
    return (1);
  return (0);
}
