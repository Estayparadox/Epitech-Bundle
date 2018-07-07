/*
** FASTAtools.c for FASTAtools in /home/pereni_j/Rendu/FASTAtools/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jun 24 09:50:32 2015 joseph pereniguez
** Last update Thu Jun 25 15:53:10 2015 joseph pereniguez
*/

#include "fastatools.h"

void		check_op(char *op, char *file)
{
  if (op[0] == '1')
    option_1(file);
  else if (op[0] == '2')
    option_2(file);
  else if (op[0] == '3')
    option_3(file);
  else if (op[0] == '5')
    printf("5\n");
  else if (op[0] == '6')
    printf("6\n");
  else if (op[0] == '7')
    printf("7\n");
  else
    printf("Usage : ./FASTAtools option [k]\n");
}

void		check_kmers(char *op, char *km, char *file)
{
  if (op[0] == '4')
    option_4(file, km);
  else
    printf("Usage : ./FASTAtools option [k]\n");
}

void		check_adn3(char **argv)
{
  char          buffer[4096];
  int		i;
  int		mark;

  i = 0;
  mark = 0;
  read(STDIN_FILENO, buffer, 4096);
  while (buffer[i])
    {
      if (buffer[i] == '>')
        mark++;
      i++;
    }
  if (mark < 2)
    printf("Le fichier doit contenir exactement 2 séquences.\n");
  else
    check_kmers(argv[1], argv[2], buffer);
}

void		check_adn(char **argv)
{
  char		buffer[4096];
  int		i;
  int		mark;

  i = 0;
  mark = 0;
  read(STDIN_FILENO, buffer, 4096);
  while (buffer[i])
    {
      if (buffer[i] == '>')
	mark++;
      i++;
    }
  if (mark < 2)
    printf("Le fichier doit contenir exactement 2 séquences.\n");
  else
    check_op(argv[1], buffer);
}

int		main(int argc, char **argv)
{
  if (argc == 2)
    check_adn(argv);
  else if (argc == 3)
    check_adn3(argv);
  else
    printf("Usage : ./FASTAtools option [k]\n");
  return (0);
}
