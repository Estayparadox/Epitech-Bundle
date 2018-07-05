/*
** prerequis.c for prerequis in /home/pereni_j/Rendu/genealogie
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jul  2 09:15:47 2015 joseph pereniguez
** Last update Thu Jul  2 13:31:07 2015 joseph pereniguez
*/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int              cmpstringp(const void *p1, const void *p2)
{
  return strcmp(* (char * const *) p1, * (char * const *) p2);
}

int			my_files_synthese(char *str)
{
  struct dirent		*d;
  DIR			*dir;
  char			**tab;
  int			i;

  i = 0;
  tab = malloc(sizeof(char *) * 100);
  if ((dir = opendir(str)) == NULL)
    return (0);
  while ((d = readdir(dir)))
    {
      if (d->d_name[0] != '.')
	{
	  tab[i] = d->d_name;
	  i++;
	}
    }
  qsort(tab, i, sizeof(char *), cmpstringp);
  i = 0;
  while (tab[i])
    {
      printf("%s\n", tab[i]);
      i++;
    }
  closedir(dir);
}
