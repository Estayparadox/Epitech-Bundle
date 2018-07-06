/*
** main.c for main in /home/pereni_j/Rendu/PSU_2015_myirc/src/client
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Tue May 17 09:17:34 2016 pereniguez joseph
** Last update Tue May 17 11:29:47 2016 pereniguez joseph
*/

#include "client/client.h"

int			main(int argc, char **argv)
{
  struct protoent	*pe;
  int			fd;
  struct sockaddr_in	s_in;
  int			port;
  char			*ip;

  if (argc != 3)
    return (-1);
  ip = argv[1];
  port = atoi(argv[2]);
  pe = getprotobyname("TCP");
  if (!pe)
    return (-1);
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    return (-1);
  s_in.sin_family= AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(ip);
  if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (close(fd) == -1)
	return (-1);
      return (-1);
    }
  write(1, "Hello!\n", strlen("Hello!\n"));
  if (close(fd) == -1)
    return (-1);
  return (0);
}
