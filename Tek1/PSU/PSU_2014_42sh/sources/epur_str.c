/*
** epur_str.c for 42sh in /home/vatine_m/rendu/PSU_2014/PSU_2014_42sh/sources
** 
** Made by Vatinelle Maxime
** Login   <vatine_m@epitech.net>
** 
** Started on  Sun May 20 11:40:08 2015 Vatinelle Maxime
** Last update Sun May 24 14:50:36 2015 Vatinelle Maxime
*/

#include "../42sh.h"

char	*epur_str(char *str)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  if (!str)
    return (0);
  while (str[++i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  str[j] = str[i];
	  j++;
	  if (str[i + 1] == ' ' || str[i + 1] == '\t')
	    {
	      str[j] = ' ';
	      j++;
	    }
	}
    }
  str[j] = '\0';
  if (str[j - 1] != ' ')
    str = my_strcp(str, " ");
  return (str);
}
