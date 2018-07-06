#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
  int	i;
  int	j;
  int	k;

  if (ac != 3)
    return (1);
  k = 0;
  for (i = 0; (unsigned)i < strlen(av[1]); ++i)
    {
      for (j = 0; (unsigned)j < strlen(av[2]); ++j)
	if (av[1][i] == av[2][j])
	  ++k;
    }
  printf("%d\n", k);
  return (0);
}
