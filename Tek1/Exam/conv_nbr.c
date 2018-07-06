#include <unistd.h>
#include <string.h>

#define SIGN(s)	(*s && *s == '-' ? -1 : 1)

static void	my_putchar(char c)
{
  write(1, &c, 1);
}

static int	strpos(char *s, char c)
{
  int		i;

  i = -1;
  while (s[++i])
    if (s[i] == c)
      return (i);
  return (0);
}

static int	my_atoi_base(char *str, char *base)
{
  long		nbr;
  int		i;

  nbr = 0;
  i = -1;
  while (str[++i])
    nbr = nbr * strlen(base) + strpos(base, str[i]);
  return ((int)(nbr * SIGN(str)));
}

static void	my_putnbr_base(long val, char *base)
{
  int		len;

  len = strlen(base);
  if (val < 0)
    {
      write(1, "-", 1);
      val *= -1;
    }
  if (val > 0)
    {
      my_putnbr_base(val / len, base);
      my_putchar(base[val % len]);
    }
}

int	main(int ac, char **av)
{
  if (ac < 4)
    return (1);
  if (strlen(av[1]) == 1 && *av[1] == *av[2])
    write(1, av[3], 1);
  else
    my_putnbr_base(my_atoi_base(av[1], av[2]), av[3]);
  return (write(1, "\n", 1) && 0);
}
