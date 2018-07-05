/*
** search_pipe.c for search_pipe in /home/pereni_j/rendu/PSU_2014_minishell2
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Feb 20 15:12:15 2015 Pereniguez Joseph
** Last update Sun Mar  8 16:24:02 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include "minishell.h"

void		check_pipe(char *buffer, int pid, char **argv, char **env)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (buffer[i] != '\n')
    {
      if (buffer[i] == '|' && buffer[i + 1] != ' ')
	my_putstr("\033[31;05mSyntax Error\033[00m\n");
      else if (buffer[i] == '|' && buffer[i - 1] != ' ')
	my_putstr("\033[31;05mSyntax Error\033[00m\n");
      else
	j = j + 1;
      i = i + 1;
    }
  if (j != 0)
    search_pipe(buffer, pid, argv, env);
}

int	search_sec_pipe(char *buffer, int i, char *s1)
{
  int	j;
  char	*s2;

  j = 0;
  s2 = malloc(sizeof(s2) * 4096);
  while (buffer[i] && buffer[i] != ' ')
    {
      s2[j] = buffer[i];
      i = i + 1;
      j = j + 1;
      if (buffer[i] == ' ' || buffer[i] == '\n')
	{
	  send_cat(s1, s2);
	  return (0);
	}
    }
  return (0);
}

int	search_pipe(char *buffer, int pid, char **argv, char **env)
{
  int	i;
  int	j;
  char	*s1;

  i = 0;
  j = 0;
  pid = pid;
  argv = argv;
  env = env;
  s1 = malloc(sizeof(char) * 4096);
  while (buffer[i] && buffer[i] != ' ')
    {
      s1[j] = buffer[i];
      i = i + 1;
      j = j + 1;
      if (buffer[i] == ' ' && buffer[i + 2])
	{
	  i = i + 3;
	  search_sec_pipe(buffer, i, s1);
	  return (0);
	}
    }
  return (0);
}
