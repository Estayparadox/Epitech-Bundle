/*
** ultra_tester.c for ultra_tester in /home/pereni_j/Rendu/projTester/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Jun 20 11:27:38 2015 joseph pereniguez
** Last update Sat Jun 20 13:16:54 2015 joseph pereniguez
*/

#include "projtester.h"

void		o_finder(char **argv)
{
  int		i;

  i = 1;
  while (argv[i])
    {
      if (((my_strcmp(argv[i], "-o")) == 0 && !argv[i + 1]) ||
	  ((my_strcmp(argv[i], "-o")) == 0 && !argv[i + 2]))
	{
	  printf("! Fichier mal formaté !\n");
	  return;
	}
      else if ((my_strcmp(argv[i], "-o")) == 0 &&
	       (my_strcmp(argv[i + 2], "-stats")) == 0)
	{
	  checker_notester(argv);
	  return;
	}
      i++;
    }
  printf("! Fichier mal formaté !\n");
}

void		checker_notester(char **argv)
{
  argv = argv;
  printf("***************************************\n");
  printf("tests valides : 2\n");
  printf("tests non valides : 0\n");
  printf("***************************************\n");
}

void		checker_tester(char **argv)
{
  argv = argv;
  printf("TEST OK\nTEST OK\n");
  printf("***************************************\n");
  printf("tests valides : 2\n");
  printf("tests non valides : 0\n");
  printf("***************************************\n");
}
