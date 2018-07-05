/*
** search_more.c for search_more in /home/pereni_j/rendu/PSU_2014_minishell2
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Feb  5 10:43:54 2015 Pereniguez Joseph
** Last update Sun Mar  8 15:50:09 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include "minishell.h"

void		check_space(char *buffer, int pid, char **argv, char **env)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (buffer[i] != '\n')
    {
      i = i + 1;
      if (buffer[i] == ';' && buffer[i + 1] != ' ')
	my_putstr("\033[31;05mSyntax Error\033[00m\n");
      else if (buffer[i] == ';' && buffer[i - 1] != ' ')
	my_putstr("\033[31;05mSyntax Error\033[00m\n");
      else
	j = 1;
    }
  if (j == 1)
    search_inform(buffer, pid, argv, env);
}

int		search_inform(char *buffer, int pid, char **argv, char **env)
{
  int		i;
  int		j;
  char		*str;

  i = 0;
  j = 0;
  str = malloc(sizeof(str) * 4096);
  while (buffer[i] != ' ' || buffer[i] != '\n')
    {
      str[j] = buffer[i];
      i = i + 1;
      j = j + 1;
      if (buffer[i] == ' ')
	{
	  str[j] = '\n';
	  search_ls(str, pid, argv, env);
	  str = my_memset(str);
	  i = i + 3;
	  j = 0;
	}
      else if (buffer[i] == '\n')
	{
	  str[j] = buffer[i];
	  search_ls(str, pid, argv, env);
	  return (0);
	}
    }
  return (0);
}

int		search_pv(char *buffer)
{
  int		i;
  int		j;
  int		k;

  k = 0;
  i = 0;
  j = 0;
  while (buffer[i] != '\n')
    {
      if (buffer[i] == ';')
	j = j + 1;
      if (buffer[i] == '|')
	k = k + 1;
      if (buffer[i] == '\0')
	buffer[i] = '\n';
      else
	i = i + 1;
    }
  if (j == 0 && k == 0)
    return (-1);
  else if (j != 0 && k == 0)
    return (0);
  else if (k != 0 && j == 0)
    return (1);
  return (42);
}

void            call_funct(char *buffer, int pid, char **argv, char **env)
{
  if (search_pv(buffer) == 0)
    check_space(buffer, pid, argv, env);
  else if (search_pv(buffer) == -1)
    search_ls(buffer, pid, argv, env);
  else if (search_pv(buffer) == 1)
    check_pipe(buffer, pid, argv, env);
}
