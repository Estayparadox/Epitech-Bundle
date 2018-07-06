#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

static void	display(char **tab)
{
  int		i;

  for (i = 1; tab[i]; ++i)
    printf("%s ", tab[i]);
  printf("%s\n", *tab);
}

static int	parse(char *s)
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
  while (s[++i])
    {
      if (!i || ((s[i - 1] == 0 || strchr(" \t", s[i - 1]))
		 && !strchr(" \t", s[i])))
	tab[++j] = s + i;
      else if (strchr(" \t", s[i]))
	s[i] = 0;
    }
  display(tab);
  free(tab);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac != 2)
    return (printf("\n"));
  while (strchr(" \t", *av[1]))
    ++av[1];
  return (parse(av[1]));
}
