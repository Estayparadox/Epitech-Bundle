/*
** command.c for comman in /home/pereni_j/rendu/PSU_2014_minishell1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan 30 11:56:40 2015 Pereniguez Joseph
** Last update Sun Feb  1 15:53:42 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "minishell.h"

void    control_c()
{
  my_putstr("\n");
}

void    end_mysh(char *buffer)
{
  if (my_strcmp(buffer, "exit\n") == 0)
    {
      my_putstr("\033[32;01mThank you for using the Minishell1\033[00m\n");
      exit (0);
    }
  else
    press_ent(buffer);
}

void	press_ent(char *buffer)
{
  if (my_strcmp(buffer, "\n") == 0)
    {
    }
  else
    my_putstr("\033[31;05mCommand not found\033[00m\n");
}
