/*
** server.h for server in /home/pereni_j/PSU_2015_zappy/src_server
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Thu Jun 23 10:30:06 2016 pereniguez joseph
** Last update Sun Jun 26 21:35:49 2016 pereniguez joseph
*/

#ifndef __SERVER_H__
# define __SERVER_H__

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>
# include <signal.h>
# include <sys/select.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "xfunct.h"
# include "funct.h"

typedef struct		s_content
{
  int                   food_nb;
  int                   linemate_nb;
  int                   deraumere_nb;
  int                   sibur_nb;
  int                   mendiane_nb;
  int                   phiras_nb;
  int                   thystame_nb;
  int                   player_nb;
}			t_content;

typedef struct		s_world
{
  int			width;
  int			height;
  t_content		***content;
}			t_world;

typedef struct		s_team
{
  char			*team_name;
}			t_team;

typedef struct		s_option
{
  char			**argv;
  char			*current_argv;
  int			argc;
  int			index;
  int			opt;
  int			nb_team;
  int			aff_map;
}			t_option;

typedef struct		s_cap
{
  unsigned int		port;
  int			world[2];
  int			client_nbr;
  int			time_exe;
}			t_cap;

typedef struct		s_client
{
  char			name[4096];
  char			chan[4096];
  int			id;
  int			c_fd;
  struct sockaddr_in	clientaddr;
  struct s_client	*next;
}			t_client;

typedef struct		s_server
{
  fd_set                fd;
  fd_set		read_fds;
  int                   socket_fd;
  int			fdmax;
  int			newfd;
  char			*buf;
  int			addrlen;
  char			**args;
  int			i;
  t_world		*world;
  t_option		*option;
  t_cap			*cap;
  t_client		*clients;
  t_team		*team;
  struct sockaddr_in	serveraddr;
}			t_server;

void		aff_map(t_server *server);
void		print_item(t_server *server, int i, int j);
void		print_item2(t_server *server, int i, int j);
void		print_item3(t_server *server, int i, int j);
void		print_item4(t_server *server, int i, int j);

int		set_client(t_server *server);
int		set_time(t_server *server);
int		set_width(t_server *server);
int		set_height(t_server *server);
int		set_port(t_server *server);
int		set_team(t_server *server);

t_server	*init_option(int argc, char **argv);
void		init_default(t_server *server, int argc, char **argv);
void		init_world(t_server *server);

void		check_px(t_server *server);
void		check_yn(t_server *server);
void		check_ct(t_server *server);

void		init_socket(t_server *server);
void		bind_socket(t_server *server);
void		accept_server(t_server *server, char **argv);

void		fill_map(t_server *server);
void		init_case(t_server *server, int i, int j);
void		fill_case(t_server *server);
void		calc_prob(t_server *server, int i, int j);
void		calc_prob2(t_server *server, int i, int j);

t_client        *push_back(t_client **client);
t_client        *choose_client(int i, t_server *s, t_client *c);
void            client_verbose(t_server *s, int i, char **argv);

#endif /* __SERVER_H__ */
