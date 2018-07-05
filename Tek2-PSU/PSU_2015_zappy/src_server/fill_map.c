/*
** fill_map.c for fill_map in /home/pereni_j/MEGAREPO/PSU_2015_zappy/src_server
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Sun Jun 26 19:00:43 2016 pereniguez joseph
** Last update Sun Jun 26 23:21:10 2016 Luca Guarnieri
*/

#include "head/server.h"
#include <sys/time.h>
#include <time.h>

void		calc_prob2(t_server *server, int i, int j)
{
  struct timeval	time;

  gettimeofday(&time, NULL);
  if ((rand() % 100) < 50)
    {
      gettimeofday(&time, NULL);
      if ((rand() % 100) < 50)
	{
	  gettimeofday(&time, NULL);
	  if ((rand() % 100) < 50)
	    {
	      gettimeofday(&time, NULL);
	      if ((rand() % 100) >= 50)
		server->world->content[i][j]->thystame_nb++;
	    }
	  else
	    server->world->content[i][j]->phiras_nb++;
	}
      else
	server->world->content[i][j]->mendiane_nb++;
    }
  else
    server->world->content[i][j]->sibur_nb++;
}

void		calc_prob(t_server *server, int i, int j)
{
  struct timeval	time;

  gettimeofday(&time, NULL);
  if ((time.tv_usec % 100) < 50)
    {
      gettimeofday(&time, NULL);
      if ((time.tv_usec % 100) < 50)
	{
	  gettimeofday(&time, NULL);
	  if ((rand() % 100) < 50)
	    {
	      gettimeofday(&time, NULL);
	      if ((rand() % 100) < 50)
		  calc_prob2(server, i, j);
	       else
		 server->world->content[i][j]->deraumere_nb++;
	    }
	  else
	    server->world->content[i][j]->linemate_nb++;
	}
      else
	server->world->content[i][j]->food_nb++;
    }
}

void		fill_case(t_server *server)
{
  int		i;
  int		j;

  i = 0;
  while (i <= server->world->width)
    {
      j = 0;
      while (j <= server->world->height)
	{
	  calc_prob(server, i, j);
	  j++;
	}
      i++;
    }
}

void		init_case(t_server *server, int i, int j)
{
  server->world->content[i][j]->food_nb = 0;
  server->world->content[i][j]->linemate_nb = 0;
  server->world->content[i][j]->deraumere_nb = 0;
  server->world->content[i][j]->sibur_nb = 0;
  server->world->content[i][j]->mendiane_nb = 0;
  server->world->content[i][j]->phiras_nb = 0;
  server->world->content[i][j]->thystame_nb = 0;
  server->world->content[i][j]->player_nb = 0;
}

void		fill_map(t_server *server)
{
  int		i;
  int		j;

  i = 0;
  server->world->content = xmalloc(sizeof(*server->world->content)
  				   * (server->world->width * server->world->height));
  while (i <= server->world->width)
    {
      j = 0;
      server->world->content[i] = xmalloc(sizeof(t_content)
					  * server->world->width);
      while (j <= server->world->height)
	{
	  server->world->content[i][j] = xmalloc(sizeof(t_content));
	  init_case(server, i, j);
	  j++;
	}
      i++;
    }
  fill_case(server);
  if (server->option->aff_map == 1)
    {
      aff_map(server);
      server->option->aff_map = 0;
    }
}
