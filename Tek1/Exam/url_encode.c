#include <stdio.h>
#include <string.h>

#define NON_ESCAPE	"$-_.!*(),"
#define IS_LOWER(c)	(c >= 'a' && c <= 'z')
#define IS_UPPER(c)	(c >= 'A' && c <= 'Z')
#define IS_ALPHA(c)	(IS_LOWER(c) || IS_UPPER(c))
#define IS_NUM(c)	(c >= '0' && c <= '9')

int	main(int ac, char **av)
{
  int	i;

  if (ac != 2)
    return (printf("\n"));
  i = -1;
  while (av[1][++i])
    {
      if (av[1][i] == ' ')
	printf("+");
      else if (IS_ALPHA(av[1][i])
	       || IS_NUM(av[1][i])
	       || strchr(NON_ESCAPE, av[1][i]))
	printf("%c", av[1][i]);
      else
	printf("%%%X", av[1][i]);
    }
  return (printf("\n") && 0);
}
