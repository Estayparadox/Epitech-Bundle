/*
** my_reader.c for my_reader in /home/pereni_j/Rendu/SBMLparser/sources
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Mon Jun 15 10:12:28 2015 joseph pereniguez
** Last update Mon Oct  2 00:54:49 2017 pereniguez joseph
*/

#include "sbmlparser.h"

void		extension_checker(char *str)
{
  int		len;

  len = my_strlen(str);
  if (str[len - 1] != 'l' && str[len - 2] != 'm' &&
      str[len - 3] != 'b' && str[len - 4] != 's' &&
      str[len - 5] != '.')
    printf("Fichier incorrect\n");
  else if (str[len -1] == 'l' && str[len - 2] == 'm' &&
	   str[len - 3] == 'b' && str[len - 4] == 's' &&
	   str[len -5] == '.')
    {
    }
}

void		my_checker(char *str)
{
  int		fd;
  char		buffer[20480];
  char		**tab;

  if ((fd = open(str, O_RDONLY)) == -1)
    if ((my_strcmp(str, "-h")) == 0)
      print_usage();
    else
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
      tab = my_strtowordtab2(buffer);
      my_baliser(tab);
    }
}
