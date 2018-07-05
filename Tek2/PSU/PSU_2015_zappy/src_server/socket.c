/*
** init.c for init in /home/pereni_j/PSU_2015_zappy/src_server
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri Jun 24 15:57:21 2016 pereniguez joseph
** Last update Sun Jun 26 18:48:00 2016 pereniguez joseph
*/

#include <netdb.h>
#include "head/server.h"

void	init_socket(t_server *server)
{
  int	yes;

  yes = 1;
  FD_ZERO(&server->fd);
  FD_ZERO(&server->read_fds);
  server->socket_fd = xsocket();
  printf("Server: socket() OK\n");
  if (setsockopt(server->socket_fd, SOL_SOCKET,
		   SO_REUSEADDR, &yes, sizeof(int)) == -1)
    {
      my_puterror("Error server: setsockopt()\n");
      exit(-1);
    }
  printf("setsockopt() OK\n");
}

void	bind_socket(t_server *server)
{
  server->serveraddr.sin_family = AF_INET;
  server->serveraddr.sin_addr.s_addr = INADDR_ANY;
  server->serveraddr.sin_port = htons(server->cap->port);
  xbind(server->socket_fd, (struct sockaddr *)&(server->serveraddr),
	  sizeof(server->serveraddr));
  printf("Server: bind() OK\n");
}

void	accept_server(t_server *server, char **argv)
{
  t_client	*client;
  int		addrlen;

  addrlen = sizeof(struct sockaddr_in);
  client = push_back(&server->clients);
  if ((client->c_fd = accept(server->socket_fd,
			       (struct sockaddr *)&(client->clientaddr),
			       (socklen_t *)&(addrlen))) == -1)
    my_puterror("Error server: accept\n");
  else
    {
      printf("Server: accept() OK\n");
      FD_SET(client->c_fd, &(server->fd));
      bzero(client->chan, 4096);
      server->option->nb_team++;
      if (client->c_fd > server->fdmax)
	server->fdmax = client->c_fd;
      printf("%s: New connections from %s on socket %d\n",
	       argv[0], inet_ntoa(client->clientaddr.sin_addr), client->c_fd);
    }
}
