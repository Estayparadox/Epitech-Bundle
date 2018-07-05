/*
** algo.c for  in /home/vatine_m/PSU/PSU_2015_philo
**
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
**
** Started on  Sun Mar 13 15:00:58 2016 vatinelle maxime
** Last update Sun Mar 13 16:58:33 2016 pereniguez joseph
*/

#include "philo.h"

void		*algo(void *av)
{
  t_philo	*p;

  p = (t_philo*)av;
  while (p->nbRice > 0)
    {
      if (p->action == 'e')
      	{
	  pthread_mutex_unlock(&p->right->chopstick);
	  pthread_mutex_unlock(&p->chopstick);
      	  eater(p);
      	  p->action = 's';
      	}
      if (p->action == 's')
  	{
  	  lphilo_sleep();
  	  p->action = 't';
  	}
      else
	{
	  pthread_mutex_unlock(&p->chopstick);
	  thinker(p);
	}
    }
  pthread_exit(NULL);
}

void		thinker(t_philo *p)
{

  if (pthread_mutex_trylock(&p->chopstick) == 0)
  {
    lphilo_take_chopstick(&p->chopstick);
    lphilo_think();
    p->action = 'e';
    lphilo_release_chopstick(&p->chopstick);
    pthread_mutex_unlock(&p->chopstick);
  }
}

void		eater(t_philo *p)
{
  if ((pthread_mutex_trylock(&p->chopstick) == 0)
      && (pthread_mutex_trylock(&p->right->chopstick) == 0))
    {
      lphilo_take_chopstick(&p->chopstick);
      lphilo_take_chopstick(&p->right->chopstick);
      lphilo_eat();
      p->nbRice = p->nbRice - 1;
      lphilo_release_chopstick(&p->chopstick);
      pthread_mutex_unlock(&p->chopstick);
      lphilo_release_chopstick(&p->right->chopstick);
      pthread_mutex_unlock(&p->right->chopstick);
    }
}
