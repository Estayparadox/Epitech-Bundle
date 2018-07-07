/*
** my.h for colle2 in /home/pereni_j/Piscine-C-colles-Semaine_02/subject5/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#ifndef     MY_H_
# define    MY_H_

int         my_revloopstar(char *str, int pos_max, int pos_word, int size);
int         my_revmid_display(char *str, int *pos_max, int *pos_word, int size);
int	        my_revback_display(char *str, int pos_star, int pos_word, int size);
int	        my_main_rev_loop(char *str, int size);
int         my_loopstar(char *str, int position_max, int position_word, int size);
int	        my_mid_display(char *str, int *pos_max, int *pos_word, int size);
int	        my_back_display(char *str, int pos_star, int position_word, int size);
int	        my_main_loop(char *str, int size);
int         my_while(char *str, int i, int max, int size);
int         my_getnbr(char const *str);
int		    my_putstr(const char *str);
int		    my_strlen(const char *str);

void	    my_loop(char *str, int size);
void		my_putchar(char c);

char	    verif_space(char *str);

char        *my_revnewstr(char *str, int pos_star, int pos_word, int size);
char        *my_newstr(char *str, int pos_star, int pos_word, int size);


#endif      /* __MY_H__ */