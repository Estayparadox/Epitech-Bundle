#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define VAL(x) (x - '0')
#define ASCII(x) (x + '0')

static char	*mul(char *a, char *b) {
  char		*c;
  int		carry, neg = 0;
  long long	la, lb, len;
  long long	i, j, k;
  int		mul;

  if (*a == '-')
    {
      ++a;
      neg = !neg;
    }
  if (*b == '-')
    {
      ++b;
      neg = !neg;
    }
  la = strlen(a);
  lb = strlen(b);
  len = la + lb;
  if (!(c = memset(malloc((len + 1 + neg) * sizeof(char)), '0', len + neg)))
    return (NULL);
  if (neg)
    *c = '-';
  c[len + neg] = 0;
  if (!VAL(*a) || !VAL(*b) || !*c)
    return (c);
  for (i = la - 1; i >= 0; --i)
    {
      for (j = lb - 1, k = i + j + 1 + neg, carry = 0; j >= 0; --j, --k)
	{
	  mul = VAL(a[i]) * VAL(b[j]) + VAL(c[k]) + carry;
	  carry = mul / 10;
	  c[k] = ASCII(mul % 10);
	}
      c[k] += carry;
    }
  if (!VAL(c[neg]))
    memmove(c + neg, c + neg + 1, len);
  return (c);
}

int	main(int ac, char **av)
{
  char	*res;

  if (ac < 3
      || !(res = mul(av[1], av[2])))
    return (1);
  printf("%s\n", res);
  free(res);
  return (0);
}
