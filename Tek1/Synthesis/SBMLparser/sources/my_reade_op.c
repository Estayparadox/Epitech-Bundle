/*
** my_reade_op.c for my_reader_op in /home/pereni_j/Rendu/SBMLparser/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Mon Jun 15 16:38:00 2015 joseph pereniguez
** Last update Wed Jun 17 10:46:45 2015 joseph pereniguez
*/

#include "sbmlparser.h"

int		check_op(char **tab, char *op)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if ((check_icompartment(tab, op, i)) == 0)
	{
	  my_compartment(tab, op);
	  return (0);
	}
      if ((check_ispecies(tab, op, i)) == 0)
	{
	  my_species(tab, op);
	  return (0);
	}
      if ((check_ireactan(tab, op, i)) == 0)
	{
	  my_reactan(tab, op);
	  return (0);
	}
      i++;
    }
  printf("Fichier incorrect\n");
  return (0);
}

void		my_checker_op(char *str, char *op)
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
      check_op(tab, op);
    }
}
