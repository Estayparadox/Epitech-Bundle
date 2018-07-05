/*
** my_putnbr_base.c for my_putnbr_base in /home/pereni_j/rendu/Piscine_C_J07/lib/my
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Nov 15 18:14:24 2014 Pereniguez Joseph
** Last update Sat Nov 15 18:49:52 2014 Pereniguez Joseph
*/

void    my_putnbr_base(int nb, char *base)
{
  int	i;
  int	j;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  j = my_strlen(base);
  i = nb % j;
  nb = nb / j;
  if (nb > 0)
    my_putnbr_base(nb, base);
  my_putchar(base[i]);
}
