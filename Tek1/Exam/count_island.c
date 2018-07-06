#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int	getfilelen(char *filename)
{
  FILE		*file;
  char		*line = NULL;
  int		i = 0;
  size_t	len = 1024;

  if (!(file = fopen(filename, "r")))
    return (-1);
  while (getline(&line, &len, file) != -1)
    {
      ++i;
      free(line);
      line = NULL;
    }
  free(line);
  return (i);
}

static char	**getfile(char *filename)
{
  int		filelen;
  FILE		*file;
  char		*line = NULL;
  size_t	len = 1024;
  int		i = 0;
  char		**buf;

  if ((filelen = getfilelen(filename)) == -1
      || !(buf = malloc((filelen + 1) * sizeof(char *)))
      || !(file = fopen(filename, "r")))
    return (NULL);
  memset(buf, 0, filelen + 1);
  i = -1;
  while (++i < filelen && getline(&line, &len, file) != -1)
    {
      buf[i] = line;
      line = NULL;
    }
  free(line);
  return (buf);
}

static void	print_buf(char **buf)
{
  int		i;

  for (i = 0; buf[i]; ++i)
    printf("%s", buf[i]);
}

static void	free_buf(char **buf)
{
  int		i;

  for (i = 0; buf[i]; ++i)
    free(buf[i]);
  free(buf);
}

static void	create_island(char **buf, int i, int j, int k)
{
  buf[i][j] = k + '0';
  if (i > 0 && buf[i - 1][j] == 'X')
    create_island(buf, i - 1, j, k);
  if (buf[i + 1] && buf[i + 1][j] == 'X')
    create_island(buf, i + 1, j, k);
  if (j > 0 && buf[i][j - 1] == 'X')
    create_island(buf, i, j - 1, k);
  if (buf[i][j + 1] && buf[i][j + 1] == 'X')
    create_island(buf, i, j + 1, k);
}

static void	find_island(char **buf)
{
  int		i, j, k;

  k = 0;
  for (i = 0; buf[i]; ++i)
    for (j = 0; buf[i][j] && buf[i][j] != '\n'; ++j)
      if (buf[i][j] == 'X')
	create_island(buf, i, j, k++);
}

int		main(int ac, char **av)
{
  char **file;

  if (ac < 2
      || !(file = getfile(av[1])))
    return (printf("\n"));
  find_island(file);
  print_buf(file);
  free_buf(file);
  return (0);
}
