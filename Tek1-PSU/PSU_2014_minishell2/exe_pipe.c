/*
** exe_pipe.c for exe_pipe in /home/pereni_j/rendu/PSU_2014_minishell2
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Feb 26 08:42:22 2015 Pereniguez Joseph
** Last update Sun Mar  8 17:27:03 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include "minishell.h"

char            *my_strcat(char *s1, char *s2)
{
  int           i;
  int           j;
  char          *s3;

  i = 0;
  j = 0;
  s3 = malloc(sizeof(s3) * 4096);
  while (s1[i] != '\0')
    {
      s3[i] = s1[i];
      i++;
    }
  while (s2[j] != '\0')
    s3[i++] = s2[j++];
  s3[i] = '\0';
  return (s3);
}

void		my_pipe(char **op, char **opp, char *str1, char *str2)
{
  int		pipefd[2];

  pipe(pipefd);
  if (pipe(pipefd) == -1)
    my_putstr("[ERROR]: fork error\n");
  if (fork() == 0)
    {
      close(pipefd[0]);
      dup2(pipefd[1], 1);
      execve(str1, opp, NULL);
    }
  else
    {
      wait(0);
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      if (fork() == 0)
	execve(str2, op, NULL);
      else
	wait(0);
    }
}

int	        send_cat(char *s1, char *s2)
{
  char		*op[2];
  char		*opp[2];
  char		*r1;
  char		*r2;
  char		*str1;
  char		*str2;

  r1 = "/bin/";
  r2 = "/bin/";
  str1 = my_strcat(r1, s1);
  str2 = my_strcat(r2, s2);
  op[0] = s1;
  op[1] = NULL;
  opp[0] = s2;
  opp[1] = NULL;
  my_pipe(op, opp, str1, str2);
  return (0);
}
