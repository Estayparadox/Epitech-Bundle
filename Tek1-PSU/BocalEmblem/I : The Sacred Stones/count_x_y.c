/*
** count_x_y.c for count_x_y in /home/kadri_j/BocalEmblem/The Sacred Stones
** 
** Made by Jade Kadri
** Login   <kadri_j@epitech.net>
** 
** Started on  Sat May 16 14:45:37 2015 Jade Kadri
** Last update Sat May 16 15:00:37 2015 Jade Kadri
*/

#include "strategic.h"

int             cpt_y(char **line)
{
  int           i;

  i = -1;
  while (line[i])
    i++;
  return (i);
}

int		cpt_x(char *str)
{
  int		cpt;
  int		i;
  int		x;

  cpt = 0;
  i = 0;
  x = 0;
  while (str[i])
    {
      if (str[i] == ' ' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
        cpt++;
      if (str[i] == '\n')
        {
          if (cpt >= x)
            x = cpt;
          cpt = 0;
        }
      i++;
    }
  return (x);
}
