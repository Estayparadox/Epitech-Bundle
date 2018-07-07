/*
** SBMLparser.c for SBMLparser in /home/pereni_j/Rendu/SBMLparser/sources
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Mon Jun 15 10:00:14 2015 joseph pereniguez
** Last update Mon Oct  2 00:55:47 2017 pereniguez joseph
*/

#include "sbmlparser.h"

int		print_usage()
{
  printf("USAGE:\n\t./SBMLparser SBMLfile [-i id [-e]]\n");
  printf("DESCRIPTION:\n\tSBMLfileSBML file\n");
  printf("\t-i ID\tif of the compartment, reaction or product to be extracted\n\t\t(ignored if uncorrect)\n");
  printf("\t-e\tprint the equation if a reaction ID is given as argument\n\t\t(ignored otherwise)\n");
  exit(0);
}

int		main(int argc, char **argv)
{
  if (argc == 2)
    my_checker(argv[1]);
  else if (argc == 4)
    {
      if ((my_strcmp(argv[2], "-i")) == 0)
	my_checker_op(argv[1], argv[3]);
    }
  else if (argc == 5)
    {
      if ((my_strcmp(argv[2], "-i")) == 0 &&
	  (my_strcmp(argv[4], "-e")) == 0)
	my_checker_equation(argv[1], argv[3]);
      else
	printf("Fichier incorrect\n");
    }
  else
    printf("Fichier incorrect\n");
  return (0);
}
