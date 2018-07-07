/*
** my.h for libmy in /home/pereni_j/libmy
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
void        my_swap(int *a , int *b);
void        my_sort_int_array(int *tab , int size);
void        my_print_hex(int nbr, int char_count);
void        my_print_hex_str(char const *beg, char const *end);
void        my_revstr_swap(char *p1, char *p2);
void	    my_memcpy(void *dest, void *src, unsigned int size);
void		my_puterr(const char *str);

void        *my_memset(void *ptr, int value, int size);
void		*my_xmalloc(int size);

int         my_count_nbr_digits(int n, int base);
int         my_isneg(int nb);
int         my_put_nbr(int nb);
int         my_strcmp(char const *s1, char const *s2);
int         my_putstr(char const * str);
int         my_strncmp(char const *s1 , char const *s2 , int n);
int         my_strlen(char const * str);
int         my_getnbr(char const *str);
int         my_compute_power_rec(int nb , int power);
int         my_compute_square_root(int nb);
int         my_str_isalpha(char const * str);
int         my_str_isnum(char const * str);
int         my_is_prime(int nb);
int         my_find_prime_sup(int nb);
int         my_str_islower(char const * str);
int         my_str_isupper(char const * str);
int         my_str_isprintable(char const * str);
int         my_showstr(char const *str);
int         my_showmem(char const *str, int size);
int		    my_putnbr_base(int nbr, char *base);
int         my_is_word_char(char c);
int		    my_getnbr_base(char *str, char *base);
int         my_get_digit_weight(char c, char *base);
int         my_is_valid_digit(char c, char *base);
int		    my_strlcat(char *dest, char *src, int size);
int	        my_check_base(char c, char *bdd);
int	        my_power_rec(int nb, int power);

char        my_char_to_low(char c);
char        my_char_to_up(char c);

char        *my_strupcase( char * str);
char        *my_strstr(char * str , char const *to_find);
char        *my_strlowcase(char * str);
char        *my_strcapitalize(char *str);
char        *my_strcpy(char *dest, char const *src);
char        *my_strncpy(char *dest , char const *src ,int n);
char        *my_revstr( char *str);
char        *my_strcat(char *dest, char const *src);
char        *my_strncat(char *dest , char const *src , int nb);
char        *my_find_first_digit(char *str, char *base);
char		*my_strdup(char *str);
char		*my_strndup(char *src, int n);

char	    **my_strtok(char *str, char *bdd, int flag);

#endif      /* __MY_H__ */
