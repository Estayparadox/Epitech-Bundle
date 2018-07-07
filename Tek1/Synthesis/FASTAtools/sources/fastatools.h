/*
** fastatools.h for fastatools in /home/pereni_j/Rendu/FASTAtools/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jun 24 10:19:22 2015 joseph pereniguez
** Last update Thu Jun 25 11:03:34 2015 joseph pereniguez
*/

#ifndef FASTATOOLS_H_
# define FASTATOOLS_H_

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

int		ret_char(char c);
int		my_nb_word(char *str);
int		my_nb_carac(char *str);
int		my_strlen(char *str);
int		my_strcmp(char *s1, char *s2);
char		*rev_str(char *str);
char		*maj_tab(char *str);
char		**my_strtowordtab(char *str);
void   		check_op(char *op, char *file);
void		check_adn(char **argv);
void		check_adn3(char **argv);
void		check_kmers(char *op, char *km, char *file);
void		option_1(char *file);
void		option1_2(char *file, int i);
void		option_2(char *file);
void		option2_2(char *file, int i);
void		option_3(char *file);
void		option_4(char *file, char *km);
void		option2_4(char **tab, char *km);
void		sendtoshow(char **tab);
void		showop_3(char **tab, int i);

#endif
