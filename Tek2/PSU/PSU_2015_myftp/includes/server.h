/*
** server.h for server in /home/pereni_j/Rendu/PSU_2015_myftp/includes
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Thu May 12 23:57:45 2016 pereniguez joseph
** Last update Sun May 15 10:18:07 2016 pereniguez joseph
*/


#ifndef __SERVER_H__
# define __SERVER_H__

# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <dirent.h>
# include <stdbool.h>
# include <stdlib.h>
# include <netdb.h>
# include <unistd.h>
# include <signal.h>
# include <sys/socket.h>
# include <sys/stat.h>

# define SUCCESS        1
# define FAILURE        -1
# define CRLF           "\r\n"
# define USER           "USER"
# define LS             "LIST"
# define CD             "CWD"
# define GET            "RETR"
# define PUT            "STOR"
# define PWD            "PWD"
# define QUIT           "QUIT"
# define HELP           "HELP"
# define PASS           "PASS"
# define USER_SUCCESS   230
# define USER_FAILURE   231
# define USER_PASS      332
# define HELP_MESS      214
# define COMMAND_OK     200
# define REQUEST_FILE   250
# define LIST_OK        150
# define PWD_OK         257
# define DATA_CONNECT   256
# define SERVICE_OK     220
# define SERVICE_STOP   221
# define SERVER_DOWN    0

# define NL     "\n"

# define H_LINEONE      "Usage: CMD [ARGS]\r\n"
# define H_CMDLIST      "Available commands:\r\n"
# define H_CMD_USER     "user\t\tset user\r\n"
# define H_CMD_LS       "ls\t\tlist directory contents\r\n"
# define H_CMD_CD       "cd\t\thange the working directory\r\n"
# define H_CMD_GET      "get\t\tsend file from server to client\r\n"
# define H_CMD_PUT      "put\t\tsend file from client to server\r\n"
# define H_CMD_PWD      "pwd\t\tpprint name of current/working directory\r\n"
# define H_CMD_QUIT     "quit\t\tquit\r\n"
# define H_CMD_HELP     "help\t\tdisplays this message\r\n"
# define H_CMDS_HELP    H_CMD_PUT NL H_CMD_PWD NL H_CMD_QUIT NL H_CMD_HELP
# define H_CMDS_ACTION  H_CMD_USER NL H_CMD_LS NL H_CMD_CD NL H_CMD_GET NL
# define HELPMSG        H_LINEONE H_CMDLIST H_CMDS_ACTION H_CMDS_HELP

# define MAX_PORT	65535
# define MIN_PORT	1

# define GNL_BUFSIZ     8
# define BUFSIZE	1024
# define ALLOWED_USER	10

# define COMMENT	';'

# define USER_FILE	"data/user"
# define ROOT_DIR	"data/root"

typedef struct	s_server
{
  int		port;
  int		sock;
}		t_server;

typedef struct s_client
{
  char		*user;
  bool		pass;
  bool	        son;
  char		*dir;
  int		fd;
}		t_client;

typedef	int	(*t_opfunc)(t_client *client, char *str);

typedef struct	s_opmap
{
  char		*name;
  t_opfunc	func;
}		t_opmap;

typedef struct s_id	t_id;

struct		s_id
{
  char		*user;
  char		*pass;
};

void	my_putstr(int fd, char *str, int size);
void	new_client(t_client *client);
void	send_to_client(t_client *client, char *str);
int	cmd_user(t_client *client, char *str);
int	cmd_pass(t_client *client, char *str);
int	cmd_quit(t_client *client, char *str);
int	cmd_help(t_client *client, char *str);
int	cmd_pwd(t_client *client, char *str);
int	cmd_ls(t_client *client, char *str);
int	cmd_cd(t_client *client, char *str);
char    *get_next_line(int fd);

#endif
