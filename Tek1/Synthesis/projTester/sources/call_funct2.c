/*
** call_funct2.c for call_funct2 in /home/pereni_j/Rendu/projTester/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jun 19 14:20:09 2015 joseph pereniguez
** Last update Fri Jun 19 14:20:48 2015 joseph pereniguez
*/

#include "projtester.h"

void            send_to_exec(char *bin, char *word)
{
  pid_t         pid;

  bin = bin;
  pid = fork();
  if (pid == 0)
    execlp(bin, bin, word, NULL);
  else
    wait(0);
}
