#ifndef ALLUM_H_
# define ALLUM_H_

#ifndef READ_SIZE
#define READ_SIZE (1)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct  s_gnl
{
    char        *str;
    int         i;
}               t_gnl;

typedef struct	s_play
{
  char		    *buffer;
  int		    nb_line;
  int		    nb_matches;
}		        t_play;

char    *get_next_line(const int fd);
int	    my_putchar(char);
int	    my_putcharerror(char);
int	    my_putstr(char * );
int	    my_putstrerror(char *);
int	    my_strlen(char *);
int	    my_getnbr(char *);
int	    my_put_nbr(int);
int	    check_line(int, int *);
int	    check_match(int, int *, int);
void    aff_del(int, int);
int	    is_over(int *);
int	    is_number(char *);
int	    get_nb_line(int *, t_play *);
int	    get_nb_matches(int *, t_play *);
int	    play(int *, int);
int	    display_board(int *);
int	    ai(int *, int, int);
int	    aff_all(int *);
int	    aff_one(int *);
int	    aff_two(int *);
int	    aff_three(int *);
int	    aff_four(int *);

#endif
