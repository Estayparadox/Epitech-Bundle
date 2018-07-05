/*
** minishell.h for minishell1 in /home/pereni_j/rendu/PSU_2014_minishell1
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jan 20 10:10:13 2015 Pereniguez Joseph
** Last update Sun Feb  1 16:21:41 2015 Pereniguez Joseph
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

# include <unistd.h>

void		my_putchar(char c);
int		my_strcmp(char *s1, char *s2);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_puterror(char *str);
void		search_ls(char *buffer, int pid, char **argv, char **env);
void		search_pwd(char *buffer, int pid, char **argv, char **env);
void		search_sudo(char *buffer, int pid, char **argv, char **env);
void		search_cl(char *buffer, int pid, char **argv, char **env);
void		search_tree(char *buffer, int pid, char **argv, char **env);
void            search_lock(char *buffer, int pid, char **argv, char **env);
void            search_env(char *buffer, int pid, char **argv, char **env);
void		press_ent(char *buffer);
void		search_path(char *buffer);
void		try_yo_cd(char *buffer);
void		control_c();
void		exe_cd(char *buffer);
void		exe_cd_op(char *buffer);
void		end_mysh(char *buffer);

#endif
