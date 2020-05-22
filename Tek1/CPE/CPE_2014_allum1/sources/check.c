#include "allum.h"

int	    check_linezero(int line)
{
  if (line < 0) {
      if ((my_putstr("Error: invalid input ")) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      if ((my_putstr("(positiv number excepted)\n")) == EXIT_FAILURE)
        return (EXIT_FAILURE);

      return (EXIT_FAILURE);
  }

  return (EXIT_SUCCESS);
}

int     check_line(int line, int *map)
{
  if ((check_linezero(line)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (line == 0 || line > 4) {
      if ((my_putstr("Error: this line ")) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      if ((my_putstr("is out of range\n")) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      return (EXIT_FAILURE);
  }

  if (line >= 1 && line <= 4) {
      if (map[line - 1] == 0) {
	    if ((my_putstr("Error: this line is empty\n")) == EXIT_FAILURE)
	        return (EXIT_FAILURE);
	    return (EXIT_FAILURE);
	  }
  }

  return (EXIT_SUCCESS);
}

int     check_match(int match, int *map, int line)
{
  if (match < 0) {
      if ((my_putstr("Error: invalid input ")) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      if ((my_putstr("(positive number expected)\n")) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      return (EXIT_FAILURE);
  }

  if (match == 0) {
      if ((my_putstr("Error: you have to remove ")) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      if ((my_putstr("at least one match\n")) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      return (EXIT_FAILURE);
  }

  if (match > map[line - 1]) {
      if ((my_putstr("Error: not enough ")) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if ((my_putstr("matches on this line\n")) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      return (EXIT_FAILURE);
  }

  return (EXIT_SUCCESS);
}

void    aff_del(int line_rem, int match_rem)
{
  my_putstr("Player removed ");
  my_put_nbr(match_rem);
  my_putstr(" match(es) from line ");
  my_put_nbr(line_rem);
  my_putchar('\n');
}

int     is_over(int *map)
{
  int   nb;
  int   stock;

  stock = 0;
  nb = 0;
  while (stock < 4) {
    nb = nb + map[stock];
    stock++;
  }

  if (nb == 0)
    return (EXIT_SUCCESS);
  else
    return (EXIT_FAILURE);
}
