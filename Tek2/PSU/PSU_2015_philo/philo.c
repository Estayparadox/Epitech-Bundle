/*
** philo.c for  in /home/vatine_m/PSU/PSU_2015_philo
**
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
**
** Started on  Tue Mar  8 09:38:05 2016 vatinelle maxime
** Last update Sun Mar 13 16:20:06 2016 vatinelle maxime
*/

#include "philo.h"

void		createThread(t_philo *p, int nbP, int i, int nbT)
{
  p[i].nbRice = nbT;
  if (i == nbP - 1)
    p[i].right = &p[0];
  else
    p[i].right = &p[i + 1];
  if ((i % 2) == 0)
    {
      p[i].action = 's';
      pthread_create(&(p[i].philoThread), NULL, algo, &p[i]);
    }
  else
    {
      p[i].action = 'e';
      pthread_create(&(p[i].philoThread), NULL, algo, &p[i]);
    }
}

int	check(char **av, t_philo *p)
{
  if (strcmp(av[1], "-p") == 0)
    p->nbP = atoi(av[2]);
  else
    exit(0);
  if (strcmp(av[3], "-e") == 0)
    p->nbT = atoi(av[4]);
  else
    exit(0);
  p->i = 0;
  return (0);
}

int		main(int ac, char **av)
{
  t_philo	*p;

  if (ac != 5)
    return (0);
  if ((p = malloc(sizeof(t_philo) * atoi(av[2]))) == NULL)
    return (0);
  check(av, p);
  RCFStartup(ac, av);
  if (p->nbP < 3 || p->nbT < 0)
    return (0);
  while (p->i < p->nbP)
    {
      createThread(p, p->nbP, p->i, p->nbT);
      p->i++;
    }
  p->i = 0;
  while (p->i < p->nbP)
    {
      pthread_join(p[p->i].philoThread, NULL);
      p->i++;
    }
  RCFCleanup();
  free(p);
  return (0);
}
