/*
** SBMLparser.h for SBMLparser in /home/pereni_j/Rendu/SBMLparser/sources
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Mon Jun 15 10:10:29 2015 joseph pereniguez
** Last update Mon Oct  2 00:40:47 2017 pereniguez joseph
*/

#ifndef SBMLPARSER_H_
# define SBMLPARSER_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		print_usage();
void		my_putchar(char c);
void		my_putstr(char *str);
void		extension_checker(char *str);
void		my_checker(char *str);
void		my_checker_op(char *str, char *op);
void            my_compartment(char **tab, char *op);
void		my_baliser(char **tab);
void		aff_attribut(char **tab, int i);
void		my_checker_equation(char *str, char *op);
int		check_param(char **tab, char *op);
void		simple_rea(char **tab, int i);
void		double_rea(char **tab, int i);
int		double_rea2(char **tab, int i);
int		simple_rea2(char **tab, int i);
int		check_reverse(char **tab, int i);
int             aff_baliser(char **tab, int i);
int		check_op(char **tab, char *op);
int		my_species(char **tab, char *op);
int		my_species2(char **tab, int i, int j);
int		my_strlen(char *str);
int		my_strcmp(char *s1, char *s2);
int		ret_char(char c);
int		ret_char2(char c);
int		my_nb_word(char *str);
int		my_nb_word2(char *str);
int		my_nb_carac(char *str);
int		my_nb_carac2(char *str);
int		my_product(char **tab, char *op, int i);
int		my_reactan(char **tab, char *op);
int		check_icompartment(char **tab, char *op, int i);
int		check_ispecies(char **tab, char *op, int i);
int		check_ireactan(char **tab, char*op, int i);
int		baliser_sbml(char **tab, int i);
int		baliser_model(char **tab, int i);
int		baliser_compartment(char **tab, int i);
int		baliser_species(char **tab, int i);
int		baliser_reaction(char **tab, int i);
int		baliser_speRef(char **tab, int i);
char		**my_strtowordtab_synthese(char *str);
char		**my_strtowordtab2(char *str);

#endif
