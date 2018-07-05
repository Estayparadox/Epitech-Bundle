/*
** lemipc.h for  in /home/vatine_m/PSU/PSU_2015_lemipc
** 
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
** 
** Started on  Tue Mar 22 09:10:34 2016 vatinelle maxime
** Last update Sat Mar 26 14:03:00 2016 vatinelle maxime
*/

#ifndef LEMIPC_H__
# define LEMIPC_H__

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <sys/msg.h>
# include <stdlib.h>
# include <time.h>
# include <sys/types.h>
# include <sys/ipc.h>

struct  s_case
{
  struct sembuf sops;
  struct s_case	*tab;
  int		nteam;
  key_t		key;
  int		size;
  int		x;
  int		y;
  int		width;
  int		height;
  int		shm;
  int		sem;
  int		msg;
};

void		my_error(char *str);
void		semaphoreLock(struct s_case c);
void		semaphoreUnlock(struct s_case c);
void		aff(struct s_case c, struct s_case *tab, char *fd);
int		tabSize(struct s_case my_case);
void		createKey(char *fd, char *fd2, struct s_case c);

#endif
