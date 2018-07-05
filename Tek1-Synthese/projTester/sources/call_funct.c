/*
** call_funct.c for call_funct in /home/pereni_j/Rendu/projTester/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jun 19 11:45:24 2015 joseph pereniguez
** Last update Fri Jun 19 15:09:06 2015 joseph pereniguez
*/

#include "projtester.h"

void		funct_noresult(char **tab, char **argv)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if ((my_strcmp(tab[i], "ENTREE")) == 0 &&
	  tab[i + 1])
	send_to_exec(argv[1], tab[i + 1]);
      i++;
    }
}

void		funct_result()
{
  printf("TEST OK\n");
}

int		find_result(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if ((my_strcmp(tab[i], "RES")) == 0)
	return (-1);
      i++;
    }
  return (0);
}

int		call_checkop(char **tab, char **argv)
{
  if ((check_arg(tab)) == -1 ||
      (check_arg(tab)) == 0)
    return (-1);
  else
    {
      if ((find_result(tab)) == 0)
	funct_noresult(tab, argv);
      if ((find_result(tab)) == -1)
	funct_result();
    }
  return (0);
}

void		my_call_funct(char *file, char **argv)
{
  int           fd;
  char          buffer[4096];
  char          **tab;
  int           ret;

  argv = argv;
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      printf("! Fichier mal formaté !\n");
      return;
    }
  ret = read(fd, buffer, 4096);
  buffer[ret] = 0;
  if (buffer[0] == '\0' || buffer == NULL)
    {
      printf("! Fichier mal formaté !\n");
      return;
    }
  tab = my_strtowordtab(buffer);
  call_checkop(tab, argv);
}
