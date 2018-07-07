/*
** main.c for colle2 in /home/pereni_j/Piscine-C-colles-Semaine_02/subject1/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    <stdlib.h>
#include    <unistd.h>
#include    "my.h"

void	    appel_colle(int argc, char **argv)
{
    char	*vitesse;
    int	    i;

    i = 0;
    if (argc == 1)
        my_putstr("./colle2-1: [-speed] word1 [word2 [word3...]]\n");
    else
    {
        vitesse = malloc(my_strlen(argv[1]));
        my_strcpy(vitesse, argv[1]);
        if (vitesse[i] == '-' && (vitesse[i + 1] > 47 && vitesse[i + 1] < 58))
        {
            if (argc - 2 == 0)
                my_putstr("Erreur: pas d'arguments\n");
            else
                colle(argc - 2, &argv[2], my_getnbr(vitesse));
            free(vitesse);
        }
        else
        {
            colle(argc - 1, &argv[1], 100000);
        }
    }
}

void    colle(int argc, char **argv, int speed)
{
    int i;
    int	j;

    j = 0;
    i = 1;
    while (i > 0)
    {
        if (j == argc)
            j = 0;
        if (i % 2 != 0)
        {
            reset_field(argc, argv, j);
            my_putchar('\r');
            my_first_case(argv[j], speed);
        }
        else
        {
            reset_field(argc, argv, j);
            usleep(speed);
            my_putchar('\r');
            my_second_case(argv[j], speed);
        }
        i = i + 1;
        j = j + 1;
    }
}

void	    reset_field(int argc, char **argv, int j)
{
    if (j == 0)
    {
        my_putchar('\r');
        affichage_espace(my_strlen(argv[argc - 1]));
    }
    else
    {
        my_putchar('\r');
        affichage_espace(my_strlen(argv[j - 1]));
    }
}

int     main(int argc, char **argv)
{
    appel_colle(argc, argv);
    return(0);
}
