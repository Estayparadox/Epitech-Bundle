/*
** my_puts.c for my_puts in /home/pereni_j/Rendu/projTester/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jun 18 11:32:03 2015 joseph pereniguez
** Last update Thu Jun 18 17:59:13 2015 joseph pereniguez
*/

#include "projtester.h"

char		*str_cat(char *s1, char *s2)
{
  int           i;
  int           j;
  char          *s3;

  i = 0;
  j = 0;
  s3 = malloc(sizeof(char) * 4096);
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

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      putchar(str[i]);
      i++;
    }
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int     my_strcmp(char *s1, char *s2)
{
  int   i;

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
