#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	size_of_word(char *s)
{
  int		i;

  for (i = 0; s[i] && !strchr(" \t", s[i]); ++i);
  return (i);
}

static int	count_words(char *s)
{
  int		i;
  int		count;

  for (i = count = 0; (unsigned)i < strlen(s); i += size_of_word(s + i), ++count)
    while (strchr(" \t", s[i]))
      ++i;
  return (count);
}

static void	swap(char **a, char **b)
{
  char		*tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

static void	sort(char **tab)
{
  int		i;
  int		j;

  for (i = 0; tab[i]; ++i)
    for (j = i; tab[j]; ++j)
      if (strcasecmp(tab[i], tab[j]) > 0)
	swap(&tab[i], &tab[j]);
}

static void	display(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i])
    {
      write(1, tab[i], strlen(tab[i]));
      if (tab[i + 1])
	write(1, " ", 1);
    }
  write(1, "\n", 1);
}

static int	exec(char *s)
{
  char		**tab;
  int		words;
  int		i;
  int		j;

  words = count_words(s);
  if (!(tab = malloc((sizeof(char *) * (1 + words)))))
    return (1);
  tab[words] = NULL;
  i = -1;
  j = -1;
  while (s[++i]) {
    if (!i || ((s[i - 1] == 0 || strchr(" \t", s[i - 1]))
	       && !strchr(" \t", s[i])))
      tab[++j] = s + i;
    else if (strchr(" \t", s[i]))
      s[i] = 0;
  }
  sort(tab);
  display(tab);
  free(tab);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac != 2)
    return (write(1, "\n", 1));
  while (strchr(" \t", av[1][0]))
    ++av[1];
  return (exec(av[1]));
}
