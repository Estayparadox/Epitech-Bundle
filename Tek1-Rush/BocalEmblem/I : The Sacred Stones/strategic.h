/*
** strategic.h for strategic in /home/pereni_j/Rendu/BocalEmblem/The Sacred Stones
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat May 16 10:48:23 2015 joseph pereniguez
** Last update Sun May 17 16:48:08 2015 Jade Kadri
*/

#ifndef STRATEGIG_H_
# define STRATEGIC_H_

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_size
{
  int		x;
  int		y;
  int		cpt;
}		t_size;

typedef struct	s_sold
{
  char		**line;
  char		**elem;
  char		buffer[4096];
  int		x;
  int		y;
}		t_sold;

int		my_put_nbr(int n);
int		my_getnbr(char *str);
int		my_strlen(char *str);
int		cpt_y(char **line);
int		cpt_x(char *str);
int		verify_elem(char **line, char *str);
int		verify_soldiers(char *str);
int		verify_double(char *str);
void		my_putchar(char c);
void		my_putstr(char *str);
void		my_puterror(char *str);
void		verify_map(char *file);
void		verify_extension(char *file);
void		verify_size(char *file, char *str);
void		aff_size(char *file, int x, int y);
void		aff_blue_sold(int sold, int x, int y);
void		aff_red_sold(int sold, int x, int y);
void		*xmalloc(int len);
char		**my_str_to_wordtab(char *str, char c);
int		number_of_space(char *str, char c);
char		**my_str_to_wordtab_2(char *str, char c1, char c2);
int		number_of_space_2(char *str, char c1, char c2);

#endif
