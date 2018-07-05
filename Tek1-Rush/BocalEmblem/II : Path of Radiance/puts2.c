/*
** puts2.c for puts2 in /home/pereni_j/Rendu/BocalEmblem/II : Path of Radiance
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Sun May 17 11:35:26 2015 joseph pereniguez
** Last update Sun May 17 11:44:45 2015 joseph pereniguez
*/

#include "playradiance.h"

void            my_puterror(char *str)
{
  write (2, str, my_strlen(str));
}

void            *xmalloc(int len)
{
  void          *str;

  str = malloc(len);
  return (str);
}

int             my_getnbr(char *str)
{
  int           nbr;
  int           s;
  int           i;

  nbr = 0;
  i = 0;
  s = 1;
  while (str[i] != '\0')
    {
      if (str[i] == '-')
        s = s * -1;
      if (str[i] >= '0' && str[i] <= '9')
        {
          nbr = nbr * 10 + str[i] - '0';
          if (str[i + 1] < '0' || str[i + 1] > '9')
            return (nbr * s);
        }
      if (nbr < 0)
        return (0);
      i = i + 1;
    }
  return (nbr + s);
}
