/*
** main.c for main in /home/pereni_j/Rendu/projTester/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jun 18 09:54:51 2015 joseph pereniguez
** Last update Sat Jun 20 13:21:05 2015 joseph pereniguez
*/

#include "projtester.h"

int		main(int argc, char **argv)
{
  if (argc <= 2)
    printf("! Fichier mal formaté !\n");
  if (argc == 3)
    {
      if ((my_strcmp(argv[1], "echo")) == 0)
	my_checker(argv[2], argv);
      else if ((my_strcmp(argv[1], "projTester")) == 0)
        boucle_inf();
      else
	my_call_funct(argv[2], argv);
    }
  if (argc == 4)
    {
      if ((my_strcmp(argv[3], "-stats")) == 0)
	checker_tester(argv);
      else
	printf("! Fichier mal formaté !\n");
    }
  if (argc >= 5)
    o_finder(argv);
  return (0);
}
