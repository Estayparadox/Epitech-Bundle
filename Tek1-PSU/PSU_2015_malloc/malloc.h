/*
** malloc.h for malloc in /home/pereni_j/Rendu/PSU_2015_malloc
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Feb  2 09:58:29 2016 pereniguez joseph
** Last update Sun Feb 14 21:01:16 2016 pereniguez joseph
*/

#ifndef __MALLOC_H__
# define __MALLOC_h__

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <pthread.h>
# include <string.h>

typedef struct		s_list
{
  size_t		size;
  void			*addr;
  int			befree;
  struct s_list		*prev;
  struct s_list		*next;
} t_list;

void			my_put_in_list(t_list **list, size_t size);
void			my_show_list();
void			free(void*);

#endif
