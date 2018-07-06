#include <unistd.h>
#include <string.h>

static int	print_word(char *s)
{
  int		i;

  i = -1;
  while (s[++i] && s[i] != ' ' && s[i] != '\t');
  write(1, s, i);
  return (i);
}

int	main(int ac, char **av)
{
  int	i;

  if (ac < 2)
    return (write(1, "\n", 1));
  while (strchr(" \t", *av[1]))
    ++av[1];
  i = strlen(av[1]);
  while (--i >= 0)
    if ((!i || strchr(" \t", av[1][i - 1]))
	 && print_word(av[1] + i) && i)
	write(1, " ", 1);
  return (write(1, "\n", 1) && 0);
}
