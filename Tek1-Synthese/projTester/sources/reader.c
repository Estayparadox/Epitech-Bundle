/*
** reader.c for reader in /home/pereni_j/Rendu/projTester/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jun 18 10:29:22 2015 joseph pereniguez
** Last update Fri Jun 19 15:08:31 2015 joseph pereniguez
*/

#include "projtester.h"

void		my_checker(char *file, char **argv)
{
  int		fd;
  char		buffer[4096];
  char		**tab;
  int		ret;

  argv = argv;
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      printf("! Fichier mal formaté !\n");
      return;
    }
  ret = read(fd, buffer, 4096);
  buffer[ret] = 0;
  if (buffer[0] == '\0' || buffer == NULL)
    {
      printf("! Fichier mal formaté !\n");
      return;
    }
  tab = my_strtowordtab(buffer);
  call_checker(tab, argv);
}

void		my_reader(char *bin, char *word)
{
  pid_t		pid;

  bin = bin;
  pid = fork();
  if (pid == 0)
    execlp(bin, bin, "-n", word, NULL);
  else
    wait(0);
}

void		my_readerer(char *bin, char *word)
{
  pid_t         pid;

  bin = bin;
  pid = fork();
  if (pid == 0)
    execlp(bin, bin, "-n", "-e", word, NULL);
  else
    wait(0);
}
