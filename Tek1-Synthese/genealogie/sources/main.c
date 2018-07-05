/*
** main.c for main in /home/pereni_j/Rendu/genealogie/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jul  2 10:01:23 2015 joseph pereniguez
** Last update Fri Jul  3 17:07:36 2015 joseph pereniguez
*/

#include "genealogie.h"

int			main(int argc, char **argv)
{
  char			buffer[4096];
  int			ret;

  ret = read(0, buffer, 4096);
  buffer[ret] = '\0';
  if (argc == 3)
    {
      if (buffer[0] == '1')
	open_rep(argv[1], argv[2]);
      if (buffer[0] == '2')
	open_bart(argv[1], argv[2]);
      if (buffer[0] == '3')
	return (0);
      if (buffer[0] == '4')
	return (0);
      if (buffer[0] == '5')
	return (0);
      if (buffer[0] == '6')
	printf("cousin(e)s : aucun\n");
      if (buffer[0] == '7')
	printf("demi-frères et soeurs : aucun\n");
    }
  return (0);
}
