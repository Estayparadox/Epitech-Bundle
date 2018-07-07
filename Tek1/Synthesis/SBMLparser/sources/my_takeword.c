/*
** my_takeword.c for my_takeword in /home/pereni_j/Rendu/SBMLparser/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jun 17 08:41:55 2015 joseph pereniguez
** Last update Wed Jun 17 11:19:32 2015 joseph pereniguez
*/

#include "sbmlparser.h"

int             double_rea2(char **tab, int i)
{
  while ((my_strcmp(tab[i], "listOfReactions")) != 0)
    {
      if ((my_strcmp(tab[i], "reaction")) == 0)
        {
          while ((my_strcmp(tab[i], "listOfReactionts")) != 0)
            {
              if ((my_strcmp(tab[i], "species")) == 0 &&
                  (my_strcmp(tab[i - 4], "listOfProducts")) != 0)
                printf("%s %s + ", tab[i - 1], tab[i + 1]);
              if ((my_strcmp(tab[i], "species")) == 0 &&
                  (my_strcmp(tab[i - 4], "listOfProducts")) == 0)
                {
                  printf("%s %s\n", tab[i - 1], tab[i + 1]);
                  return (0);
                }
              i--;
            }
        }
      i++;
    }
  return (0);
}

void            double_rea(char **tab, int i)
{
  i = i + 1;
  while ((my_strcmp(tab[i], "listOfProducts")) != 0)
    {
      if ((my_strcmp(tab[i], "species")) == 0 &&
          (my_strcmp(tab[i + 2], "listOfReactants")) != 0)
        printf("%s %s + ", tab[i - 1], tab[i + 1]);
      if ((my_strcmp(tab[i], "species")) == 0 &&
          (my_strcmp(tab[i + 2], "listOfReactants")) == 0)
        printf("%s %s ", tab[i - 1], tab[i + 1]);
      i++;
    }
  printf("<-> ");
  simple_rea2(tab, i);
}

int		simple_rea2(char **tab, int i)
{
  while ((my_strcmp(tab[i], "listOfReactions")) != 0)
    {
      if ((my_strcmp(tab[i], "reaction")) == 0)
	{
	  while ((my_strcmp(tab[i], "listOfReactionts")) != 0)
	    {
	      if ((my_strcmp(tab[i], "species")) == 0 &&
		  (my_strcmp(tab[i - 4], "listOfProducts")) != 0)
		printf("%s %s + ", tab[i - 1], tab[i + 1]);
	      if ((my_strcmp(tab[i], "species")) == 0 &&
		  (my_strcmp(tab[i - 4], "listOfProducts")) == 0)
		{
		  printf("%s %s\n", tab[i - 1], tab[i + 1]);
		  return (0);
		}
	      i--;
	    }
	}
      i++;
    }
  return (0);
}

void		simple_rea(char **tab, int i)
{
  i = i + 1;
  while ((my_strcmp(tab[i], "listOfProducts")) != 0)
    {
      if ((my_strcmp(tab[i], "species")) == 0 &&
	  (my_strcmp(tab[i + 2], "listOfReactants")) != 0)
	printf("%s %s + ", tab[i - 1], tab[i + 1]);
      if ((my_strcmp(tab[i], "species")) == 0 &&
          (my_strcmp(tab[i + 2], "listOfReactants")) == 0)
	printf("%s %s ", tab[i - 1], tab[i + 1]);
      i++;
    }
  printf("-> ");
  simple_rea2(tab, i);
}

int		check_reverse(char **tab, int i)
{
  while ((my_strcmp(tab[i], "reaction")) != 0)
    {
      if ((my_strcmp(tab[i], "reversible")) == 0 &&
	  (my_strcmp(tab[i + 1], "false")) == 0)
	{
	  simple_rea(tab, i);
	  exit(0);
	}
      if ((my_strcmp(tab[i], "reversible")) == 0 &&
          (my_strcmp(tab[i + 1], "true")) == 0)
	{
	  double_rea(tab, i);
	  exit(0);
	}
      i--;
    }
  return (-1);
}
