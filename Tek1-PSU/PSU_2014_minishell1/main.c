/*
** main.c for main in /home/pereni_j/rendu/PSU_2014_minishell1
**
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jan 20 10:13:06 2015 Pereniguez Joseph
** Last update Sun Feb  1 11:56:13 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include "minishell.h"

char			*my_memset(char *str)
{
  int			i;

  i = -1;
  while (i <= 4096)
    {
      i = i + 1;
      str[i] = 0;
    }
  return (str);
}

int                     main(int argc, char **argv, char **env)
{
  char			*buffer;
  int			pid;

  argc = argc;
  pid = 0;
  buffer = malloc(sizeof(char)* 4096);
  buffer = my_memset(buffer);
  my_putstr("\033[32;01mThank you not crash the Minishell1\033[00m\n");
  while (1)
    {
      buffer = my_memset(buffer);
      my_putstr("\033[31;01m$> \033[00m");
      signal(SIGINT, control_c);
      read(0, buffer, 4096);
      search_ls(buffer, pid, argv, env);
    }
  return (0);
}
