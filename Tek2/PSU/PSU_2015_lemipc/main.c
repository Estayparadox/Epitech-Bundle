/*
** main.c for  in /home/vatine_m/PSU/PSU_2015_lemipc
** 
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
** 
** Started on  thu Mar 24 11:35:09 2016 vatinelle maxime
** Last update Sat Mar 26 14:00:56 2016 vatinelle maxime
*/

#include "lemipc.h"

int		tabSize(struct s_case c)
{
  c.size = c.width * c.height * sizeof(struct s_case);
  return (c.size);
}

void		createKey(char *fd, char *fd2, struct s_case c)
{
  c.size = tabSize(c);
  if ((c.key = ftok(fd, 0)) == -1)
    my_error("Usage: ./lemipc path  and the team's name ( > 0)\n");
  c.sem = semget(c.key, 1, SHM_R | SHM_W);
  c.msg = msgget(c.key, SHM_R | SHM_W);
  c.shm = shmget(c.key, c.size, SHM_R | SHM_W);
  if (c.sem == -1 || c.msg == -1  || c.shm == -1)
    {
      c.sem = semget(c.key, 1, IPC_CREAT | SHM_R | SHM_W);
      c.msg = msgget(c.key, IPC_CREAT | SHM_R | SHM_W);
      c.shm = shmget(c.key, c.size, IPC_CREAT | SHM_R | SHM_W);
      c.tab = shmat(c.shm, NULL, SHM_R | SHM_W);
      aff(c, c.tab, fd2);
      semctl(c.sem, 0, SETVAL, c.width * c.height);
    }
  else
    {
      semaphoreLock(c);
      c.tab = shmat(c.shm, NULL, SHM_R | SHM_W);
      bzero(c.tab, sizeof(*c.tab));
      msgsnd(c.msg, c.tab, sizeof(c.tab), 0);
      aff(c, c.tab, fd2);
      semop(c.sem, &c.sops, 1);
      semaphoreUnlock(c);
    }
}

int		main(int ac, char **av)
{
  struct s_case c;

  srand(time(NULL));
  if (ac != 3 || atoi(av[2]) <= 0)
    {
      fprintf(stderr, "Usage: %s path  and the team's name ( > 0)\n", av[0]);
      return (0);
    }
  else
    {
      c.height = 15;
      c.width = 10;
      createKey(av[1], av[2], c);
    }
  return (0);
}
