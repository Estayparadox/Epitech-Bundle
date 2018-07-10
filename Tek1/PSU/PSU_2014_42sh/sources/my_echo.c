/*
** my_echo for 42sh in /home/arrazo_p/semestre2/SystemeUnix/PSU_2014_minishell2/sources
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sun Mar  8 02:33:59 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:51:55 2015 Vatinelle Maxime
*/

#include "../42sh.h"

void	my_echo4(t_mini *shell, int i, int j)
{
  if (shell->tab[i][j] == '"' || shell->tab[i][j] == 39)
    j++;
  else
    my_putchar(shell->tab[i][j]);
}

void	my_echo3(t_mini *shell)
{
  shell->echo2 = my_strcat(shell->echo1, "=");
  shell->echo2 = my_parse_env(shell->echo2, shell->env);
  if (shell->echo2 != NULL)
    my_putstr(shell->echo2);
}

void	my_echo2(t_mini *shell, int i, int j, int k)
{
  shell->echo1 = malloc(sizeof(my_strlen(shell->tab[i])));
  shell->echo2 = malloc(sizeof(my_strlen(shell->tab[i] + 1)));
  while (shell->tab[i][j])
    {
      if ((my_strcmp(shell->tab[i], "$PWD")) == 0)
	{
	  my_putstr(shell->cwd);
	  return ;
	}
      else if (shell->tab[i][j] == '$' && shell->tab[i][j + 1] != '\0')
	{
	  while (shell->tab[i][j] != '\0')
	    {
	      shell->echo1[k] = shell->tab[i][j + 1];
	      j++;
	      k++;
	    }
	  my_echo3(shell);
	}
      else
        my_echo4(shell, i, j);
      j++;
    }
}

void	my_echo(t_mini *shell)
{
  int	i;
  int	j;
  int	k;

  i = 1;
  j = 0;
  k = 0;
  if (shell->tab[1] == NULL)
    {
      my_putchar('\n');
      return ;
    }
  if ((my_strcmp(shell->tab[1], "-n")) == 0)
    i = 2;
  while (shell->tab[i])
    {
      my_echo2(shell, i, j, k);
      k = 0;
      j = 0;
      i++;
      if (shell->tab[i] != NULL)
        my_putchar(' ');
    }
  if ((my_strcmp(shell->tab[1], "-n")) != 0)
    my_putchar('\n');
}
