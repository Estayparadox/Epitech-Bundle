/*
** my_parse_env.c for 42sh in /home/arrazo_p/semestre2/SystemeUnix/PSU_2014_minishell2
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Fri Mar  6 14:57:11 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:52:18 2015 Vatinelle Maxime
*/

#include "../42sh.h"

char		*my_parse_env(char *str, char **env)
{
  int		i;
  int		j;
  int		k;
  char		*tmp;

  i = 0;
  k = 0;
  while (env[i] != '\0')
    {
      j = 0;
      while (env[i][j] == str[j] && str[j])
        j++;
      if (!str[j])
        {
          tmp = xmalloc(sizeof(char) * my_strlen(env[i]));
          while (env[i][j])
            tmp[k++] = env[i][j++];
          tmp[k] = '\0';
          return (tmp);
        }
      i++;
    }
  return (NULL);
}

void		my_fork(t_mini *shell, int nb)
{
  pid_t		pid;
  char		*str;
  char		*cat;

  str = my_strcp(shell->path[nb], "/");
  cat = my_strcp(str, shell->tab[0]);
  pid = fork();
  if (cat[my_strlen(cat) - 1] == '\n')
    cat[my_strlen(cat) - 1] = 0;
  if (pid > 0)
    waitpid(pid, 0, 0);
  else if (pid == 0)
    execve(cat, shell->tab, shell->env);
  else
    my_xputstr("Error : fork failed\n");
  free(str);
  free(cat);
}

int		my_path_command(t_mini *shell)
{
  char		*path;
  int		nb;

  if ((path = my_parse_env("PATH=", shell->env)) == NULL)
    return (0);
  path[my_strlen(path) - 1] = '\0';
  shell->path = my_str_to_wordtab(path, ':');
  free(path);
  if ((nb = my_search_command(shell->tab[0], shell->path, shell)) == -1)
    return (-1);
  else
    my_fork(shell, nb);
  return (0);
}

int		my_fork2(char *str, t_mini *shell)
{
  pid_t		pid;

  pid = fork();
  if (pid > 0)
    waitpid(pid, 0, 0);
  else if (pid == 0)
    execve(str, shell->tab, shell->env);
  else
    my_xputstr("Error : fork failed\n");
  return (0);
}

int		my_search_command(char *str, char **path, t_mini *shell)
{
  shell->i = 0;
  while (path[shell->i])
    if ((str[0] == '/' && ((str[1] >= 'a' && str[1] <= 'z')
			   || (str[1] >= 'A' && str[1] <= 'Z'))))
      {
	my_fork2(str, shell);
	  return (shell->i);
      }
    else
      {
	shell->cmd = my_strcp(path[shell->i], "/");
	shell->cmd2 = my_strcp(shell->cmd, str);
	free(shell->cmd);
	if (shell->cmd2[my_strlen(shell->cmd2) - 1] == '\n')
	    shell->cmd2[my_strlen(shell->cmd2) - 1] = 0;
	if ((access(shell->cmd2, F_OK)) != 0)
	  shell->i++;
	else
	    {
	      free(shell->cmd2);
	      return (shell->i);
	    }
	free(shell->cmd2);
      }
  return (-1);
}
