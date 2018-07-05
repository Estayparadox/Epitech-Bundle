/*
** navCommands.c for navCommands in /home/pereni_j/Rendu/PSU_2015_myftp/src
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri May 13 00:04:13 2016 pereniguez joseph
** Last update Sun May 15 10:06:55 2016 pereniguez joseph
*/

#include "server.h"

int	cmd_pwd(t_client *client, char *str)
{
  (void)str;
  send_to_client(client, client->dir);
  return (PWD_OK);
}

char	*get_new_wd(bool *from_root, char *str,
			    t_client *client, char *tmp)
{
  *from_root = false;
  if (!str)
    {
      client->dir = "/";
      return (NULL);
    }
  else if (str[0] == '/')
    {
      *from_root = true;
      snprintf(tmp, BUFSIZE, "%s%s", ROOT_DIR, str);
    }
  else
    snprintf(tmp, BUFSIZE, "%s%s%s", ROOT_DIR, client->dir, str);
  return (tmp);
}

int		cmd_cd(t_client *client, char *str)
{
  struct stat	s;
  char		*tmp;
  bool		from_root;

  if ((!(tmp = malloc(sizeof(char) * BUFSIZE)))
      || !(tmp = get_new_wd(&from_root, str, client, tmp)))
    return (REQUEST_FILE);
  if (stat(tmp, &s) == FAILURE)
      send_to_client(client, "no such file or directory" );
  else
    {
      if (S_ISDIR(s.st_mode) && from_root == false)
	printf(client->dir, "%s%s", strlen(client->dir) + strlen(str),
	      client->dir, str);
      else if (S_ISDIR(s.st_mode) && from_root == true)
	printf(client->dir, "%s%s", strlen(str), str);
      else
	send_to_client(client, "no such file or directory\r\n" );
    }
  free(tmp);
  return (REQUEST_FILE);
}

int		cmd_ls(t_client *client, char *str)
{
  char		dir[BUFSIZE];
  char		ret[BUFSIZE];
  char		tmp[BUFSIZE];
  struct dirent *road;
  DIR		*dirp;

  memset(ret, 0, BUFSIZE);
  sprintf(ret, "%d", LIST_OK);
  send_to_client(client, ret);
  memset(ret, 0, BUFSIZE);
  if (!str)
      snprintf(dir, BUFSIZE, "%s%s", ROOT_DIR, client->dir);
  else
    snprintf(dir, BUFSIZE, "%s%s%s", ROOT_DIR, client->dir, str);
  if (!(dirp = opendir(dir)))
    return (DATA_CONNECT);
  while ((road = readdir(dirp)))
    {
      sprintf(tmp, "%s ", road->d_name);
      strcat(ret, tmp);
    }
  send_to_client(client, ret);
  return (DATA_CONNECT);
}
