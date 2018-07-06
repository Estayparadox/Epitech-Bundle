/*
** mastermind.h for mastermind in /home/pereni_j/Colle4
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu May 21 18:18:21 2015 joseph pereniguez
** Last update Thu May 21 21:57:01 2015 joseph pereniguez
*/

#ifndef MASTERMIND_H
# define MASTERMIND_H_

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_code
{
  char		*code;
  char		*pawn;
  int		try;
  int		slot;
}		t_code;

typedef struct	s_val
{
  int		i;
  int		j;
  int		y;
  int		n;
}		t_val;

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_put_nbr(int i);
int		my_strlen(char *str);
int		my_get_nbr(char *str);
void		pars_argv(char **argv);
int		my_loop(t_code code);
int		my_loop_no_op(t_code code);
void		my_prep();
void		search_code(char *buffer, t_code code);
void		aff_pawn(int y, int n);
int		succes();
void		fail();
void		my_puterror_loop(char *str, t_code code);
void		my_prompt(int i);
void		my_pawns_verify(t_code code, char *prop);
int		my_pawns_verify2(t_code code, char *prop);

#endif
