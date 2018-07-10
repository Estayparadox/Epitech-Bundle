/*
** builtin.c for 42sh in /home/arrazo_p/semestre2/SystemeUnix/PSU_2014_minishell2/sources
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sun Mar  8 02:33:59 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:51:17 2015 Vatinelle Maxime
*/

#include "../42sh.h"

int	my_builtins(t_mini *shell)
{
  shell->cwd = getcwd(shell->buffcwd, 100);
  if ((my_strcmp(shell->tab[0], "cd")) == 0)
    my_cd(shell);
  else if ((my_strcmp(shell->tab[0], "exit")) == 0)
    return (-1);
  else if ((shell->command[0] == '.' && shell->command[1] == '/'))
    my_exec_prog(shell);
  else if ((my_strcmp(shell->tab[0], "echo")) == 0)
    my_echo(shell);
  else
    return (0);
  return (1);
}
