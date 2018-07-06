#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

static int	tab_empty(char **nodes, int size)
{
  int		i;

  for (i = 0; i < size; ++i)
    if (nodes[i])
      return (0);
  return (1);
}

static void	search_and_remove_buddy(char **nodes, int size, int id) {
  int		i;
  int		searched;

  searched = atoi(nodes[id]);
  nodes[id] = NULL;
  for (i = 0; i < size; ++i)
    {
      if (((nodes[i] && atoi(nodes[i]) == searched)
	   || i == id)
	  && nodes[i ^ 1])
	search_and_remove_buddy(nodes, size, i ^ 1);
    }
}

static int	algo(char **nodes)
{
  int		size;
  int		nb;
  int		i;

  size = size_of_tab(nodes);
  nb = 0;
  while (!tab_empty(nodes, size))
    {
      i = -1;
      while (++i < size)
	if (nodes[i])
	  {
	    search_and_remove_buddy(nodes, size, i);
	    ++nb;
	  }
    }
  return (nb);
}

int	main(int ac, char **av)
{
  char	**nodes;

  if (ac != 2)
    return (printf("\n"));
  if (!(nodes = parse(av[1])))
    return (1);
  printf("%i\n", algo(nodes));
  free(nodes);
  return (0);
}
