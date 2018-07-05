/*
** userCommands.c for userCommands in /home/pereni_j/Rendu/PSU_2015_myftp/src
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri May 13 12:47:39 2016 pereniguez joseph
** Last update Fri May 13 12:47:41 2016 pereniguez joseph
*/

#include "server.h"

t_id	**get_all_user()
{
  t_id		**tab;
  int		fd;
  int		index;
  char		*str;

  index = 0;
  fd = open(USER_FILE, O_RDONLY);
  if (fd == FAILURE)
    return (NULL);
  while ((str = get_next_line(fd)))
    {
      if (str && str[0] != COMMENT)
	{
	  if ((!(tab = realloc(tab, (sizeof(t_id) * (index + 2)))))
	      || (!(tab[index] = malloc(sizeof(t_id)))))
	    return (NULL);
	  tab[index]->user = strtok(str, ":");
	  tab[index]->pass = strtok(NULL, "\0");
	  ++index;
	}
    }
  tab[index] = NULL;
  close(fd);
  return (tab);
}

int	get_password(t_client *client, char *str)
{
  client->user = str;
  client->pass = false;
  return (USER_PASS);
}

int	set_current_user(t_client *client, char *str)
{
  client->user = str;
  client->pass = true;
  return (USER_SUCCESS);
}

int	cmd_user(t_client *client, char *str)
{
  t_id	**tab;
  int	index;

  index = 0;
  if (!(tab = get_all_user()))
    return (USER_FAILURE);
  while (tab && tab[index])
    {
      if (strcmp(tab[index]->user, str) == 0 && !tab[index]->pass)
	return (set_current_user(client, str));
      else if (strcmp(tab[index]->user, str) == 0)
	return (get_password(client, str));
      ++index;
    }
  return (USER_FAILURE);
}

int	cmd_pass(t_client *client, char *str)
{
  t_id	**tab;
  int	index;

  index = 0;
  if (!(tab = get_all_user()))
    return (USER_FAILURE);
  while (tab && tab[index])
    {
      if (strcmp(tab[index]->user, client->user) == 0
	  && (strcmp(tab[index]->pass, str) == 0))
	return (set_current_user(client, str));
      else if (strcmp(tab[index]->user, client->user) == 0)
	return (USER_FAILURE);
      ++index;
    }
  return (USER_FAILURE);
}
