#include <stdio.h>

int	main(int ac, char **av)
{
  int	i;
  int	j;

  if (ac != 3)
    return (printf("\n"));
  j = -1;
  i = 0;
  while (av[2][++j])
    {
      if (av[2][j] == av[1][i])
	++i;
      if (!av[1][i])
	return (printf("%s\n", av[1]) && 0);
    }
  return (printf("\n"));
}
