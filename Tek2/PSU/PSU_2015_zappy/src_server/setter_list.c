/*
** setter_list.c for setter_list in /home/pereni_j/PSU_2015_zappy/src_server
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Sat Jun 25 17:03:44 2016 pereniguez joseph
** Last update Sun Jun 26 20:38:13 2016 pereniguez joseph
*/

#include "head/server.h"

void		set_team_name(t_server *server, int i)
{
  server->team[i].team_name = server->option->argv[server->option->index];
}

int		set_team(t_server *server)
{
  int		nb_team;
  int		i;

  nb_team = 0;
  i = 0;
  server->option->index--;
  while ((server->option->index < server->option->argc)
	 && (*(server->option->argv[server->option->index]) != 45))
    {
      set_team_name(server, i);
      printf("Team %d: %s\n", i + 1, server->option->argv[server->option->index]);
      server->option->index++;
      nb_team++;
      i++;
    }
  server->option->nb_team = nb_team;
  return (0);
}

int		set_client(t_server *server)
{
  if (is_number(server->option->current_argv) != -1)
    {
      if (atoi(server->option->current_argv) == 0)
	print_usage();
      server->cap->client_nbr = atoi(server->option->current_argv);
    }
  else
    return (-1);
  return (0);
}
