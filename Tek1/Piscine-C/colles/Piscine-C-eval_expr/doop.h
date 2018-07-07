/*
** doop.h for eval_expr in /home/pereni_j/Piscine-C-eval_expr/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#ifndef DOOP_H_
# define DOOP_H_

typedef struct	s_opp
{
  char		    *str;
  int		    (*fun) (int, int);
}		        t_opp;

int	    my_own_strcmp(char *, char *);
int	    find_my_op(char);
int	    my_usage(int, int);
int	    my_calc(int, int, char);
int	    eval_expr(char *str);
int	    my_size_int(int n);
int		my_bool_int(unsigned int nbr, char bool);
int	    firstparent(char *str, int i);
int	    backparent(char *str);
int	    anyparent(char *str);
int	    my_answer(char **arr, char *str, int i, int count);
int	    my_size_to_tab(char *str);
int	    my_mod(int a, int b);
int	    my_mul(int a, int b);
int	    my_div(int a, int b);
int	    my_sub(int a, int b);
int	    my_add(int a, int b);

void	rec_my_put_nbr(unsigned int nbr);

char	my_is_num(char);
char	my_is_op(char);
char    my_is_alphanumeric(int i, char *str);

char	*my_decstr(char *str);
char	*my_revstr_malus(char *str, char neg);
char    *my_int_to_string(int n);
char	*operation(char **arr);
char	*what_operation(char *str, int begin, int end, char parenth);
char	*my_new_minus(char *str, char *my_new_str, unsigned int i, unsigned int *j);
char	*my_new_op(char *str, char *my_new_str, unsigned int *i, unsigned int *j);
char    *where_is_my_space(char *str);
char	*my_str_powa(char *str);
char	*my_sub_string(char *str, int begin, int end);
char	*my_start_string(char *str, char *start, char *nbr, int begin);
char	*my_newstring(char *str, char *nbr, int begin, int end);

char	**my_sub_arr(char **arr, int begin, char *nbr);
char	**my_str_to_wordtab(char *str);

#endif /* __DOOP_H__ */
