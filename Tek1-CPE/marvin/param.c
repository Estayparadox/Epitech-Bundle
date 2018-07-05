 /*
** funct.c for funct.c in /home/pereni_j/rendu/marvin
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Jan  3 09:52:13 2015 Pereniguez Joseph
** Last update Sun Jan  4 22:21:25 2015 georges valentin
*/

#include <unistd.h>
#include "my.h"

int	param(char *str)
{
  int	i;
  int	op;
  int	cl;

  i = 0;
  op = 0;
  cl = 0;
  
  while (str[i])
    {
      if (str[i] == '(')
	op = op + 1;
      if (str[i] == ')')
	cl = cl + 1;
      i = i + 1;
    }
  return(op);
}
