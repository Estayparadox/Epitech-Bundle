/*
** my_put_nbr.c for my_put_nbr in /home/pereni_j/rendu/Piscine_C_J03
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Oct  1 18:52:15 2014 joseph pereniguez
** Last update Tue Oct  7 13:55:28 2014 joseph pereniguez
*/

int	my_put_nbr(int nb)
{
  int	neg;

  neg = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
	{
	  neg = 1;
	  nb = nb + 1;
	}
      nb = nb * -1;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  if (neg == 1)
    {
      neg = 0;
      my_putchar(nb % 10 + '1');
    }
  else
    my_putchar(nb % 10 + '0');
}
