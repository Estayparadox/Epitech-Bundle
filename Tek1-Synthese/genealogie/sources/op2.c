/*
** op2.c for op2 in /home/pereni_j/Rendu/genealogie/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jul  2 15:49:30 2015 joseph pereniguez
** Last update Fri Jul  3 15:58:01 2015 joseph pereniguez
*/

#include "genealogie.h"

char			g_ext[BUFSIZ];
int			g_pid;

char			*my_lstime(char *cmd, char *op1, char *op2, char *rep)
{
  int			fd[2];

  if (pipe(fd) == -1)
    exit(0);
  if ((g_pid = fork()) < 0)
    exit(0);
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

void			print_born(char **tabx)
{
  if (tabx[1][4] == 'r')
    {
      printf("née le %s %s %s ", tabx[6], tabx[7], tabx[8]);
      if (tabx[5][my_strlen(tabx[5]) - 2] == '\0')
	printf("(0%c)\n", tabx[5][my_strlen(tabx[5]) - 1]);
      if (tabx[5][my_strlen(tabx[5]) - 2] != '\0')
	printf("(%c%c)\n", tabx[5][my_strlen(tabx[5]) - 2],
	       tabx[5][my_strlen(tabx[5]) - 1]);
      printf("de sexe féminin\n2 ");
    }
  if (tabx[1][4] == '-')
    {
      printf("né le %s %s %s ", tabx[6], tabx[7], tabx[8]);
      if (tabx[5][my_strlen(tabx[5]) - 2] == '\0')
        printf("(0%c)\n", tabx[5][my_strlen(tabx[5]) - 1]);
      if (tabx[5][my_strlen(tabx[5]) - 2] != '\0')
        printf("(%c%c)\n", tabx[5][my_strlen(tabx[5]) - 2],
               tabx[5][my_strlen(tabx[5]) - 1]);
      printf("de sexe masculin\n1 ");
    }
}

void			print_shield(char **tabx)
{
  printf("%c%c", tabx[8][my_strlen(tabx[8]) - 2],
	 tabx[8][my_strlen(tabx[8]) - 1]);
  if (tabx[5][my_strlen(tabx[5]) - 2] == '\0')
    printf("%s 0%c", tabx[9], tabx[5][my_strlen(tabx[5]) - 1]);
  if (tabx[5][my_strlen(tabx[5]) - 2] != '\0')
    printf("%s %c%c", tabx[9], tabx[5][my_strlen(tabx[5]) - 2],
	   tabx[5][my_strlen(tabx[5]) - 1]);
  aff_inode(tabx[0]);
}

void			aff_lstime(char *res, char *file, char *rep)
{
  int			i;
  char			**tab;
  char			**tabx;

  i = 0;
  tab = my_str_to_wordtab(res);
  while (tab[i++])
    {
      tabx = my_str_to_wordtab2(tab[i]);
      if (tabx[10] && (my_strcmp(tabx[10], file)) == 0)
	{
	  print_born(tabx);
	  print_shield(tabx);
	  print_cv(tabx[10], rep);
	}
    }
}

int			open_bart(char *rep, char *file)
{
  int			fd;
  char			*res;
  char			*cmd;
  char			*op1;
  char			*op2;
  char			*temp;
  char			*adr;
  DIR			*dir;

  cmd = "ls";
  op1 = "-li";
  op2 = "--time-style=+%e %B %Y %m";
  dir = opendir(rep);
  temp = my_strcat(rep, "/");
  adr = my_strcat(temp, file);
  if (dir == NULL)
    {
      printf("! Famille incorrecte !\n");
      return (0);
    }
  if ((fd = open(adr, O_RDONLY)) == -1)
    return (0);
  printf("%s ", file);
  rep_printer(rep);
  res = my_lstime(cmd, op1, op2, rep);
  aff_lstime(res, file, rep);
  return (0);
}
