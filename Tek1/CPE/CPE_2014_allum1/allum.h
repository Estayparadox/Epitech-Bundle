/*
** allum.h for allum in /home/pereni_j/rendu/CPE_2014_allum1/new_allum1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Feb 13 19:13:27 2015 Pereniguez Joseph
** Last update Sat Feb 21 10:27:06 2015 Pereniguez Joseph
*/

#ifndef ALLUM_H_
# define ALLUM_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>

char            *my_memset(char *str);
void            my_putchar(char c);
void            my_putstr(char *str);
void            my_allum(char *buffer);
void		my_second_q(char *buffer);
void		find_column(char *buffer);
void		param_c1(char *buffer, int h);
void		param_c2(char *buffer, int h);
void		param_c3(char *buffer, int h);
void		param_c4(char *buffer, int h);
void		my_tab1(int *tabx, char c, int indic);
void		my_tab2(int *tabx, char c, int indic);
void		my_tab3(int *tabx, char c, int indic);
void		my_tab4(int *tabx, char c, int indic);
void		my_aff_tab(int *tab);
void		my_check_tab1(char c, int *tab);
void		my_check_tab2(char c, int *tab);
void		my_check_tab3(char c, int *tab);
void		my_check_tab4(char c, int *tab);
void		my_recap_aff1(int *tab);
void		my_recap_aff2(int *tab);
void		my_recap_aff3(int *tab);
void		my_recap_aff4(int *tab);
void            my_funct1(char c, int a, int *tab);
void            my_funct2(char c, int a, int *tab);
void		my_funct2_2(char c, int a, int *tab);
void		my_funct2_3(char c, int a, int *tab);
void            my_funct3(char c, int a, int *tab);
void            my_funct3_2(char c, int a, int *tab);
void            my_funct3_3(char c, int a, int *tab);
void            my_funct3_4(char c, int a, int *tab);
void            my_funct3_5(char c, int a, int *tab);
void            my_funct4(char c, int a, int *tab);
void            my_funct4_2(char c, int a, int *tab);
void            my_funct4_3(char c, int a, int *tab);
void            my_funct4_4(char c, int a, int *tab);
void            my_funct4_5(char c, int a, int *tab);
void            my_funct4_6(char c, int a, int *tab);
void            my_funct4_7(char c, int a, int *tab);

#endif
