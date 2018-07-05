/*
** op1.c for op1 in /home/pereni_j/Rendu/genealogie/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jul  2 15:04:56 2015 joseph pereniguez
** Last update Fri Jul  3 12:30:47 2015 joseph pereniguez
*/

#include "genealogie.h"

char			g_ext[BUFSIZ];
int			g_pid;

char			*my_lstr(char *cmd, char *op1, char *op2, char *rep)
{
  int			fd[2];

  if (pipe(fd) == -1)
    printf("tube cassé\n");
  if ((g_pid = fork()) < 0)
    printf("processus fils cassé\n");
  if (g_pid == 0)
    {
      while (read(fd[0], g_ext, BUFSIZ) != 0)
        return (g_ext);
    }
  else
    {
      close(fd[0]);
      dup2(fd[1], 1);
      execlp(cmd, cmd, op1, op2, rep);
    }
  close(fd[0]);
  close(fd[1]);
  return g_ext;
}

void			aff_lstr(char *res)
{
  int			i;

  i = 0;
  while (res[i])
    {
      if (res[i] == '\n' && res[i + 1])
        printf(" / ");
      if (res[i] != '\n')
        printf("%c", res[i]);
      if (res[i] == '\n' && !res[i + 1])
        printf("\n");
      i++;
    }
}

int			open_rep(char *rep, char *file)
{
  int			fd;
  char			*res;
  char			*cmd;
  char			*op1;
  char			*op2;
  char			*temp;
  char			*adr;
  DIR			*dir;

  temp = my_strcat(rep, "/");
  adr = my_strcat(temp, file);
  cmd = "ls";
  op1 = "-t";
  op2 = "-r";
  dir = opendir(rep);
  if (dir == NULL)
    {
      printf("! Famille incorrecte !\n");
      return (0);
    }
  if ((fd = open(adr, O_RDONLY)) == -1)
    return (0);
  res = my_lstr(cmd, op1, op2, rep);
  aff_lstr(res);
  return (0);
}
