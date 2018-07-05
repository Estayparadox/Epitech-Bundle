/*
** tools.c for tools in /home/pereni_j/Rendu/genealogie/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jul  2 18:20:26 2015 joseph pereniguez
** Last update Fri Jul  3 12:07:11 2015 joseph pereniguez
*/

#include "genealogie.h"

int			my_strlen(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int			my_strcmp(char *s1, char *s2)
{
  int			i;

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

char		*my_strcat(char *s1, char *s2)
{
  int		i;
  int		j;
  char		*s3;

  i = 0;
  j = 0;
  s3 = malloc(sizeof(s3) * 4096);
  while (s1[i] != '\0')
    {
      s3[i] = s1[i];
      i++;
    }
  while (s2[j] != '\0')
    s3[i++] = s2[j++];
  s3[i] = '\0';
  return (s3);
}
