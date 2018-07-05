/*
** genealogie.h for genealogie in /home/pereni_j/Rendu/genealogie/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jul  2 10:02:15 2015 joseph pereniguez
** Last update Fri Jul  3 14:07:19 2015 joseph pereniguez
*/

#ifndef GENEALOGIE_H_
# define GENEALOGIE_H_

# include <dirent.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <time.h>
# include <memory.h>

int			open_rep(char *rep, char *file);
int			open_bart(char *rep, char *file);
int			ret_char(char c);
int			ret_char2(char c);
int			ret_char3(char c);
int			my_nb_word(char *str);
int			my_nb_word2(char *str);
int			my_nb_word3(char *str);
int			my_nb_carac(char *str);
int			my_nb_carac2(char *str);
int			my_nb_carac3(char *str);
int			my_strlen(char *str);
int			my_strcmp(char *s1, char *s2);
int			print_cv(char *str, char *rep);
int			rep_reprinter(char *str, int i);
char			*my_strcat(char *s1, char *s2);
char			*my_lstr(char *cmd, char *op1, char *op2, char *rep);
char			*my_lstime(char *cmd, char *op1, char *op2, char *rep);
char			**my_str_to_wordtab(char *str);
char			**my_str_to_wordtab2(char *str);
char			**my_str_to_wordtab3(char *str);
void			aff_lstr(char *res);
void			aff_lstime(char *res, char *file, char *rep);
void			aff_inode(char *str);
void			aff_zero(char *str);
void			rep_printer(char *str);
void			print_born(char **tabx);
void			print_shield(char **tabx);

#endif
