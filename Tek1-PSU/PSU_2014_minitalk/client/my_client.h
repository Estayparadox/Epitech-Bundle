/*
** my_client.h for my_client in /home/pereni_j/rendu/PSU_2014_minitalk/client
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Mar 17 14:13:06 2015 Pereniguez Joseph
** Last update Sat Mar 21 16:25:39 2015 Pereniguez Joseph
*/

#ifndef MY_CLIENT_H_
# define MY_CLIENT_H_

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>

int		main(int argc, char **argv);
void		convert_mess(int pid, char *str);
void		sending(int pid, char *str);
int		my_getnbr(char *str);
void		my_putchar(char c);
void		my_putstr(char *str);
int		my_pow(int nb, int pow);
int		check_pid(char *str);
int		check_ex_pid(char *str);

#endif /* MY_CLIENT_H_ */
