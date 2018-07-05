/*
** command.c for comman in /home/pereni_j/rendu/PSU_2014_minishell1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan 30 11:56:40 2015 Pereniguez Joseph
** Last update Sun Mar  8 14:17:41 2015 Pereniguez Joseph
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
  if (buffer[0] == 'e' && buffer[1] == 'x'
      && buffer[2] == 'i' && buffer[3] == 't'
      && buffer[4] == '\n')
    {
      my_putstr("\033[32;01m~Thank you for using the Minishell2~\033[00m\n");
      exit (0);
    }
  else
    press_ent(buffer);
}

void	press_ent(char *buffer)
{
  if (buffer[0] == '\n')
    {
    }
  else
    my_putstr("\033[31;05mCommand not found\033[00m\n");
}
