#include "allum.h"

char            *my_strncpy(char *dest, char *src, int n)
{
  int           i;

  i = 0;
  while (dest && src && src[i] && i < n) {
      dest[i] = src[i];
      ++i;
  }
  dest[i] = 0;

  return (dest);
}

char            *get_line(char *str, int i, char *buff, int *start)
{
  t_gnl	        new;

  new.i = my_strlen(str);
  if ((new.str = malloc(sizeof(char) * (new.i + i + 1))) == NULL)
    return (NULL);
  if (str)
    new.str = my_strncpy(new.str, str, new.i);
  my_strncpy(new.str + new.i, buff + *start, i);
  if (str)
    free(str);
  *start = * start + i + 1;

  return (new.str);
}

char            *get_next_line(const int fd)
{
  static char   buff[READ_SIZE];
  static int    bufflenght = 0;
  static int    start;
  t_gnl		    gnl;

  gnl.str = 0;
  gnl.i = 0;
  while (42) {
    if (bufflenght <= start) {
        start = 0;
            if (!(bufflenght = read(fd, buff, READ_SIZE)))
                return (gnl.str);
            if (bufflenght == -1)
                return (NULL);
            gnl.i = 0;
    }
    if (buff[start + gnl.i] == '\n')
        return (gnl.str = get_line(gnl.str, gnl.i, buff, &start));
    if (start + gnl.i == bufflenght - 1)
        gnl.str = get_line(gnl.str, gnl.i + 1, buff, &start);
    ++gnl.i;
  }
}
