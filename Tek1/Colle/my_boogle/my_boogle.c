/*
** my_boogle.c for my_boogle in /home/pereni_j/Colle_6
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jun  2 19:18:06 2015 joseph pereniguez
** Last update Tue Jun  2 21:53:19 2015 joseph pereniguez
*/

#include "my_boogle.h"

int		try(char *s1, char *s2)
{
  t_val		v;

  v.i = 0;
  v.j = 0;
  v.old = 0;
  while (s1[v.i])
    {
      if ((s2[v.j] == s1[v.i] && v.old == 0) ||
	  (s2[v.j] == s1[v.i] && (v.old != 0 && (v.i == v.old || v.i == v.old + 3))))
	{
	  v.j++;
	  if (v.old == 0 || v.i == v.old || v.i == v.old + 3)
	    v.old = v.i + 1;
	  else if (s2[v.j] == s1[v.i - v.j])
	    {
	      v.j++;
	      v.old = v.i;
	    }
	  if (s2[v.j] == '\0')
	    return (0);
	}
      v.i++;
    }
  return (-1);
}

char		*after_check(char *s1, char *s2)
{
  t_val		v;

  v.i = 0;
  v.j = 0;
  v.old = 0;
  while (s1[v.i])
    {
      if ((s2[v.j] == s1[v.i] && v.old == 0) ||
	  (s2[v.j] == s1[v.i] && (v.old != 0 && (v.i == v.old || v.i == v.old + 3))))
	{
	  v.j++;
	  if (v.old == 0 || v.i == v.old || v.i == v.old + 3)
	    v.old = v.i + 1;
	  else if (s2[v.j] == s1[v.i - v.j])
	    {
	      v.j++;
	      v.old = v.i;
	      s1[v.i - 1] = s1[v.i - 1] - 32;
	    }
	  s1[v.i] = s1[v.i] - 32;
	}
      v.i++;
    }
  return (s1);
}

char		*aff_rand_str()
{
  char		*str;
  int		i;
  int		lettre;

  i = 0;
  str = malloc(sizeof(char) * 17);
  srand(time(NULL));
  while (i < 17)
    {
      lettre = rand() % 100;
      if (lettre >= 0 && lettre <= 25)
	{
	  str[i] = lettre + 97;
	  i++;
	}
    }
  str[i] = '\0';
  return (str);
}
