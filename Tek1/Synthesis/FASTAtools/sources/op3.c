/*
** op.c for op3 in /home/pereni_j/Rendu/FASTAtools/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jun 24 16:40:39 2015 joseph pereniguez
** Last update Thu Jun 25 11:09:43 2015 joseph pereniguez
*/

#include "fastatools.h"

void		showop_3(char **tab, int i)
{
  int		j;

  j = 0;
  while (tab[i][j])
    {
      if (tab[i][j] == 'a' || tab[i][j] == 'A')
	printf("T");
      if (tab[i][j] == 't' || tab[i][j] == 'T')
	printf("A");
      if (tab[i][j] == 'c' || tab[i][j] == 'C')
	printf("G");
      if (tab[i][j] == 'g' || tab[i][j] == 'G')
	printf("C");
      if (tab[i][j] == 'n' || tab[i][j] == 'N')
	printf("N");
      j++;
    }
}

void		sendtoshow(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if (tab[i][0] == '>')
        printf("%s\n", tab[i]);
      else if (tab[i][0] != '>' && tab[i + 1] && tab[i + 1][0] != '>')
        {
          showop_3(tab, i + 1);
          showop_3(tab, i);
          printf("\n");
	  i = i + 1;
        }
      else
        {
          showop_3(tab, i);
          printf("\n");
        }
      i++;
    }
}

void		option_3(char *file)
{
  int		i;
  char		**tab;

  i = 0;
  tab = my_strtowordtab(file);
  while (tab[i])
    {
      if (tab[i][0] != '>')
	tab[i] = rev_str(tab[i]);
      i++;
    }
  sendtoshow(tab);
}
