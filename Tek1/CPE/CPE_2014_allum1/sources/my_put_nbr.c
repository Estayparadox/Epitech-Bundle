#include "allum.h"

int	    get_power(int nb)
{
  int	power;

  if (nb > 999999999) {
      power = 1000000000;
      return (power);
  }
  power = 1;

  while (nb > 0) {
      nb = nb / 10;
      power = power * 10;
  }

  power = power / 10;

  return (power);
}

void	maj(int nb)
{
  char	c;

  if (nb <= 9) {
    c = nb + 48;
    my_putchar(c);
  }
}

int	    display_negative(int nb)
{
  if (nb < 0) {
      my_putchar('-');
      nb = nb * -1;
  }

  return (nb);
}

void	display_nbr(int nb, int stock)
{
  char	c;
  int	pow;

  pow = get_power(nb);
  while (pow != 1)
    {
      stock = nb / pow;
      c = stock + 48;
      nb = nb - (stock * pow);
      pow = pow / 10;
      my_putchar(c);
      maj(nb);
    }
}

int	    my_put_nbr(int nb)
{
  int	stock;

  stock = 0;
  if (nb == -2147483648) {
      write(1, "-2147483648", 11);
      return (0);
  }

  nb = display_negative(nb);
  maj(nb);

  if (nb >= 9)
    display_nbr(nb, stock);

  return (0);
}
