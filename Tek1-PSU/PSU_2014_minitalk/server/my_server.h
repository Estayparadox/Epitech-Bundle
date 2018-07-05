/*
** my_server.h for my_server in /home/pereni_j/rendu/PSU_2014_minitalk/server
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sun Mar 22 10:49:24 2015 Pereniguez Joseph
** Last update Sun Mar 22 10:49:28 2015 Pereniguez Joseph
*/

#ifndef MY_SERVER_H_
# define MY_SERVER_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

void		serv(int nb);
void		my_putchar(char c);
void		my_putstr(char *str);
int		my_pow(int nb, int pow);
void		my_put_nbr(int nb);
int		my_getnbr(char *str);

#endif /* MY_SERVER_H_ */
