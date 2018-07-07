/*
** my_print_hex.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

void     my_print_hex(int nbr, int char_count)
{
    char   *hex_base;
    int    i;

    hex_base = "0123456789abcdef";
    i = 0;
    while (i < (char_count - my_count_nbr_digits(nbr, 16)))
    {
        my_putchar('0');
        i += 1;
    }
    if (nbr < 0)
        nbr = -nbr;
    my_putnbr_base(nbr, hex_base);
}
