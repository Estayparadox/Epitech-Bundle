/*
** xfunct.h for xfunct in /home/pereni_j/PSU_2015_zappy/src_server
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri Jun 24 23:10:12 2016 pereniguez joseph
** Last update Sat Jun 25 05:58:40 2016 Luca Guarnieri
*/

#ifndef __XFUNCT_H__
# define __XFUNCT_H__

# include "server.h"

int		xsocket();
int		xbind(int, const struct sockaddr*, socklen_t);
int		xlisten(int, int);
void		*xmalloc(size_t);
void		my_puterror(char*);

#endif /* __XFUNCT_H__ */
