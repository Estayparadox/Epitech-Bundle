/*
** main.c for main in /home/pereni_j/rendu/CPE_2014_bsq
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan 16 16:07:28 2015 Pereniguez Joseph
** Last update Sun Jan 18 20:37:48 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "bsq.h"

int		check_error(int i)
{
  if (i == -1)
    my_putstr("[ERROR]: >map error<\n");
  else if (i == 1)
    my_putstr("[ERROR]: >open function does not work<\n");
  else if (i == 0)
    return (0);
  return (0);
}

int             check_file(char *str)
{

  if (str)
    {
      open(str, O_RDONLY);
      check_error(0);
    }
  else
    check_error(1);
  return (0);
}

int	main(int argc, char **argv)
{
  int	i;

  i = -1;
  if (argc != 2)
    {
      check_error(i);
    }
  else
    {
      check_file(argv[1]);
    }
  return (0);
}
