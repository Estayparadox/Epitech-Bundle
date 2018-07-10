/*
** 42sh.h for  in /home/arrazo_p/PSU_2014_42sh/sources
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Wed Apr 29 10:33:30 2015 arrazolaleon pedroantonio
** Last update Sat May 23 22:21:24 2015 paul rosset
*/

#ifndef _42SH_H_
# define _42SH_H_

# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

# define BUFFSIZE 2
# define SIZE 1000

typedef struct	s_mini
{
  char		**env;
  char		**av;
  char		**tab;
  char		**parse;
  char		**path;
  char		*command;
  int		nb;
  int		ret;
  char		*cwd;
  char		buffcwd[4095];
  char		*echo1;
  char		*echo2;
  int           fd_open;
  int           dup_error;
  int           close_error;
  pid_t         pid;
  char          *str;
  char          *str1;
  char          *cat;
  int		i;
  char		*cmd;
  char		*cmd2;
}		t_mini;

int		my_strlen(char *str);
int		my_putstr(char *str);
int		my_xputstr(char *str);
int		my_strcmp(char *s1, char *s2);
int		my_putchar(char c);
void		my_xputchar(char c);
char		*my_strstr(char *str, char *to_find);
char		*my_strcat(char *s1, char *s2);
char		*my_strcp(char *s1, char *s2);
char		*epur_str(char *str);
char		**my_str_to_wordtab(char *str, char carac);
int		cas_special(t_mini *shell);
int	        my_path_command(t_mini *shell);
int		my_search_command(char *str, char **path, t_mini *shell);
int		my_strlen_tab(char **str);
int		xread(int fd, void *buff, size_t count);
int		my_printf(const char *format, ...);
int		my_builtins(t_mini *shell);
int		my_parse_loop(t_mini *shell);
int		count2(char *str);
void		ctrl_c();
void		my_cd(t_mini *shell);
int		my_print_prompt();
void		my_fork(t_mini *shell, int nb);
void		*xmalloc(int len);
char		*xmemset(char *str);
char		*my_parse_env(char *str, char **env);
char		*my_parse_command(t_mini *shell);
t_mini		*tranfert_env(char **env);
void		redi_right(t_mini *shell);
void		double_redi_right(t_mini *shell);
int		check_redi_right(t_mini *shell, int i);
int		check_error_redi_right(t_mini *shell, int i);
int		check_error_redi_right2(t_mini *shell, int i);
int		check_double_redi_right(t_mini *shell);
int		check_error_double_redi_right(t_mini *shell, int i);
int		check_error_double_redi_right2(t_mini *shell, int i);
int		redi_left(t_mini *shell);
int		check_redi_left(t_mini *shell, int i);
int		check_error_redi_left(t_mini *shell, int i);
int		check_error_redi_left2(t_mini *shell, int i);
void            my_echo(t_mini *shell);
void            my_exec_prog(t_mini *shell);
char		*my_display_line(char *dest, char src[SIZE + 1],
				 int index, int *start);
char		*get_next_line(const int fd);

#endif /* 42SH_H_ */
