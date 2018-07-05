/*
** xfunct.c for xfunct in /home/pereni_j/PSU_2015_zappy/src_server
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri Jun 24 23:09:30 2016 pereniguez joseph
** Last update Sun Jun 26 18:33:32 2016 pereniguez joseph
*/

#include "head/xfunct.h"

void		my_puterror(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      write(2, &str[i], 1);
      i++;
    }
}

int		xbind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  if (bind(sockfd, addr, addrlen) == -1)
    {
      my_puterror("Error server: bind\n");
      exit(-1);
    }
  return (0);
}

int		xlisten(int sockfd, int backlog)
{
  if (listen(sockfd, backlog) == -1)
    {
      my_puterror("Error server: listen\n");
      exit(-1);
    }
  return (0);
}

int		xsocket()
{
  int		desc;

  if ((desc = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      my_puterror("Error server: socket\n");
      exit(-1);
    }
  return (desc);
}

void		*xmalloc(size_t size)
{
  void		*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      my_puterror("Error ! Malloc failed !\n");
      exit(-1);
    }
  return (ptr);
}
