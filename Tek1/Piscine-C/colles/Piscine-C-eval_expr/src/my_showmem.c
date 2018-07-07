/*
** my_showmem.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include "../include/my.h"

int             my_showmem(char const *str, int size)
{
    char const    *address;
    int		    i;

    address = str;
    while (address < str + size)
    {
        my_print_hex(address - str, 8);
        my_putchar(':');
        my_putchar(' ');
        my_print_hex_str(address, str + size);
        i = 0;
        while (&address[i] < address + 16 && &address[i] < str + size)
        {
            if (address[i] > 31 && address[i] < 127)
                my_putchar(address[i]);
            else
                my_putchar('.');
            i += 1;
        }
        address += 16;
        my_putchar('\n');
    }
    return (1);
}
