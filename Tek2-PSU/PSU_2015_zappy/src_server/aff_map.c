/*
** option.c for option in /home/pereni_j/MEGAREPO/PSU_2015_zappy/src_server
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Sun Jun 26 20:44:03 2016 pereniguez joseph
** Last update Sun Jun 26 23:28:01 2016 Luca Guarnieri
*/

#include "head/server.h"

void		print_item4(t_server *server, int i, int j)
{
  if (server->world->content[i][j]->thystame_nb == 1)
    printf("D ");
  else
    printf("- ");
}

void		print_item3(t_server *server, int i, int j)
{
  if (server->world->content[i][j]->mendiane_nb == 1)
    printf("M ");
  else if (server->world->content[i][j]->phiras_nb == 1)
    printf("P ");
  else
    print_item4(server, i, j);
}

void		print_item2(t_server *server, int i, int j)
{
  if (server->world->content[i][j]->deraumere_nb == 1)
    printf("D ");
  else if (server->world->content[i][j]->sibur_nb == 1)
    printf("S ");
  else
    print_item3(server, i, j);
}

void		print_item(t_server *server, int i, int j)
{
  if (server->world->content[i][j]->food_nb == 1)
    printf("F ");
  else if (server->world->content[i][j]->linemate_nb == 1)
    printf("L ");
  else
    print_item2(server, i, j);
}

void		aff_map(t_server *server)
{
  int		i;
  int		j;

  i = 1;
  while (i <= server->world->width)
    {
      j = 1;
      while (j <= server->world->height)
	{
	  if (j == server->world->height)
	    {
	      print_item(server, i, j);
	      printf("\n");
	    }
	  else
	    print_item(server, i, j);
	  j++;
	}
      i++;
    }
}
