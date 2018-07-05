/*
** addClient.c for addClient in /home/pereni_j/Rendu/PSU_2015_myftp/src
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri May 13 00:04:51 2016 pereniguez joseph
** Last update Sun May 15 10:04:05 2016 pereniguez joseph
*/

#include <netinet/in.h>
#include <arpa/inet.h>
#include "server.h"

t_opmap	g_opmap[] = {
  { USER, &cmd_user },
  { LS, &cmd_ls },
  { CD, &cmd_cd },
  { PWD, &cmd_pwd },
  { QUIT , &cmd_quit },
  { HELP , &cmd_help },
  { PASS, &cmd_pass },
  { NULL, NULL }
};

void	msg_welcome(t_client *client)
{
  client->son = true;
  client->user = NULL;
  dprintf(client->fd, "%d", SERVICE_OK);
}

int	get_id_prog(char *str)
{
  int		index;

  index = 0;
  while (g_opmap[index].name)
    {
      if (strcmp(g_opmap[index].name, str) == 0)
	return (index);
      ++index;
    }
  return (FAILURE);
}

void	set_arg(char *buf, char **cmd, char **opt)
{
  if (!strstr(buf, " "))
    {
      *cmd = strtok(buf, CRLF);
      *opt = NULL;
    }
  else
    {
      *cmd = strtok(buf, " ");
      *opt = strtok(NULL, CRLF);
    }
}

void	send_to_client(t_client *client, char *str)
{
  char	buf[BUFSIZE];

  my_putstr(client->fd, str, strlen(str));
  read(client->fd, &buf, BUFSIZE);
}

void	new_client(t_client *client)
{
  char	buf[BUFSIZE];
  char	tmp[BUFSIZE];
  int	ret;
  char	*cmd;
  char	*opt;

  if (!fork())
    {
        msg_welcome(client);
      while (read(client->fd, &buf, BUFSIZE) > 0)
	{
	  set_arg(buf, &cmd, &opt);
	  if ((ret = get_id_prog(cmd)) == FAILURE)
	    dprintf(client->fd, "%d", FAILURE);
	  else
	    {
	      ret = g_opmap[ret].func(client, opt);
	      sprintf(tmp, "%d", ret);
	      send_to_client(client, tmp);
	      if (ret == SERVICE_STOP)
		return ;
	    }
	  memset(buf, 0, BUFSIZE);
	}
    }
}
