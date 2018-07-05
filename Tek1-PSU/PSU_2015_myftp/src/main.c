/*
** main.c for main in /home/pereni_j/Rendu/PSU_2015_myftp/src
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri May 13 00:04:00 2016 pereniguez joseph
** Last update Sun May 15 10:20:24 2016 pereniguez joseph
*/

#include "server.h"

static t_server	g_server;

int	get_port(int ac, char **av)
{
  int		nb;

  if (ac == 3)
    {
      nb = atoi(av[1]);
      if (nb >= MIN_PORT && nb <= MAX_PORT)
	return (nb);
      dprintf(2, "Invalid port\n");
      return (FAILURE);
    }
  dprintf(2, "%s : port\n", av[0]);
  return (FAILURE);
}

/*int		handle_client(int client_fd, char const *client_ip)
{
  static const char * const welcome = "Welcome !\nYour IP Address is ";

  if (write(client_fd, welcome, strlen(welcome)) == -1 ||
      write(client_fd, client_ip, strlen(client_ip)) == -1 ||
      write(client_fd, "\n", 1) == -1)
    return (-1);
  return (0);
  }*/

int		init_server(t_server *server)
{
  struct protoent	*proto;
  struct sockaddr_in	addr;

  proto = getprotobyname("TCP");
  addr.sin_family = AF_INET;
  addr.sin_port = htons(server->port);
  addr.sin_addr.s_addr = INADDR_ANY;
  if (!(server->sock = socket(AF_INET, SOCK_STREAM, proto->p_proto))
      || (bind(server->sock, (const struct sockaddr *)&addr,
	       sizeof(addr)) == FAILURE)
      || (listen(server->sock, ALLOWED_USER) == FAILURE))
    {
      dprintf(2, "Failed to init server\n");
      return (FAILURE);
    }
  mkdir(ROOT_DIR, 0700);
  return (SUCCESS);
}

void	close_server()
{
  printf("Server stop\n");
  close(g_server.sock);
  exit(0);
}

int		main(int ac, char **av)
{
  t_client	client;

  signal(SIGINT, close_server);
  if (((g_server.port = get_port(ac, av)) == FAILURE))
    return (FAILURE);
  else if (!init_server(&g_server) == FAILURE)
    {
      close_server();
      return (-1);
    }
  client.dir = "/";
  client.son = false;
  while (client.son == false
	 && ((client.fd = accept(g_server.sock, NULL, NULL)) > 0))
    new_client(&client);
  return (0);
}
