/*
** redi_right.c for 42sh in /home/vatine_m/rendu/PSU_2014/PSU_2014_42sh/sources
** 
** Made by Vatinelle Maxime
** Login   <vatine_m@epitech.net>
** 
** Started on  Sun May 24 14:49:16 2015 Vatinelle Maxime
** Last update Sun May 24 14:49:17 2015 Vatinelle Maxime
*/

#include "../42sh.h"

void	redi_right(t_mini *shell)
{
  shell->fd_open = open(shell->tab[2], O_CREAT | O_RDWR, 0666);
  if (shell->fd_open == -1)
    my_xputstr("Error on open\n");
  if ((shell->pid = fork()) == -1)
    my_xputstr("Error on fork\n");
  if (shell->pid == 0)
    {
      shell->str = my_strcat(shell->path[shell->nb], "/");
      shell->cat = my_strcat(shell->str, shell->tab[0]);
      shell->dup_error = dup2(shell->fd_open, 1);
      if (shell->dup_error == -1)
        my_xputstr("Error on dup2\n");
      shell->tab[1] = NULL;
      if (execve(shell->cat, shell->tab, shell->env) == -1)
        fprintf(stderr, "error\n");
    }
  else
    {
      wait(0);
      shell->close_error = close(shell->fd_open);
      if (shell->close_error == -1)
        my_xputstr("Error on close\n");
    }
}
