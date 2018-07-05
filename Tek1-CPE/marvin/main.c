/*
** marvin.c for marvin in /home/pereni_j/rendu/marvin
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Jan  3 09:47:29 2015 Pereniguez Joseph
** Last update Sun Jan  4 23:35:46 2015 georges valentin
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	main(int ac, char **av)
{
  check_param(av[1]);
  check_error(av[1]);
  if (ac < 2)
    {
      param(av[1]);
      if ((param(av[1])) == 0)
	{
	  var_type(av[1]);
          var_name(av[1]);
	}
      else if(param(av[1]) == 1)
	{
	  fonction1(av[1]);
	  fonction2(av[1]);
	  fonction3(av[1]);
	  fonction4(av[1]);
	}
      else if ((param(av[1])) == 1)
	{
	  var_type(av[1]);
	  var_name(av[1]);
	}
    }
  return (0);
}
