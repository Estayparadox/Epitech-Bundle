/*
** my.h for my.h in /home/pereni_j/rendu/CPE_2014_Pushswap
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Dec  6 13:35:03 2014 Pereniguez Joseph
** Last update Sun Dec 14 20:28:20 2014 Pereniguez Joseph
*/

#ifndef PUSHSWAP_H_
# define PUSHSWAP_H_

typedef struct	s_list
{
  int		valeur;
  struct s_list	*prec;
  struct s_list	*next;
}		t_list;

typedef struct s_var
{
  int		nb;
  int		pos;
  int		i;
  int		len;
}		t_var;

void	my_push(t_list **p, int Val);
void	my_clear(t_list **p);
int	    my_length(t_list *p);
int	    my_is_empty(t_list *p);
void	my_var_ini(int *i, int *pos, int flag, t_list *p);
int	    my_min_doc(t_list *p, int *pos);
void	my_delete_first(t_list **p, t_list **stack2);
void	my_reverse_doc(t_list **p);
void	my_clear_all(t_list *tmp, t_list *lc);
void	my_rotate(t_list **p);
int	    main(int argc, char **argv);
int	    nbr_comp(char *str);
int	    find_operator(char *str);
int	    my_getnbr(char *str);
int	    my_power_rec(int nb, int power);
int	    new_fonc(int nb, int power, int resul,int i);
void	my_putchar(char c);
void	my_putstr(char *str);

#endif
