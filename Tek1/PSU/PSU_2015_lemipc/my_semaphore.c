/*
** semaphore.c for  in /home/vatine_m/PSU/PSU_2015_lemipc
** 
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
** 
** Started on  Tue Mar 22 10:45:01 2016 vatinelle maxime
** Last update Sat Mar 26 13:30:00 2016 vatinelle maxime
*/

#include "lemipc.h"

void		semaphoreLock(struct s_case c)
{
  c = c;
  c.sops.sem_num = 0;
  c.sops.sem_flg = 0;
  c.sops.sem_op = -1;
}

void		semaphoreUnlock(struct s_case c)
{
  c = c;
  c.sops.sem_num = 0;
  c.sops.sem_flg = 0;
  c.sops.sem_op = 1;
}
