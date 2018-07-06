#include <string.h>

#define SIGN(s)	(*s && *s == '-' ? -1 : 1)

static int	strpos(char *s, char c)
{
  int		i;

  i = -1;
  while (s[++i])
    if (s[i] == c)
      return (i);
  return (0);
}

int	my_atoi_base(char *str, char *base)
{
  long	nbr;
  int	i;

  nbr = 0;
  i = -1;
  while (str[++i])
    nbr = nbr * strlen(base) + strpos(base, str[i]);
  return ((int)(nbr * SIGN(str)));
}
