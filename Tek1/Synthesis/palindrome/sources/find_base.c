/*
** find_base.c for find_base in /home/pereni_j/Rendu/palindrome/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Jun 27 08:34:10 2015 joseph pereniguez
** Last update Sat Jun 27 10:55:14 2015 joseph pereniguez
*/

#include "palindrome.h"

void            check_pal_base(char *sup, char *str, char *base, char *ndb)
{
  int           i;
  int           j;
  static int    c;
  int		r;

  i = 0;
  j = my_strlen(sup) - 1;
  while (i < j)
    {
      if (sup[i] != sup[j])
        {
          c = c + 1;
          finder_base(sup, str, base, ndb);
          return;
        }
      i++;
      j--;
    }
  r = my_getnbr_base(sup, base);
  printf("%s donne %d en %d itération(s) (en base %s)\n", str, r, c + 1, ndb);
}

int		finder_base(char *sup, char *str, char *base, char *ndb)
{
  char          *rev;
  int           r;
  int		a;
  int		b;

  rev = rev_str(sup);
  a = my_getnbr_base(sup, base);
  b = my_getnbr_base(rev, base);
  r = a + b;
  sup = my_putnbr_base(r, base);
  check_pal_base(sup, str, base, ndb);
  return (0);
}

int             first_check_base(char *str, char *base, char *ndb)
{
  int           i;
  int           j;
  char		*sup;

  i = 0;
  j = 0;
  if (str == NULL || str[0] == '\0')
    printf("argument invalide\n");
  sup = malloc(sizeof(char) * 4096);
  sup = my_putnbr_base(atoi(str), base);
  j = my_strlen(sup) - 1;
  while (i < j)
    {
      if (sup[i] != sup[j])
        {
	  finder_base(sup, str, base, ndb);
          return (0);
        }
      i++;
      j--;
    }
  printf("%s donne %s en 0 itération(s) (en base %s)\n", str, str, ndb);
  return (0);
}
