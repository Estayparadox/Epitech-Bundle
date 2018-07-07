/*
** find_dec.c for find_dec in /home/pereni_j/Rendu/palindrome/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jun 26 15:29:33 2015 joseph pereniguez
** Last update Sat Jun 27 11:02:21 2015 joseph pereniguez
*/

#include "palindrome.h"

char		*my_memset(char *str)
{
  int		i;

  i = 0;
  while (i < 4096)
    {
      str[i] = 0;
      i++;
    }
  return (str);
}

int		first_check(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (str == NULL || str[0] == '\0')
    printf("argument invalide\n");
  j = my_strlen(str) - 1;
  while (i < j)
    {
      if (str[i] != str[j])
        {
          finder_dec(str, str);
          return (0);
        }
      i++;
      j--;
    }
  printf("%s donne %s en 0 itération(s) (en base 10)\n", str, str);
  return (0);
}

void		check_pal(char *sup, char *u)
{
  int		i;
  int		j;
  static int	c;

  i = 0;
  j = my_strlen(sup) - 1;
  while (i < j)
    {
      if (sup[i] != sup[j])
	{
	  c = c + 1;
	  finder_dec(sup, u);
	  return;
	}
      i++;
      j--;
    }
  if ( c >= 93 )
    {
      printf("overflow\n");
      return;
    }
  else
    printf("%s donne %s en %d itération(s) (en base 10)\n", u, sup, c + 1);
}

int		finder_dec(char *str, char *print)
{
  char		*rev;
  int		r;
  char		*sup;

  sup = malloc(sizeof(char) * 4096);
  sup = my_memset(sup);
  rev = rev_str(str);
  r = my_atoi(rev) + my_atoi(str);
  sprintf(sup, "%d", r);
  check_pal(sup, print);
  return (0);
}
