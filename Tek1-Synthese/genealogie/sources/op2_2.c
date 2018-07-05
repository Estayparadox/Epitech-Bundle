/*
** op_bis.c for op_bis in /home/pereni_j/Rendu/genealogie/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jul  3 09:26:54 2015 joseph pereniguez
** Last update Fri Jul  3 14:05:54 2015 joseph pereniguez
*/

#include "genealogie.h"

char			g_ext[BUFSIZ];
int			g_pid;

int			rep_reprinter(char *str, int i)
{
  while (str[i] != '/' || str[i] != '\0')
    {
      i--;
      if (str[i] == '/' || str[i] == '\0')
	{
	  i = i + 1;
	  while (str[i] != '\0' || str[i] != '/')
	    {
	      printf("%c", str[i++]);
	      if (str[i] == '\0' || str[i] == '/')
		{
		  printf("\n");
		  return (0);
		}
	    }
	}
    }
  return (0);
}

void			rep_printer(char *str)
{
  int			i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
      if (str[i] == '\0')
        {
	  i = i - 2;
          if ((rep_reprinter(str, i)) == 0)
	    return;
        }
    }
}

int			print_cv(char *str, char *rep)
{
  int			fd;
  char			*temp;
  char			*adr;
  char			buffer[4096];

  temp = malloc(sizeof(char) * 4096);
  adr = malloc(sizeof(char) * 4096);
  temp = my_strcat(rep, "/");
  adr = my_strcat(temp, str);
  if ((fd = open(adr, O_RDONLY)) == -1)
    printf("erreur\n");
  read(fd, buffer, 4096);
  if (buffer[0] == '\0' || buffer == NULL)
    {
      printf("\n");
      return (0);
    }
  printf("%s", buffer);
  return (0);
}

void			aff_zero(char *str)
{
  if (my_strlen(str) == 5)
    printf(" 0%c%c%c%c%c\n", str[my_strlen(str) - 5], str[my_strlen(str) - 4],
	   str[my_strlen(str) - 3], str[my_strlen(str) - 2],
	   str[my_strlen(str) - 1]);
  if (my_strlen(str) == 4)
    printf(" 00%c%c%c%c\n", str[my_strlen(str) - 4], str[my_strlen(str) - 3],
	   str[my_strlen(str) - 2], str[my_strlen(str) - 1]);
  if (my_strlen(str) == 3)
    printf(" 000%c%c%c\n", str[my_strlen(str) - 3], str[my_strlen(str) - 2],
	   str[my_strlen(str) - 1]);
  if (my_strlen(str) == 2)
    printf(" 0000%c%c\n", str[my_strlen(str) - 2], str[my_strlen(str) - 1]);
  if (my_strlen(str) == 1)
    printf(" 00000%c\n", str[my_strlen(str) - 1]);
}

void			aff_inode(char *str)
{
  if (my_strlen(str) == 6)
    printf(" %s\n", str);
  if (my_strlen(str) > 6)
    printf(" %c%c%c%c%c%c\n", str[my_strlen(str) - 6], str[my_strlen(str) - 5],
	   str[my_strlen(str) - 5], str[my_strlen(str) - 3],
	   str[my_strlen(str) - 2], str[my_strlen(str) - 1]);
  if (my_strlen(str) < 6)
    aff_zero(str);
}
