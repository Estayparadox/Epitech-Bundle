/*
** my_exe_prog for 42sh in /home/arrazo_p/semestre2/SystemeUnix/PSU_2014_minishell2/sources
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sun Mar  8 02:33:59 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:52:09 2015 Vatinelle Maxime
*/

#include "../42sh.h"

char		*my_parse(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '.' && str[i + 1] == '/')
	return (&(str[2]));
      i++;
    }
  return ("error\n");
}

void		my_exec_prog(t_mini *shell)
{
  pid_t		pid;

  pid = fork();
  shell->tab[0] = my_parse(shell->tab[0]);
  if (shell->tab[0] != NULL && pid == 0)
    {
      if (access(shell->tab[0], F_OK) == -1)
        printf("bash: ./%s: No such file or directory\n", shell->tab[0]);
      else
        {
	  shell->tab[0] = my_strcat("/", shell->tab[0]);
	  shell->tab[0] = my_strcat(shell->cwd, shell->tab[0]);
	  execve(shell->tab[0], shell->tab, shell->env);
	}
    }
  else if (pid > 0)
    waitpid(pid, 0, 0);
}
