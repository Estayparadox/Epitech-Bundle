/*
** check_opt.c for check_opt in /home/pereni_j/PSU_2015_zappy/src_server
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Sat Jun 25 16:14:26 2016 pereniguez joseph
** Last update Sun Jun 26 22:08:05 2016 Luca Guarnieri
*/

#include "head/server.h"

void			check_ct(t_server *server)
{
  if (server->option->opt == 'c')
    set_client(server);
  else if (server->option->opt == 't')
    set_time(server);
  else if (server->option->opt == 'z')
    {}
  else
    print_usage();
}

void			check_yn(t_server *server)
{
  if (server->option->opt == 'y')
    set_width(server);
  else if (server->option->opt == 'n')
    set_team(server);
  else
    check_ct(server);
}

void			check_px(t_server *server)
{
  if (server->option->opt == 'p')
    set_port(server);
  else if (server->option->opt == 'x')
    set_height(server);
  else
    check_yn(server);
}
