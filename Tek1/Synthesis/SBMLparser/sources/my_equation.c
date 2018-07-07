/*
** my_equation.c for my_equation in /home/pereni_j/Rendu/SBMLparser/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jun 16 17:37:05 2015 joseph pereniguez
** Last update Wed Jun 17 11:20:13 2015 joseph pereniguez
*/

#include "sbmlparser.h"

int		check_param(char **tab, char *op)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if ((my_strcmp(tab[i], op)) == 0 &&
	  (my_strcmp(tab[i - 1], "id")) == 0 &&
	  (my_strcmp(tab[i + 1], "listOfReactants")) == 0)
	{
	  if ((check_reverse(tab, i)) == -1)
	    printf("Fichier incorrect");
	}
      if ((my_strcmp(tab[i], op)) == 0 &&
          (my_strcmp(tab[i - 1], "id")) == 0 &&
          (my_strcmp(tab[i + 1], "listOfReactants")) != 0)
	{
	  check_op(tab, op);
	  return (0);
	}
      i++;
    }
  printf("Fichier incorrect\n");
  return (0);
}

void		my_checker_equation(char *str, char *op)
{
  int		fd;
  char		buffer[20480];
  char		**tab;

  if ((fd = open(str, O_RDONLY)) == -1)
    printf("Fichier incorrect\n");
  else
    {
      read(fd, buffer, 4096);
      if (buffer[0] == '\0' || buffer == NULL)
        {
          printf("Fichier incorrect\n");
          return;
        }
      extension_checker(str);
      tab = my_strtowordtab_synthese(buffer);
      check_param(tab, op);
    }
}
