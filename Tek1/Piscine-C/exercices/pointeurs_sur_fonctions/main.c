/*
** main.c for main in /home/pereni_j/test2
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed May 27 17:06:42 2015 joseph pereniguez
** Last update Wed May 27 17:51:27 2015 joseph pereniguez
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && s2[i])
    i++;
  if (!s1[i] && !s2[i])
    return (0);
  return (1);
}

char            *my_cd()
{
  printf("cd\n");
}

char            *my_env()
{
  printf("env\n");
}

char            *un_set_env()
{
  printf("unsetenv\n");
}

char            *set_env()
{
  printf("setenv\n");
}


int		main(int argc, char **argv)
{
  char		*tab[5];
  char		*(**ft)();
  int		i = 0;

  ft = malloc(sizeof(*ft) * 4);
  ft[0] = &my_cd;
  ft[1] = &my_env;
  ft[2] = &un_set_env;
  ft[3] = &set_env;

  tab[0] = "cd";
  tab[1] = "env";
  tab[2] = "unsetenv";
  tab[3] = "setenv";
  tab[4] = NULL;

  while (tab[i])
    {
      if (my_strcmp(tab[i], argv[1]) == 0)
	ft[i]();
      i++;
    }
}
