/*
** search_cd.c for search_cd in /home/pereni_j/rendu/PSU_2014_minishell1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sun Feb  1 11:00:28 2015 Pereniguez Joseph
** Last update Sun Feb  1 15:23:41 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

void	exe_cd_op(char *str);
void	put_to_cd(char *buffer);
void	try_to_cd(char *buffer);

void    exe_cd(char *buffer)
{
  if (buffer[0] == 'c' && buffer[1] == 'd')
    try_to_cd(buffer);
  else
    end_mysh(buffer);
}

void    try_to_cd(char *buffer)
{
  int	i;
  int	j;
  char	str[4094];

  i = 3;
  j = 0;
  if (buffer[2] == '\n' || my_strcmp(buffer, "cd /home\n") == 0)
    chdir("/home");
  else if (buffer[2] == ' ')
    {
      while (buffer[i] != '\n')
	{
	  str[j] = buffer[i];
	  i = i + 1;
	  j = j + 1;
	  if (buffer[i] == '\n')
	    str[i] = '\0';
	}
      exe_cd_op(str);
    }
  else
    my_puterror("[ERROR]: >cd error<\n");
}

void	exe_cd_op(char *str)
{
  chdir(str);
}
