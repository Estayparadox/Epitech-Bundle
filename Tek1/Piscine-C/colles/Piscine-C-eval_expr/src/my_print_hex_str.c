/*
** my_print_hex_str.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

void     my_print_hex_str(char const *beg, char const *end)
{
    int    i;
    int    char_count;

    i = 0;
    char_count = 0;
    while (i < 16 && &beg[i] < end)
    {
        my_print_hex(beg[i], 2);
        if (i % 2 != 0)
        {
            my_putchar(' ');
            char_count += 1;
        }
        i += 1;
        char_count += 2;
    }
    while (char_count < 41)
    {
        my_putchar(' ');
        char_count += 1;
    }
}
