/*
** op1.c for op1 in /home/pereni_j/Rendu/FASTAtools/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jun 24 16:38:38 2015 joseph pereniguez
** Last update Thu Jun 25 11:06:54 2015 joseph pereniguez
*/

#include "fastatools.h"

void		option1_2(char *file, int i)
{
  if ((file[i] != '>') && (file[i] == 'a' || file[i] == 'c' ||
			   file[i] == 't' || file[i] == 'g' ||
			   file[i] == 'n'))
    printf("%c", file[i] - 32);
  else if ((file[i] != '>') && (file[i] == 'A' || file[i] == 'C' ||
				file[i] == 'T' || file[i] == 'G' ||
				file[i] == 'N'))
    printf("%c", file[i]);
  else
    return;
  return;
}

void		option_1(char *file)
{
  int		i;

  i = 0;
  while (file[i])
    {
      if (file[i] == '>' && !file[i - 1])
	{
          while (file[i] != '\n')
            printf("%c", file[i++]);
          printf("\n");
	}
      else if (file[i] == '>' && file[i - 1])
        {
          printf("\n");
          while (file[i] != '\n')
            printf("%c", file[i++]);
          printf("\n");
        }
      else
	option1_2(file, i);
      i++;
    }
  printf("\n");
}
