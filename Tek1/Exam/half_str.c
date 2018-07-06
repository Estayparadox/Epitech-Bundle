#include <unistd.h>
#include <string.h>

int	main(int ac, char **av)
{
  int	i;
  int	j;

  for (i = 1; i < ac; ++i)
    {
      for (j = 0; (unsigned)j < strlen(av[i]); j += 2)
	write(1, &av[i][j], 1);
      write(1, "\n", 1);
    }
  if (i == 1)
    write(1, "\n", 1);
  return (0);
}
