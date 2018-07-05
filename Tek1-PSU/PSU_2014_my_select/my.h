/*
** my.h for my in /home/pereni_j/rendu/PSU_2014_my_select
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Jan 10 10:33:40 2015 Pereniguez Joseph
** Last update Sat Jan 10 16:24:42 2015 Pereniguez Joseph
*/

#ifndef MY_H_
# define MY_H_

#include <termios.h>

typedef struct s_elem
{
  char		*str;
  struct s_elem	*next;
  struct s_elem	*prev;
}		t_elem;

int		raw_mode(struct termios *term);
int		end_raw_mode(struct termios *term);
int		keyboard_input(int key);
void		my_putchar(char c);
void		my_putstr(char *str);
int		my_strlen(char *str);
int		my_puterror(char *str);
int		call_putchar(int c);
int		my_buffer();

#endif /* !MY_H_ */
