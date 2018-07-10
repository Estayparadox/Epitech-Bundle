/*
** main.c for 42sh in /home/arrazo_p/PSU_2014_42sh/sources
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sun May 17 00:33:43 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:51:07 2015 Vatinelle Maxime
*/

#include "../42sh.h"

t_mini		*shell;

char		**transfert_env(char **env)
{
  int		i;
  int		nb;

  i = 0;
  if (env[0] == NULL)
    return (NULL);
  shell->env = xmalloc(sizeof(char *) * (my_strlen_tab(env) + 1));
  while (env[i])
    {
      nb = -1;
      shell->env[i] = xmalloc(sizeof(char) * (my_strlen(env[i]) + 1));
      while (env[i][++nb])
        shell->env[i][nb] = env[i][nb];
      shell->env[i][nb] = 0;
      i++;
    }
  shell->env[i] = NULL;
  return (shell->env);
}

int		my_free_end(t_mini *shell)
{
  int		index;

  if (shell->nb != 3)
    {
      if ((my_strcmp(shell->command, "\0")) == 0)
        shell->nb = 0;
      index = 0;
      if (shell->nb != 0 && shell->tab)
        while (shell->tab[index])
          free(shell->tab[index++]);
      free(shell->tab);
      index = 0;
      if (shell->nb == 2 && shell->path)
        {
          while (shell->path[index])
            free(shell->path[index++]);
          free(shell->path);
        }
    }
  return (0);
}

int			my_print_prompt()
{
  char			*user;
  char			*comp;
  static int		i;

  if ((user = my_parse_env("USER=", shell->env)) == NULL)
    user = "user";
  if ((comp = my_parse_env("HOST=", shell->env)) == NULL)
    comp = "computer";
  my_printf("[%s]@", user);
  my_printf("[%s] <%d> ", comp, ++i);
  if ((my_strcmp(user, "user")) != 0)
    free(user);
  if ((my_strcmp(comp, "computer")) != 0)
    free(comp);
  return (1);
}

int		my_loop()
{
  char		buff[4096];

  shell->i = 0;
  while (my_print_prompt())
    {
      xmemset(buff);
      shell->ret = read(dup(0), buff, 4095);
      if (shell->ret == 0)
	return (my_putchar('\n'));
      buff[shell->ret] = '\0';
      if (buff[my_strlen(buff) -1] == '\n')
        buff[my_strlen(buff) - 1] = 0;
      shell->tab = my_str_to_wordtab(epur_str((shell->command = buff)), ' ');
      if ((shell->nb = my_builtins(shell)) == -1)
	return (my_free_end(shell));
      if (buff[0] != '\0' && (check_redi_left(shell, shell->i) != 1)
		&& (check_redi_right(shell, shell->i) != 1)
		&& (check_double_redi_right(shell) != 1)
		&& (shell->nb == 0 && (shell->nb  = my_path_command(shell)) <= -1))
	fprintf(stderr, "If '%s' is not a typo you can use command-not-found"
			 "to lookup the package that contains it\n", shell->tab[0]);
      my_free_end(shell);
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{

  (void)(ac);
  (void)(av);
  shell = xmalloc(sizeof(t_mini));
  if ((shell->env = transfert_env(env)) == NULL)
    {
      my_xputstr("\033[31mError : Environement not found\n\033[0m");
      return (0);
    }
  if ((signal(SIGINT, ctrl_c)) == SIG_ERR)
    return (0);
  my_loop();
  return (0);
}
