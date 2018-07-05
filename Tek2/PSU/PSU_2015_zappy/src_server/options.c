/*
** options.c for options in /home/pereni_j/PSU_2015_zappy/src_server
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri Jun 24 18:01:23 2016 pereniguez joseph
** Last update Sun Jun 26 21:52:40 2016 Luca Guarnieri
*/

#include "head/server.h"

void			init_world(t_server *server)
{
  if (server->cap->world[0] != 0 && server->cap->world[1] != 0)
    {
      server->world->width = server->cap->world[0];
      server->world->height = server->cap->world[1];
    }
  else if (server->cap->world[0] != 0 && server->cap->world[1] == 0)
    {
      server->world->width = server->cap->world[0];
      server->world->height = 10;
    }
  else if (server->cap->world[0] == 0 && server->cap->world[1] != 0)
    {
      server->world->width = 10;
      server->world->height = server->cap->world[1];
    }
  else
    {
      server->world->width = 10;
      server->world->height = 10;
    }
  fill_map(server);
}

void			init_default(t_server *server, int argc, char **argv)
{
  server->option->nb_team = 0;
  server->option->argv = strtabcpy(argc, argv);
  server->option->argc = argc;
  server->option->aff_map = 0;
  server->cap->port = 4242;
  server->cap->world[0] = 0;
  server->cap->world[1] = 0;
  server->cap->client_nbr = 0;
  server->cap->time_exe = 100;
}

t_server		*init_option(int argc, char **argv)
{
  t_server		*server;
  int			ret;

  server = xmalloc(sizeof(t_server));
  server->option = xmalloc(sizeof(*server->option));
  server->cap = xmalloc(sizeof(*server->cap));
  server->team = xmalloc(sizeof(*server->team));
  server->world = xmalloc(sizeof(*server->world));
  init_default(server, argc, argv);
  while ((ret = getopt(argc, argv, "p:x:y:n:c:t:z")) != -1)
    {
      if (ret == 'n')
	server->option->nb_team = 1;
      else if (ret == 'z')
	server->option->aff_map = 1;
      server->option->opt = ret;
      server->option->current_argv = optarg;
      server->option->index = optind;
      check_px(server);
    }
  if (server->option->nb_team ==  0)
    print_usage();
  init_world(server);
  return (server);
}
