/*
** white_rabbit.c for ex00 in /home/pereni_j/Rendu/piscine_cpp_d01/ex00
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jan  6 10:15:30 2016 pereniguez joseph
** Last update Wed Jan  6 13:18:48 2016 pereniguez joseph
*/

#include <stdlib.h>
#include <stdio.h>

int	follow_the_white_rabbit(void)
{
  int	res = 0;
  int	dice = 0;

  while (42)
    {
      dice = random() % 38;
      res = res + dice;
      if (res == 421 || res == 591)
	{
	  printf("LAPIN !!!\n");
	  return (res);
	}
      if ((res == 146 && dice > 24) || (res == 78 && dice > 24) ||
	  (dice > 24 && (res % 8) == 0))
	printf("derriere\n");
      else
	{
	  if (dice == 4 || dice == 5 || dice == 6 || dice == 17 || dice == 18 || dice == 19 || 
	      dice == 20 || dice == 21 || dice == 28)
	    printf("gauche\n");
	  if (dice == 13 || dice == 34 || dice == 35 || dice == 36)
	    printf("droite\n");
	  if (dice == 10 || dice == 15 || dice == 23)
	    printf("devant\n");
	  if (dice == 1 || dice == 37)
	    {
	      printf("LAPIN !!!\n");
	      return (res);
	    }
	}
    }
}
