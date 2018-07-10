/*
** my_cd.c for 42sh in /home/arrazo_p/Systeme_Unix/PSU_2014_minishell1/sources
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Fri Jan 30 16:41:57 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:51:35 2015 Vatinelle Maxime
*/

#include "../42sh.h"

void		my_cd_prev(char *old_pos, char *pos)
{
  char		*new_pos;

  new_pos = pos;
  pos = old_pos;
  old_pos = new_pos;
  chdir(pos);
}

void		my_cd_home(t_mini *shell)
{
  char		*home;

  if ((home = my_parse_env("HOME=", shell->env)) == NULL)
    my_xputstr("\033[31mError : Directory not found\033[0m\n");
  chdir(home);
}

void		my_cd(t_mini *shell)
{
  char		*pos;
  char		*old_pos;

  if ((pos = my_parse_env("PWD=", shell->env)) == NULL)
    return ;
  if ((old_pos = my_parse_env("OLDPWD=", shell->env)) == NULL)
    return ;
  if (!shell->tab[1] || (shell->tab[1][0] == '~' && shell->tab[1][1] == '\0'))
    my_cd_home(shell);
  else if (shell->tab[1] && shell->tab[1][0] != '-' &&
	   (chdir(shell->tab[1])) != 0)
    {
      if (access(shell->tab[1], F_OK) == -1)
	my_xputstr("\033[31mError : No such file or directory\n\033[0m");
      else
	my_xputstr("\033[31mError: Permission denied\n\033[0m");
    }
  else if (shell->tab[1][0] == '-' && !shell->tab[1][1])
    my_cd_prev(old_pos, pos);
}
