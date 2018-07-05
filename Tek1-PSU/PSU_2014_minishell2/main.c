/*
** main.c for main in /home/pereni_j/rendu/PSU_2014_minishell1
**
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jan 20 10:13:06 2015 Pereniguez Joseph
** Last update Sun Mar  8 17:49:46 2015 Pereniguez Joseph
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

  i = 0;
  while (i < 4096)
    {
      str[i] = 0;
      i = i + 1;
    }
  return (str);
}

int                     main(int argc, char **argv, char **env)
{
  char			*buffer;
  int			ret;

  argc = argc;
  buffer = malloc(sizeof(char)* 4096);
  buffer = my_memset(buffer);
  my_putstr("\033[32;01m~Thank you for not crash the Minishell2~\033[00m\n");
  while (1)
    {
      buffer = my_memset(buffer);
      my_putstr("\033[31;01m$> \033[00m");
      signal(SIGINT, control_c);
      buffer = my_memset(buffer);
      ret = read(0, buffer, 4096);
      if (ret == 0)
	{
	  my_putstr("\n\033[32;01m~Thank you for using the Minishell2~\033[00m\n");
	  exit(0);
	}
      buffer[ret - 1] = '\0';
      if (buffer[0] != '\0')
	call_funct(buffer, 0, argv, env);
    }
  return (0);
}
