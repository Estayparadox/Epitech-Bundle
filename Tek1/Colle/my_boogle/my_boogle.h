/*
** my_boogle.h for my_boogle in /home/pereni_j/Colle_6
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jun  2 18:05:53 2015 joseph pereniguez
** Last update Tue Jun  2 21:43:07 2015 joseph pereniguez
*/

#ifndef MY_BOOGLE_H_
# define MY_BOOGLE_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct	s_val
{
  int		i;
  int		j;
  int		old;
}		t_val;

void		my_putchar(char c);
void		my_putstr(char *str);
void		classic_boogle();
void		boogle_g(char *str);
void		parse_op(char **argv);
void		print_grid(char *str);
void		print_line1(char *str);
void		print_line2(char *str);
void		print_line3(char *str);
void		print_line4(char *str);
void		put_error(char *buffer);
int		my_strlen(char *str);
int		look_at_char(char *str);
int		check_char(char *str);
int		try(char *s1, char *s2);
int		my_puterror(char *str);
char		*after_check(char *s1, char *s2);
char		*aff_rand_str();

#endif
 
