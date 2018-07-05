/*
** search_ls.c for search_ls in /home/pereni_j/rendu/PSU_2014_minishell1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jan 20 14:55:40 2015 Pereniguez Joseph
** Last update Sun Mar  8 18:28:32 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

void		search_ls(char *buffer, int pid, char **argv, char **env)
{
  if (buffer[0] == 'l' && buffer[1] == 's' && buffer[2] == '\n')
    {
      if (fork() == 0)
	{
	  execve("/bin/ls", argv, env);
	}
      else
	wait(0);
    }
  else
    search_emacs(buffer, pid, argv, env);
}

void            search_emacs(char *buffer, int pid, char **argv, char **env)
{
  char		*op[4];

  op[0] = "emacs";
  op[1] = "-nw";
  op[2] =  NULL;
  if (buffer[0] == 'e' && buffer[1] == 'm' && buffer[2] == 'a'
      && buffer[3] == 'c' && buffer[4] == 's' && buffer[5] == ' ')
    {
      if (fork() == 0)
        {
          execve("/usr/bin/emacs", op, env);
        }
      else
        wait(0);
    }
  else
    search_top(buffer, pid, argv, env);
}

void		search_top(char *buffer, int pid, char **argv, char **env)
{
  if (buffer[0] == 't' && buffer[1] == 'o' && buffer[2] == 'p'
      && buffer[3] == '\n')
    {
      if (fork() == 0)
        {
          execve("/usr/bin/top", argv, env);
        }
      else
        wait(0);
    }
  else
    search_htop(buffer, pid, argv, env);
}

void		search_htop(char *buffer, int pid, char **argv, char **env)
{
  if (buffer[0] == 'h' && buffer[1] == 't' && buffer[2] == 'o'
      && buffer[3] == 'p' && buffer[4] == '\n')
    {
      if (fork() == 0)
        {
          execve("/usr/bin/htop", argv, env);
        }
      else
        wait(0);
    }
  else
    search_pwd(buffer, pid, argv, env);
}
