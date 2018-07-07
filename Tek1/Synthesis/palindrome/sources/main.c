/*
** main.c for main in /home/pereni_j/Rendu/palindrome/sources
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Fri Jun 26 10:50:27 2015 joseph pereniguez
** Last update Mon Oct  2 11:42:02 2017 pereniguez joseph
*/

#include "palindrome.h"

int		print_usage()
{
  printf("USAGE:\n\t./palindrome number base\n");
  printf("DESCRIPTION:\n\tnumber\tinteger to be transformed (>= 0)\n");
  printf("\tbase\tbase in which the procedure will be executed (1<base<=10) [def: 10]\n");
  exit(0);
}

int		check_arg(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

int		check_v(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
        return (-1);
      i++;
    }
  return (0);
}

void		check_b(char **argv)
{
  if ((my_strcmp(argv[2], "0")) == 0 || my_strcmp(argv[2], "1") == 0)
    printf("argument invalide\n");
  else if ((my_strcmp(argv[2], "2")) == 0)
    first_check_base(argv[1], "01", argv[2]);
  else if ((my_strcmp(argv[2], "3"))== 0)
    first_check_base(argv[1], "012", argv[2]);
  else if ((my_strcmp(argv[2], "4"))== 0)
    first_check_base(argv[1], "0123", argv[2]);
  else if ((my_strcmp(argv[2], "5"))== 0)
    first_check_base(argv[1], "01234", argv[2]);
  else if ((my_strcmp(argv[2], "6"))== 0)
    first_check_base(argv[1], "012345", argv[2]);
  else if ((my_strcmp(argv[2], "7"))== 0)
    first_check_base(argv[1], "0123456", argv[2]);
  else if ((my_strcmp(argv[2], "8"))== 0)
    first_check_base(argv[1], "01234567", argv[2]);
  else if ((my_strcmp(argv[2], "9"))== 0)
    first_check_base(argv[1], "012345678", argv[2]);
  else if ((my_strcmp(argv[2], "10"))== 0)
    first_check(argv[1]);
  else
    printf("argument invalide\n");
}

int		main(int argc, char **argv)
{
  if (argc == 3)
    {
      if ((check_arg(argv[2])) == 0 && (check_v(argv[1])) == 0)
	check_b(argv);
      else
	{
	  printf("argument invalide\n");
	  return (0);
	}
    }
  else if ((argc == 2) && (my_strcmp(argv[1], "-h")) == 0)
    print_usage();
  else
    printf("argument invalide\n");
  return (0);
}
