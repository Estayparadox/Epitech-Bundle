/*
** sapin.h for sapin in /home/pereni_j/sapin/
**
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
**
** Started on  Tue Jun 16 10:37:49 2015 joseph pereniguez
** Last update Tue Jun 16 16:27:48 2015 joseph pereniguez
*/

int	    my_mid_value(int length, int max_stars)
{
    int	i;
    int	coeff;
    int	temp;
    int	n;

    temp = 0;
    coeff = 1;
    i = 1;
    n = 6;
    while (i < length)
    {
        max_stars += n;
        i += 1;
        temp += 1;
        n += 2;
        if (temp == 2)
        {
            n -= 2;
            coeff += 1;
            temp = 0;
        }
    }
    return (max_stars / 2);
}

void        my_loop(int loop, int *mid, int *star)
{
    int     n;
    int     blank;
    int     line;

    line = 0;
    while (line < loop)
    {
        blank = 0;
        n = 0;
        while (blank < *mid)
        {
            my_putchar(' ');
            blank += 1;
        }
        while (n < *star)
        {
            my_putchar('*');
            n += 1;
        }
        my_putchar('\n');
        line += 1;
        *star += 2;
        *mid -= 1;
    }
}

void        my_trunk(int mid, int size)
{
    int     i;
    int     j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < mid - (size / 2))
        {
            my_putchar(' ');
            j += 1;
        }
        j = 0;
        while (j < size)
        {
            my_putchar('|');
            j += 1;
        }
        if (size % 2 == 0)
            my_putchar('|');
        my_putchar('\n');
        i += 1;
    }
}

void	my_main_loop(int mid, int star, int loop, int length)
{
    int	i;
    int	tempo;
    int	tempo2;

    i = 0;
    tempo = 2;
    tempo2 = 0;
    while (i < length)
    {
        my_loop(loop, &mid, &star);
        mid += 2;
        star -= 4;
        i += 1;
        loop += 1;
        if (tempo == 2)
        {
            tempo = 0;
            tempo2 += 1;
        }
        mid += i > 2 ? tempo2 : 0;
        star -= i > 2 ? tempo2 * 2 : 0;
        tempo += i > 2 ? 1 : 0;
    }
}

void    my_putchar() {
    write();
}

void	sapin(int taille)
{
    int	mid;

    mid = my_mid_value(taille, 7);
    if (taille > 0)
    {
        my_main_loop(mid, 1, 4, taille);
        my_trunk(mid, taille);
    }
}
