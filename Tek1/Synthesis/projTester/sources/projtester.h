/*
** projtester.h for projtester in /home/pereni_j/Rendu/projTester/sources
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jun 18 09:53:26 2015 joseph pereniguez
** Last update Sat Jun 20 11:48:53 2015 joseph pereniguez
*/

#ifndef PROTESTER_H_
# define PROJTESTER_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

void		my_ps_synthese();
void		my_puchar(char c);
void		my_putstr(char *str);
void		my_reader(char *bin, char *word);
void		my_readerer(char *bin, char *word);
void		my_checker(char *file, char **argv);
void		my_looptofail();
void		my_dashe(char **tab, char **argv);
void		boucle_inf();
void		my_call_funct(char *file, char **argv);
void		send_to_exec(char *bin, char *word);
void		funct_noresult(char **tab, char **argv);
void		funct_result();
void		checker_tester(char **argv);
void		checker_notester(char **argv);
void		o_finder(char **argv);
int		find_result(char **tab);
int		call_checkop(char **tab, char **argv);
int		option_e(char **tab, char **argv, int i);
int		no_option(char **tab, char **argv, int i);
int		call_checker(char **tab, char **argv);
int		check_arg(char **tab);
int		my_strlen(char *str);
int		ret_char(char c);
int		my_nb_word(char *str);
int		my_nb_carac(char *str);
int		my_strcmp(char *s1, char *s2);
char		*str_cat(char *s1, char *s2);
char		**my_strtowordtab(char *str);

#endif
