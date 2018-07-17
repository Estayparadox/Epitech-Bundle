/*
** main.c for main in /home/pereni_j/test
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed May 27 16:18:01 2015 joseph pereniguez
** Last update Mon Jun 29 09:28:25 2015 joseph pereniguez
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct	s_list
{
  int		num;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

int		main(int argc, char **argv)
{
  t_list	*list = init_list(0);
  t_list	*tmp = list;
  int		i = 1;

  while (argv[i] != NULL)
    {
      tmp = add_new_elem(list, atoi(argv[i]));
      i++;
    }
}

t_list		init_list(int nbr)
{
  t_list	*new;

  new = malloc(sizeof(t_list));
  new->num = nbr;
  new->prev = NULL;
  new->next = NULL;
  return (new);
}

t_list		add_new_elem(t_list *list, int nbr)
{
  t_list	*new;

  new = malloc(sizeof(t_list));
  new->num = nbr;
  new = prev = list;
  list->next = new;
  new->next = NULL;
  return (new);
}
