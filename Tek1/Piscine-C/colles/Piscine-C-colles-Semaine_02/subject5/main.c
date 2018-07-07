/*
** main.c for colle2 in /home/pereni_j/Piscine-C-colles-Semaine_02/subject5/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    <unistd.h>
#include    "my.h"

void	    my_loop(char *str, int size)
{
    int	    pos_star;
    int	    pos_max;
    int	    pos_word;
    int	    reverse;

    reverse = 0;
    while (str[0] != 0)
    {
        if (reverse == 0)
        {
            reverse = my_main_loop(str, size);
        }
        else
        {
            reverse = my_main_rev_loop(str, size);
            str = &str[1];
        }
    }
    usleep(50000);
    if (reverse == 0)
        my_putstr(my_newstr("", 0, 0, size));
    else
        my_putstr(my_revnewstr("", 1, 0, size));
}

char	    verif_space(char *str)
{
    int	    i;

    i = 0;
    while (str[i] != '\0' && str[i] == ' ')
        i = i + 1;
    return (str[i] == '\0');
}

int	        main(int argc, char **argv)
{
    int	    nbr;

    if (argc != 3)
    {
        my_putstr("Usage : colle2-5 text size\n");
    }
    else
    {
        nbr = my_getnbr(argv[2]);
        if (my_strlen(argv[1]) < 1 || verif_space(argv[1]))
            my_putstr("String too small or only space(s)");
        else if (my_strlen(argv[1]) + 3 > nbr)
            my_putstr("Size too small\n");
        else
            my_loop(argv[1], nbr);
    }
    return (0);
}
