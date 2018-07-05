/*
** my.h for my in /home/pereni_j/rendu/PSU_2014_my_printf/include
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sun Nov 16 14:22:52 2014 Pereniguez Joseph
** Last update Sun Nov 16 15:52:39 2014 Pereniguez Joseph
*/

#include        <stdarg.h>

#ifndef         MY_H
# define        MY_H

typedef int	(*flag)(va_list);

int	my_putchar(char c);
void	my_put_nbr(int nb);
void	my_swap(int *a, int *b);
void	my_putstr(char *str);
int	my_strlen(char *str);
void	my_putnbr_base(int nb, char *base);
int	my_printf(char *format, ...);
int	fonction_d(va_list list);
int	fonction_o(va_list list);
int	fonction_u(va_list list);
int	fonction_x(va_list list);
int	fonction_X(va_list list);
int	fonction_c(va_list list);
int	fonction_s(va_list list);
int	fonction_p(va_list list);
int	fonction_b(va_list list);
int	fonction_S(va_list list);

#endif
