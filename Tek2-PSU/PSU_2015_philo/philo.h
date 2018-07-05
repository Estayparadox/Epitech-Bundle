/*
** philo.h for  in /home/vatine_m/PSU/PSU_2015_philo
**
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
**
** Started on  Tue Mar  8 09:42:35 2016 vatinelle maxime
** Last update Sun Mar 13 16:59:01 2016 pereniguez joseph
*/

#ifndef __PHILO_H__
# define __PHILO_H__

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "extern.h"

typedef struct		s_philo
{
  int			nbRice;
  char			action;
  struct s_philo	*right;
  pthread_mutex_t	chopstick;
  pthread_t		philoThread;
  int			nbP;
  int			nbT;
  int			i;
}			t_philo;

void			*algo(void *av);
void			thinker(t_philo*);
void			eater(t_philo*);
void			loop(int nbP, int nbT);
void			createThread(t_philo *p, int nbP, int i, int nbT);

#endif /* __PHILO_H__ */
