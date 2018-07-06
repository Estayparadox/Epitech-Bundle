#include <stdio.h>

int	main(int ac, char **av)
{
  int	i;
  int	j;

  if (ac < 3)
    return (printf("\n"));
  j = -1;
  i = 0;
  while (av[2][++j] && av[1][i])
    if (av[1][i] == av[2][j])
      ++i;
  printf("%i\n", av[1][i] ? 0 : 1);
  return (0);
}
