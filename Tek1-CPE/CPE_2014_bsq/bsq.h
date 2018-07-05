/*
** bsq.h for bsq in /home/pereni_j/rendu/CPE_2014_bsq
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan 16 16:24:30 2015 Pereniguez Joseph
** Last update Sun Jan 18 20:34:12 2015 Pereniguez Joseph
*/

#ifndef BSQ_H_
# define BSQ_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

typedef struct	s_elem
{
  char		*str;
  struct s_elem	*next;
}		t_elem;

int		check_file(char *str);
int		check_error(int i);
int		ret_coord(int x, int y);
int             my_strlen(char *str);
t_elem		*malloc_list(char *str);
void		my_puterror(char c);
int		my_strlen(char *str);
int		my_putstr(char *str);

#endif
