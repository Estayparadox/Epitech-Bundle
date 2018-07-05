/*
** main.c for main in /home/pereni_j/rendu/PSU_2014_minitalk/client
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Mar 17 13:19:22 2015 Pereniguez Joseph
** Last update Sat Mar 21 18:11:15 2015 Pereniguez Joseph
*/

#include "my_client.h"

void    convert_mess(int pid, char *str)
{
  int   i;
  int   j;

  j = 0;
  while (str[j])
    {
      i = 7;
      while (i >= 0)
        {
          usleep(750);
          if (((str[j] >> i) % 2) == 1)
            kill(pid, SIGUSR2);
          else
            kill(pid, SIGUSR1);
          i = i - 1;
        }
      j = j + 1;
    }
}

int	check_ex_pid(char *str)
{
  int	pid;

  pid = my_getnbr(str);
  if (kill(pid, 0) == -1)
    return (-1);
  else
    return (0);
  return (0);
}

int	check_pid(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	j = j + 1;
      i = i + 1;
    }
  if (j > 0 || check_ex_pid(str) == -1)
    return (-1);
  else
    return (0);
  return (0);
}

int     main(int argc, char **argv)
{
  int   pid;

  if (argc == 3)
    {
      if (check_pid(argv[1]) == 0)
	{
	  pid = my_getnbr(argv[1]);
	  my_putstr("\033[32;05m\nMessage being converting, wait.\033[00m\n");
	  convert_mess(pid, "\033[32;05mMessage being received.\033[00m\n\n");
	  convert_mess(pid, argv[2]);
	  convert_mess(pid, "\033[32;05m\n\nMessage received.\033[00m\n\n");
	  my_putstr("\033[32;05mMessage sent.\033[00m\n\n");
	}
      else
	my_putstr("\033[31;05m\n\tPID Error\033[00m\n\n");
    }
  else
    {
      my_putstr("\033[31;05m\n\tArguments Error\033[00m\n\n");
      exit(0);
    }
  return (0);
}
