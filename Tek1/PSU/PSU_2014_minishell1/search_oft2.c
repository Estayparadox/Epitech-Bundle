/*
** search_oft2.c for search_oft2 in /home/pereni_j/rendu/PSU_2014_minishell1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jan 29 18:00:40 2015 Pereniguez Joseph
** Last update Sun Feb  1 16:19:10 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

void    search_env(char *buffer, int pid, char **argv, char **env)
{
  if (buffer[0] == 'e' && buffer[1] == 'n'
      && buffer[2] == 'v' && buffer[3] == '\n')
    {
      if ((pid = fork()) == -1)
        my_puterror("[ERROR]: >fork error<");
      else if (pid == 0)
        {
          execve("/usr/bin/env", argv, env);
        }
      else
        wait(0);
    }
  else
    exe_cd(buffer);
}
