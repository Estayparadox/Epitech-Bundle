/*
** palindrome.h for palindrome in /home/pereni_j/Rendu/palindrome/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jun 26 10:44:34 2015 joseph pereniguez
** Last update Sat Jun 27 11:02:36 2015 joseph pereniguez
*/

#ifndef PALINDROME_H_
# define PALINDROME_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>

int		my_strlen(char *str);
int		first_check(char *str);
int		my_atoi(char *str);
int		finder_dec(char *str, char *print);
int		check_arg(char *str);
int		my_strcmp(char *s1, char *s2);
int		init(char *base, int *nbr, int *j, int *i);
int		check_neg(char *s);
int		my_getnbr_base(char *str, char *base);
int		first_check_base(char *str, char *base, char *ndb);
int		finder_base(char *sup, char *str, char *base, char *ndb);
int		check_base(char *base, int n);
void		check_pal_base(char *sup, char *str, char *base, char *ndb);
void		check_pal(char *sup, char *u);
void		check_b(char **argv);
char		*rev_str(char *str);
char		*my_memset(char *str);
char		*my_putnbr_base(int nbr, char *base);

#endif
