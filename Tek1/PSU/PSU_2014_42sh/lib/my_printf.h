/*
** my_printf.h for my_printf in /home/arrazo_p/PSU_2014_my_printf
** 
** Made by pedroantonio arrazolaleon
** Login   <arrazo_p@epitech.net>
** 
** Started on  Fri Nov 14 18:43:31 2014 pedroantonio arrazolaleon
** Last update Tue Mar 17 13:42:41 2015 arrazolaleon pedroantonio
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	my_char(va_list list);
void	my_str(va_list list);
void	my_nbr(va_list list);
void	my_ptr(va_list list);
void	my_binary(va_list list);
void	my_octal(va_list list);
void	my_hexa(va_list list);
void	my_super_str(va_list list);
void	my_super_hexa(va_list list);
void	my_percent();
void	my_unbr(va_list list);
void	my_putchar(char c);
void	my_putchar_print(char c);
void	my_putstr_print(char *c);
int	my_putnbr_base(int nbr, char *base);
int	my_put_nbr(int nb);
int	my_put_nbr_print(int nb);
int	my_count(void);
int	my_tab(const char *format, int index);

#endif /* MY_PRINTF_H_ */
