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

typedef struct	s_elem
{
  int		value;
  struct s_elem	*next;
  struct s_elem	*prev;
}		t_elem;

int		main(int argc, char **argv);
t_elem		my_init_list(int nbr);
void		sa(t_elem *l_a);
void		sb(t_elem *l_b);
void		ss(t_elem *l_a, t_elem *l_b);
void		pa(t_elem **l_a, t_elem **l_b);
void		pb(t_elem **l_a, t_elem **l_b);
void		ra(t_elem **l_a);
void		rb(t_elem **l_b);
void		rr(t_elem **l_a, t_elem **l_b);
void		rra(t_elem **l_a);
void		rrb(t_elem **l_b);
void		rrr(t_elem **l_a, t_elem **l_b);
t_elem		my_new_end_elem(int nbr, t_elem *list);
t_elem		my_new_elem(int nbr, t_elem *list);
int		my_getnbr(char *str);
int		my_check_list(t_elem *list);
void		my_algo(int argc, t_elem **l_a, t_elem **l_b);
int		my_putstr(char *str);
int		my_putchar(char c);

#endif
