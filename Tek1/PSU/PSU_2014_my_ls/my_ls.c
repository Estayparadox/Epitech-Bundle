/*
** list.c for list in /home/pereni_j/rendu/PSU_2014_my_ls
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sun Nov 30 15:58:49 2014 Pereniguez Joseph
** Last update Sun Nov 30 17:49:47 2014 Pereniguez Joseph
*/

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int		ls(char *directory)
{
  struct dirent	*d;
  DIR		*dir;
  
  if ((dir = opendir(directory)) == NULL)
    return (0);
  while ((d = readdir(dir)))
    {
      my_putstr(d->d_name);
      my_putstr("\t");
    }
  my_putstr("\n");
  closedir(dir);
}

int		ls_no_options(char *directory)
{
  struct dirent	*d;
  DIR		*dir;
  
  if ((dir = opendir(directory)) == NULL)
    return (0);
  while ((d = readdir(dir)))
    {
      if (d->d_name[0] != '.')
      my_putstr(d->d_name);
      my_putstr("\t");
    }
  my_putstr("\n");
  closedir(dir);
}

int		main(int ac, char **av)
{
  if (ac == 1)
    ls_no_options("./");
  else if (ac == 2 && av[1][0] == '-')
    {
      if (av[1][1] == 'a')
	ls("./");
    }
  else if (ac == 2 && av[1])
    ls(av[1]);
  else
    my_putstr("Input error");
}
