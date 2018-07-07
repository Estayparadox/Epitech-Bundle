/*
** my.h for colle2 in /home/pereni_j/Piscine-C-colles-Semaine_02/subject1/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#ifndef     MY_H_
# define    MY_H_

void        my_putchar(char c);
void	    appel_colle(int argc, char **argv);
void	    my_first_case(char *str, int speed);
void	    my_second_case(char *str, int speed);
void	    affichage_espace(int size);

int         my_putstr(char const * str);
int         my_strlen(char const * str);
int         my_getnbr(char const *str);
void        colle(int argc, char **argv, int speed);
void	    reset_field(int argc, char **argv, int j);

char        *my_strcpy(char *dest, char const *src);
char	    *recup(char *str, int n);
char        *recup2(char *str, int n);

#endif      /* __MY_H__ */