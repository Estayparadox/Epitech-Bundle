/*
** server.c for  in /home/guarni_l/epitech/PSU_2015_zappy/src_server
**
** Made by Luca Guarnieri
** Login   <guarni_l@epitech.net>
**
** Started on  Sat Jun 25 00:44:03 2016 Luca Guarnieri
** Last update Sun Jun 26 18:40:51 2016 pereniguez joseph
*/

#include "head/server.h"

t_client	*push_back(t_client **client)
{
  t_client	*tmp;
  t_client	*new;

  if (*client == NULL)
    {
      *client = (t_client*)xmalloc(sizeof(t_client));
      (*client)->next = NULL;
      return (*client);
    }
  else
    {
      tmp = *client;
      new = xmalloc(sizeof(t_client));
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = new;
      new->next = NULL;
      return (new);
    }
}

t_client        *choose_client(int i, t_server *s, t_client *c)
{
  t_client      *tmp;

  tmp = s->clients;
  while (tmp)
    {
      if (tmp->c_fd == i)
        c = tmp;
      tmp = tmp->next;
    }
  return (c);
}

void            client_verbose(t_server *s, int i, char **argv)
{
  ssize_t       nbytes;
  t_client      *c;

  c = xmalloc(sizeof(*c));
  c = choose_client(i, s, c);
  s->buf = xmalloc(4096 * sizeof(char));
  memset(s->buf, '\0', 4096);
  if ((nbytes = recv(i, s->buf, 4095, 0)) <= 0)
    {
      if (nbytes == 0)
        printf("%s: socket %d just disconnect\n", argv[0], i);
      else
        perror("read() error!");
      close(i);
      FD_CLR(i, &(s->fd));
    }
  free(s->buf);
}
