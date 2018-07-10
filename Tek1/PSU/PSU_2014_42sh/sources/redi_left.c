/*
** redi_left.c for 42sh in /home/vatine_m/rendu/PSU_2014/PSU_2014_42sh/sources
** 
** Made by Vatinelle Maxime
** Login   <vatine_m@epitech.net>
** 
** Started on  Sun May 24 14:49:03 2015 Vatinelle Maxime
** Last update Sun May 24 14:49:05 2015 Vatinelle Maxime
*/

#include "../42sh.h"

int	redi_left(t_mini *shell)
{
  shell->fd_open = open(shell->tab[2], O_RDWR, 0666);
  if (shell->fd_open == -1)
    {
      my_xputstr("42sh : Aucun fichier ou dossier de ce type\n");
      return (0);
    }
  if ((shell->pid = fork()) == -1)
    my_xputstr("42sh : error on fork\n");
  if (shell->pid == 0)
    {
      shell->str = my_strcat(shell->path[shell->nb], "/");
      shell->cat = my_strcat(shell->str, shell->tab[0]);
      shell->dup_error = dup2(shell->fd_open, 0);
      if (shell->dup_error == -1)
        my_xputstr("42sh : Error on dup2\n");
      shell->tab[1] = NULL;
      if (execve(shell->cat, shell->tab, shell->env) == -1)
        fprintf(stderr, "42sh : error\n");
    }
  else if (wait(0) && (shell->close_error = close(shell->fd_open)) == -1)
    my_xputstr("42sh : Error on close\n");
  return (0);
}
