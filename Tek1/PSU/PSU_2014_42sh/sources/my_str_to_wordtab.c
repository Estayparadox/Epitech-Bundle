/*
** my_str_to_wordtab.c for 42sh in /home/arrazo_p/semestre2/SystemeUnix/PSU_2014_minishell2
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Wed Feb 25 14:26:32 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:53:42 2015 Vatinelle Maxime
*/

#include "../42sh.h"

static int	nb_spaces(char *str, char c)
{
  int           i;
  int           count;

  i = 0;
  count = 1;
  while (str[i])
    {
      if (str[i] == c && str[i + 1] && str[i + 1] != c)
        count++;
      i++;
    }
  return (count + 1);
}

char	**my_str_to_wordtab(char *str, char c)
{
  int	i;
  char	**tab;
  int	y;
  int	nb;
  int	count;

  i = 0;
  count = 0;
  tab = xmalloc(sizeof(char *) * nb_spaces(str, c));
  while (str[i])
    {
      nb = i;
      y = 0;
      while (str[nb] && str[nb] != c)
        nb++;
      tab[count] = xmalloc(sizeof(char) * (nb - i + 1));
      while (i != nb)
        tab[count][y++] = str[i++];
      tab[count][y] = 0;
      tab[count + 1] = NULL;
      count++;
      i++;
    }
  return (tab);
}
