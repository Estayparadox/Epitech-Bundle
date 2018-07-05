/*
** main.c for main in /home/pereni_j/rendu/PSU_2014_minitalk/serveur
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Mar 17 14:19:41 2015 Pereniguez Joseph
** Last update Sun Mar 22 10:42:21 2015 Pereniguez Joseph
*/

#include "my_server.h"

void            serv(int nb)
{
  static int    i;
  int		j;
  int		pow;
  static char   buffer[8];
  char		c;

  j = 0;
  c = 0;
  pow = 7;
  if (nb == SIGUSR2)
    buffer[i++] = 1;
  if (nb == SIGUSR1)
    buffer[i++] = 0;
  if (i == 8)
    {
      while (j < 8)
	c = c + (buffer[j++] * my_pow(2, pow--));
      my_putchar(c);
      i = 0;
      while (i < 7)
	buffer[i++] = 0;
      i = 0;
    }
}

int             main()
{
  my_putstr("\033[31;05m\n\t~Server PID:\033[00m");
  my_put_nbr(getpid());
  my_putstr("\033[31;05m~\n\n\033[00m");
  while (42)
    {
      usleep(1000);
      signal(SIGUSR1, serv);
      signal(SIGUSR2, serv);
    }
  return (0);
}
