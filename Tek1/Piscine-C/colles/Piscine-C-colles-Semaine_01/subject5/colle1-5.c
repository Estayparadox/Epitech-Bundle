/*
** colle1-5.c for libmy in /home/pereni_j/libmy/src
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

#include    <unistd.h>

void	    my_putchar(char c)
{
    write(1, &c, 1);
}

void	    my_char_display(char c, int i, int x, int y)
{
    if ((i == 0 || i == (x - 1)) && x > 1 && y > 1)
        my_putchar(c);
    else
        my_putchar('B');
}

void	    my_main_loop(int x, int y)
{
    int	    i;
    int	    j;

    j = 0;
    while (j < y)
    {
        i = 0;
        while (i < x)
        {
            if ((j == 0 && !(x == (x - i))) || ((j == (y - 1)) && !(i == (x - 1))))
                my_char_display('C', i, x, y);
            else if (j == (y - 1) || j == 0)
                my_char_display('A', i, x, y);
            else
            {
                if (i == 0 || i == (x - 1))
                    my_putchar('B');
                else
                    my_putchar(' ');
            }
            i += 1;
        }
        j += 1;
        my_putchar('\n');
    }
}

void	    colle(int x, int y)
{
    if (x <= 0 || y <= 0)
        my_putchar('\n');
    else
        my_main_loop(x, y);
}

int	        main()
{
    colle(2, 42);
    return (0);
}
