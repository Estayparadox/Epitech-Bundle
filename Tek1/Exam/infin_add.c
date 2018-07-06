#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define VAL(x)		(x - '0')
#define ASCII(x)	(x + '0')
#define IS_NEG(x)	(*x == '-' ? 1 : 0)
#define ALIGN(s, i)	(i < IS_NEG(s) ? 0 : VAL(s[i]))
#define POS(c)		(c < 0 ? c + 10 : c)
#define BIGGEST(a, b)	(is_bigger(a, b) ? a : b)
#define SMALLEST(a, b)	(is_bigger(a, b) ? b : a)

static void	print_nb(char *s)
{
  int		i;

  for (i = 0; s[i] == '0'; ++i);
  printf("%s\n", s[i] ? s + i : "0");
}

static int	is_bigger(char *a, char *b)
{
  int		i;
  int		j;

  for (i = 0; a[i] == '0' || a[i] == '-'; ++i);
  for (j = 0; b[j] == '0' || b[j] == '-'; ++j);
  if (strlen(a + i) == strlen(b + j))
    return (a[i] >= b[j]);
  else
    return (strlen(a + i) > strlen(b + j));
}

static void	add(char *s1, char *s2)
{
  char *a, *b, *c;
  int la, lb, len;
  int i, j;
  int carry;
  int add;

  a = BIGGEST(s1, s2);
  b = SMALLEST(s1, s2);
  la = strlen(a);
  lb = strlen(b);
  len = la + 1;
  if (!(c = memset(malloc((len  + 1) * sizeof(char)), '0', len)))
    return ;
  c[len] = 0;
  for (i = la - 1, j = lb - 1, carry = 0; i >= IS_NEG(a); --i, --j)
    {
      if (IS_NEG(a) == IS_NEG(b))
	{
	  add = ALIGN(a, i) + ALIGN(b, j) + carry;
	  carry = add / 10;
	}
      else
	{
	  add = ALIGN(a, i) - ALIGN(b, j) - carry;
	  carry = (add < 0);
	  add = POS(add);
	}
      c[i + 1] = ASCII(POS(add % 10));
    }
  if (IS_NEG(a) && (a != SMALLEST(b, a)
		    || IS_NEG(b)))
    printf("-");
  print_nb(c);
  free(c);
}

int	main(int ac, char **av)
{
  if (ac != 3)
    return (1);
  add(av[1], av[2]);
  return (0);
}
