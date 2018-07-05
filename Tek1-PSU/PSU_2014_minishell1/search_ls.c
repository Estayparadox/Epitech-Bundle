/*
** search_ls.c for search_ls in /home/pereni_j/rendu/PSU_2014_minishell1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jan 20 14:55:40 2015 Pereniguez Joseph
** Last update Sun Feb  1 15:15:18 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

void	search_ls(char *buffer, int pid, char **argv, char **env)
{
  if (buffer[0] == 'l' && buffer[1] == 's' && buffer[2] == '\n')
    {
      if (fork() == 0)
	{
	  execve("/bin/ls", argv, env);
	}
      else
	wait (0);
    }
  else
    search_pwd(buffer, pid, argv, env);
}
