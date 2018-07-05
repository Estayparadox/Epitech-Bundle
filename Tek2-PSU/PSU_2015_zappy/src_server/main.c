/*
** main.c for main in /home/pereni_j/PSU_2015_zappy/src_server
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Thu Jun 23 10:27:29 2016 pereniguez joseph
** Last update Sun Jun 26 23:32:38 2016 Luca Guarnieri
*/

#include "head/server.h"

void		my_loop(t_server *server, char **argv)
{
  int		i;

  while (42)
    {
      i = 0;
      server->read_fds = server->fd;
      if (select(server->fdmax + 1, &(server->read_fds),
		 NULL, NULL, NULL) == -1)
	{
	  my_puterror("Error server: select()\n");
	  exit(-1);
	}
      printf("Server: select() OK\n");
      while (i <= server->fdmax)
	{
	  if (FD_ISSET(i, &(server->read_fds)))
	    {
	      if (i == server->socket_fd)
		accept_server(server, argv);
	      else
		client_verbose(server, i, argv);
	    }
	  i++;
	}
    }
}

int		main(int argc, char **argv)
{
  t_server	*server;

  srand(time(NULL));
  server = init_option(argc, argv);
  init_socket(server);
  bind_socket(server);
  xlisten(server->socket_fd, 10);
  FD_SET(server->socket_fd, &(server->fd));
  server->fdmax = server->socket_fd;
  server->clients = NULL;
  my_loop(server, argv);
  return (0);
}
