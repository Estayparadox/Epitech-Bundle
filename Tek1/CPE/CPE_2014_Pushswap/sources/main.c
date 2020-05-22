/*
** main.c for main in /home/pereni_j/rendu/CPE_2014_Pushswap
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Dec  6 13:40:15 2014 Pereniguez Joseph
** Last update Sun Dec 14 20:10:08 2014 Pereniguez Joseph
*/

#include <stdlib.h>
#include <stdio.h>
#include "pushswap.h"

int		main(int argc, char **argv)
{
    static t_list	*mapile = NULL;
    static t_list	*stack2 = NULL;

    t_var	var;
    var.i = 1;
    argc = argc - 0;

    while (argv[var.i]) {
        my_push(&mapile, my_getnbr(argv[var.i]));
        var.i = var.i + 1;
    }

    my_reverse_doc(&mapile);
    while (my_is_empty(mapile) != -1) {
        var.len = my_length(mapile);
        var.nb = my_min_doc(mapile, &var.pos);

        while (var.pos != 0) {
	        my_rotate(&mapile);
	        my_var_ini(&var.i, &var.pos, 1, mapile);
        }

        my_delete_first(&mapile, &stack2);
        my_var_ini(&var.i, &var.pos, 2, mapile);
    }
    my_putchar('\n');
}
