/*
** PGCommands.c for PGCommands in /home/pereni_j/Rendu/PSU_2015_myftp/src
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri May 13 00:06:10 2016 pereniguez joseph
** Last update Sun May 15 10:07:28 2016 pereniguez joseph
*/

#include "server.h"

int	end_put(char *filename, int fd, char *tmp)
{
  char		*mode;
  int		i;

  mode = "0777";
  i = strtol(mode, 0, 8);
  chmod(filename, i);
  close(fd);
  free(tmp);
  return (REQUEST_FILE);
}

int	cmd_put(t_client *client, char *str)
{
  char	buf[BUFSIZE];
  char	filename[BUFSIZE];
  char	*tmp;
  int	fd;
  long	nb;

  sprintf(filename, "%d", LIST_OK);
  send_to_client(client, filename);
  snprintf(filename, BUFSIZE, "%s%s%s", ROOT_DIR, client->dir, str);
  if (!(fd = open(filename, O_CREAT | O_WRONLY)))
    return (REQUEST_FILE);
  read(client->fd, &buf, BUFSIZE);
  nb = atol(buf);
  if (!(tmp = malloc(sizeof(char) * nb)))
    return (REQUEST_FILE);
  my_putstr(fd, tmp, nb);
  my_putstr(1, tmp, nb);
  return (end_put(filename, fd, tmp));
}
