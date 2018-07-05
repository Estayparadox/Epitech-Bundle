/*
** setter.c for setter in /home/pereni_j/PSU_2015_zappy/src_server
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Sat Jun 25 16:42:23 2016 pereniguez joseph
** Last update Sun Jun 26 18:32:49 2016 pereniguez joseph
*/

#include "head/server.h"

int		set_port(t_server *server)
{
  if (is_number(server->option->current_argv) != -1)
    server->cap->port = atoi(server->option->current_argv);
  else
    return (-1);
  return (0);
}

int		set_width(t_server *server)
{
  if (is_number(server->option->current_argv) != -1)
    server->cap->world[0] = atoi(server->option->current_argv);
  else
    return (-1);
  return (0);
}

int		set_height(t_server *server)
{
  if (is_number(server->option->current_argv) != -1)
    server->cap->world[1] = atoi(server->option->current_argv);
  else
    return (-1);
  return (0);
}

int		set_time(t_server *server)
{
  if (is_number(server->option->current_argv) != -1)
    {
      if (atoi(server->option->current_argv) <= 0)
	return (-1);
      server->cap->time_exe = atoi(server->option->current_argv);
    }
  else
    return (-1);
  return (0);
}
