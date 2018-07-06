#include <unistd.h>

static char printed[255] = {0};

static void	manage_a_string(char *s)
{
  int		i;

  i = -1;
  while (s[++i])
    if (!printed[(int)s[i]])
      {
	printed[(int)s[i]] = 1;
	write(1, s + i, 1);
      }
}

int	main(int ac, char **av)
{
  if (ac < 3)
    return (write(1, "\n", 1));
  manage_a_string(av[1]);
  manage_a_string(av[2]);
  return (write(1, "\n", 1) && 0);
}
