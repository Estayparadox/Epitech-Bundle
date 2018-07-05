/*
** basicCommands.c for basicCommands in /home/pereni_j/Rendu/PSU_2015_myftp/src
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri May 13 00:03:45 2016 pereniguez joseph
** Last update Sun May 15 10:16:47 2016 pereniguez joseph
*/

#include "server.h"

t_id	g_help[] = {
  { "USER", H_CMD_USER},
  { "LIST", H_CMD_LS},
  { "CD", H_CMD_CD},
  { "GET", H_CMD_GET},
  { "PUT", H_CMD_PUT},
  { "PWD", H_CMD_PWD},
  { "QUIT", H_CMD_QUIT},
  { "HELP", H_CMD_HELP},
  { NULL, "help : command not found" }
};

int	cmd_quit(t_client *client, char *str)
{
  (void)str;
  (void)client;
  return (SERVICE_STOP);
}

char	*help_msg(char *str)
{
    int		index;

  index = 0;
  while (g_help[index].user)
    {
      if (strcmp(g_help[index].user, str) == 0)
	return (g_help[index].pass);
      ++index;
    }
  return (g_help[index].pass);
}

int	cmd_help(t_client *client, char *str)
{
  if (!str)
    send_to_client(client, HELPMSG);
  else
    send_to_client(client, help_msg(str));
  return (HELP_MESS);
}
