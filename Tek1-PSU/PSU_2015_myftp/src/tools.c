/*
** tools.c for tools in /home/pereni_j/Rendu/PSU_2015_myftp/src
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri May 13 12:47:24 2016 pereniguez joseph
** Last update Fri May 13 12:47:26 2016 pereniguez joseph
*/

#include "server.h"

void    my_putstr(int fd, char *str, int size)
{
  write(fd, str, size);
}

int	my_linelen(char *s)
{
  int		i;
  int		len;

  i = 0;
  len = 0;
  while (s && s[i] && s[i] != '\n')
    {
      len++;
      i++;
    }
  return (len);
}

char	*my_append(char *s1, char **s2)
{
  char		*res;
  char		*tmp;
  char		*res_tmp;

  if ((res = malloc(my_linelen(s1) + my_linelen(*s2) + 1)) == NULL)
    return (NULL);
  res_tmp = s1;
  tmp = res;
  while (s1 && *s1)
    *res++ = *s1++;
  free(res_tmp);
  while (s2 && *(*s2) && *(*s2) != '\n')
    {
      *res++ = *(*s2);
      ++(*s2);
    }
  *res++ = '\0';
  return (tmp);
}

char	*my_memset(char *c, int size)
{
  int		i;

  i = 0;
  while (i <= size)
    c[i++] = '\0';
  return (c);
}

char	*read_till_n(int fd)
{
  int		red;
  char		*res;
  static char	*tmp;
  static char	*c;

  res = NULL;
  red = 0;
  while (1)
    {
      if (!c && !(c = malloc(GNL_BUFSIZ)))
	return (NULL);
      if ((!tmp || !(*tmp)) && (tmp = c)
	  && (c = my_memset(c, GNL_BUFSIZ - 1))
	  && (red = read(fd, c, GNL_BUFSIZ - 1)) <= 0)
	return (res);
      if (red > 0)
	c[red] = '\0';
      res = my_append(res, &tmp);
      if (*tmp && *tmp == '\n')
	{
	  tmp++;
	  return (res);
	}
    }
  return (NULL);
}

char	*get_next_line(int fd)
{
  char	*res;

  if (fd < 0)
    return (NULL);
  res = read_till_n(fd);
  return (res);
}
