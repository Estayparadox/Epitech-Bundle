#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX(x, y)	(x > y ? x : y);

static int *used = NULL;
static int result;
static int total = 0;

static int	size_of_word(char *s)
{
  int		i;

  for (i = 0; s[i] && !strchr(" -", s[i]); ++i);
  return (i);
}

static int	count_words(char *s)
{
  int		i;
  int		count;

  for (i = count = 0; (unsigned)i < strlen(s); i += size_of_word(s + i), ++count)
    while (strchr(" -", s[i]))
      ++i;
  return count;
}

static char	**parse(char *s)
{
  char		**tab;
  int		words;
  int		i;
  int		j;

  words = count_words(s);
  if (!(tab = malloc((sizeof(char *) * (1 + words)))))
    return (NULL);
  tab[words] = NULL;
  i = -1;
  j = -1;
  while (s[++i])
    {
      if (!i || ((s[i - 1] == 0 || strchr(" -", s[i - 1]))
		 && !strchr(" -", s[i])))
	tab[++j] = s + i;
      else if (strchr(" -", s[i]))
	s[i] = 0;
    }
  return (tab);
}

static int	size_of_tab(char **nodes)
{
  int		i;

  for (i = 0; nodes[i]; ++i);
  return i;
}

static void	search_and_find(char **nodes, int i)
{
  int		j;

  if (used[atoi(nodes[i])])
    return ;
  used[atoi(nodes[i])] = 1;
  result++;
  total = MAX(total, result);
  for (j = 0; nodes[j]; ++j)
    if (atoi(nodes[j]) == atoi(nodes[i]))
      search_and_find(nodes, j ^ 1);
  result--;
  used[atoi(nodes[i])] = 0;
}

static int	algo(char **nodes)
{
  int		len;
  int		i;

  len = size_of_tab(nodes);
  if (!(used = malloc(sizeof(int) * len)))
    return (-1);
  for (i = 0; i < len; i += 2)
    {
      result = 0;
      memset(used, 0, sizeof(int) * len);
      search_and_find(nodes, i);
    }
  free(used);
  return (total);
}

int	main(int ac, char **av)
{
  char	**nodes;
  int	result;

  if (ac != 2
      || !(nodes = parse(av[1]))
      || (result = algo(nodes)) == -1)
    return (printf("\n"));
  printf("%i\n", result);
  free(nodes);
  return (0);
}
