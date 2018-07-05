/*
** main.c for main in /home/pereni_j/Rendu/BocalEmblem/The Sacred Stones
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat May 16 10:49:34 2015 joseph pereniguez
** Last update Sun May 17 16:45:35 2015 Jade Kadri
*/

#include "strategic.h"

void		my_puterror(char *str)
{
  write (2, str, my_strlen(str));
}

void		verify_map(char *file)
{
  int		fd;
  char		buffer[4096];

  if ((fd = open(file, O_RDONLY)) == -1)
    my_puterror("File doesn't exist!\n");
  else
    {
      my_putstr("File is existing\n");
      read(fd, buffer, 4095);
      buffer[4096] = '\0';
      if (buffer[0] == '\0' || buffer == NULL)
	{
	  my_puterror("File is empty!\n");
	  return;
	}
      verify_extension(file);
      verify_size(file, buffer);
      if (verify_double(buffer) == -1)
	my_puterror("Invalid map file, double soldier in file!\n");
      else if (verify_double(buffer) == 0)
	if (verify_soldiers(buffer) == -1)
	  my_puterror("Invalid map file, bad wall or invalid soldier in file!\n");
    }
}

int		main(int ac, char **av)
{
  int		i;

  i = 1;
  if (ac < 2)
    {
      my_puterror("No file passed in parameter!\n");
      return (0);
    }
  while (av[i])
    {
      my_putstr("- -");
      my_putstr(av[i]);
      my_putstr("- -\n");
      verify_map(av[i]);
      my_putstr("- -end- -\n");
      i++;
    }
  return (0);
}
