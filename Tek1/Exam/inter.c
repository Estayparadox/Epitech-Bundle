#include <unistd.h>

static char	printed[255] = {0};

static void	print(char a, char b)
{
  if (a == b && !printed[(int)a])
    {
      printed[(int)a] = 1;
      write(1, &a, 1);
    }
}

int	main(int ac, char ** av)
{
  int	i;
  int	j;

  if (ac < 3)
    return (write(1, "\n", 1));
  i = -1;
  while (av[1][++i])
    {
      j = -1;
      while (av[2][++j])
	print(av[1][i], av[2][j]);
    }
  return (write(1, "\n", 1) && 0);
}
