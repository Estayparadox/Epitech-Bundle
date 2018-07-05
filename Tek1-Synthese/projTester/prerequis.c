/*
** my_wait_synthese.c for my_wait_synthese in /home/pereni_j/Rendu/projTester
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jun 18 09:12:29 2015 joseph pereniguez
** Last update Fri Jun 19 15:30:32 2015 joseph pereniguez
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void		my_ps_synthese()
{
  pid_t		pid;

  pid = fork();
  if (pid == 0)
    execlp("ps", "ps", NULL);
  else
    wait(0);
}
