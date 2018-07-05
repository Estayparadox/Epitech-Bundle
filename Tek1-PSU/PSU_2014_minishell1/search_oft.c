/*
** search_oft.c for search_oft in /home/pereni_j/rendu/PSU_2014_minishell1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jan 29 16:35:48 2015 Pereniguez Joseph
** Last update Sun Feb  1 16:04:40 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

void	search_pwd(char *buffer, int pid, char **argv, char **env)
{
  if (buffer[0] == 'p' && buffer[1] == 'w'
      && buffer[2] == 'd' && buffer[3] == '\n')
    {
      if ((pid = fork()) == -1)
        my_puterror("[ERROR]: >fork error<");
      else if (pid == 0)
        {
          execve("/bin/pwd", argv, env);
        }
      else
        wait(0);
    }
  else
    search_sudo(buffer, pid, argv, env);
}

void	search_sudo(char *buffer, int pid, char **argv, char **env)
{
  if (buffer[0] == 's' && buffer[1] == 'u'
      && buffer[2] == 'd' && buffer[3] == 'o'
      && buffer[4] == '\n')
    {
      if ((pid = fork()) == -1)
        my_puterror("[ERROR]: >fork error<");
      else if (pid == 0)
        {
          execve("/bin/su", argv, env);
        }
      else
        wait(0);
    }
  else
    search_cl(buffer, pid, argv, env);
}

void    search_cl(char *buffer, int pid, char **argv, char **env)
{
  if (buffer[0] == 'c' && buffer[1] == 'l'
      && buffer[2] == 'e' && buffer[3] == 'a'
      && buffer[4] == 'r' && buffer[5] == '\n')
    {
      if ((pid = fork()) == -1)
        my_puterror("[ERROR]: >fork error<");
      else if (pid == 0)
        {
          execve("/usr/bin/clear", argv, env);
        }
      else
        wait(0);
    }
  else
    search_tree(buffer, pid, argv, env);
}

void    search_tree(char *buffer, int pid, char **argv, char **env)
{
  if (buffer[0] == 't' && buffer[1] == 'r'
      && buffer[2] == 'e' && buffer[3] == 'e'
      && buffer[4] == '\n')
    {
      if ((pid = fork()) == -1)
        my_puterror("[ERROR]: >fork error<");
      else if (pid == 0)
        {
          execve("/usr/bin/tree", argv, env);
        }
      else
        wait(0);
    }
  else
    search_lock(buffer, pid, argv, env);
}

void    search_lock(char *buffer, int pid, char **argv, char **env)
{
  if (buffer[0] == 'x' && buffer[1] == 'l'
      && buffer[2] == 'o' && buffer[3] == 'c'
      && buffer[4] == 'k' && buffer[5] == '\n')
    {
      if ((pid = fork()) == -1)
        my_puterror("[ERROR]: >fork error<");
      else if (pid == 0)
        {
          execve("/usr/bin/xlock", argv, env);
        }
      else
        wait(0);
    }
  else
    search_env(buffer, pid, argv, env);
}
