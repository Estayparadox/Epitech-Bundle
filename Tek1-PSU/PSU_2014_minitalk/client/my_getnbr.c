/*
** my_getnbr.c for my_getnbr in /home/pereni_j/rendu/CPE_2014_Pushswap
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Dec 12 17:11:58 2014 Pereniguez Joseph
** Last update Sat Mar 21 10:45:17 2015 Pereniguez Joseph
*/

#include "my_client.h"

int	my_getnbr(char *str)
{
  int   nb;
  int   i;
  int   j;

  i = 0;
  j = 1;
  nb = 0;
  while (str[i] != 0)
    {
      if (str[i] >= '0' && str[i] <= '9')
        {
          nb = (nb * 10) + (str[i] - '0');
          i = i + 1;
        }
      if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
        {
          j = -j;
          i = i + 1;
        }
    }
  return (nb * j);
}
