/*
** playRadiance.h for playRadiance in /home/pereni_j/Rendu/BocalEmblem/Path of Radiance
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat May 16 11:18:53 2015 joseph pereniguez
** Last update Sun May 17 21:17:31 2015 Jade Kadri
*/

#ifndef PLAYRADIANCE_H_
# define PLAYRADIANCE_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct  s_val
{
  int		x;
  char		*name;
}               t_val;

typedef struct  s_map
{
  int           *elem;
  int           *x;
  int           *y;
}               t_map;

typedef struct  s_value
{
  char          **tab;
  int           x;
  int           y;
  int           i;
}               t_value;

typedef struct  s_size
{
  int           x;
  int           y;
  int           cpt;
}               t_size;

typedef struct  s_sold
{
  char          **line;
  char          **elem;
  int           x;
  int           y;
}               t_sold;

void		move_right(char **tab, t_map map, int nbr_elem);
void		move_left(char **tab, t_map map, int nbr_elem);
void		move_up(char **tab, t_map map, int nbr_elem);
void		move_down(char **tab, t_map map, int nbr_elem);
void		aff_size(t_val val, int y);
int		count_y(t_map map, int nbr_elem);
int		count_x(char *str);
void		try_aff(t_map, int nbr_elem, t_val val);
void		aff_blue_sold(int sold, int x, int y);
void		aff_red_sold(int sold, int x, int y);
t_map		map_in_tab(char *str);
int		count_elem(char *str);
void		my_putchar(char c);
void		my_putstr(char *str);
int		my_strlen(char *str);
char		*my_memset(char *str);
void		my_puterror(char *str);
int		my_loop(t_map map, int nbr_elem, t_val val);
void		my_rule_radiance();
int		my_strcmp(char *s1, char *s2);
int		my_getnbr(char *str);
int		number_of_space_2(char *str, char c1, char c2);
char		**my_str_to_wordtab_2(char *str, char c1, char c2);
int		number_of_space(char *str, char c);
char		**my_str_to_wordtab(char *str, char c);
void		*xmalloc(int len);
void		my_strategic(char *buffer, t_map map, int nbr_elem, t_val val);
void		my_pass(char *buffer, t_map map, int nbr_elem);
void		my_unit(char *buffer, t_map map, int nbr_elem);
void		aff_name(char *str);
int		error_check(int i, int nbr_elem);
int		my_count_tab(char **tab);
int		verify_extension(char *file);
int		verify_double(char *str);
int		verify_map(char *file);
int		verify_soldiers(char *buffer);
int		verify_elem(char **line, char *str);
int		my_put_nbr(int n);
int		cpt_y(char **line);
int		cpt_x(char *str);

#endif
