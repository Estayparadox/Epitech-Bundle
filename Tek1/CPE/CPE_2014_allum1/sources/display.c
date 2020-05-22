#include "allum.h"

int	    aff_all(int *map)
{
  if ((aff_one(map)) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  if ((aff_two(map)) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  if ((aff_three(map)) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  if ((aff_four(map)) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  return (EXIT_SUCCESS);
}

int	    aff_one(int *map)
{
  if ((my_putstr("*   ")) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (map[0] == 1) {
      if ((my_putstr("|")) == EXIT_FAILURE)
        return (EXIT_FAILURE);
  }
  else
    if ((my_putstr(" ")) == EXIT_FAILURE)
        return (EXIT_FAILURE);
  if ((my_putstr("   *\n")) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  return (EXIT_SUCCESS);
}

int	aff_two(int *map)
{
  int	i;
  int	end;

  end = 5;
  i = 0;
  if ((my_putstr("*  ")) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  if (map[1] != 0) {
      while (i < map[1]) {
	    if ((my_putstr("|")) == EXIT_FAILURE)
	        return (EXIT_FAILURE);
	    ++i;
	    --end;
	  }
  }

  i = 0;
  while (i++ < end)
    if ((my_putstr(" ")) == EXIT_FAILURE)
      return (EXIT_FAILURE);

  if ((my_putstr("*\n")) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  return (EXIT_SUCCESS);
}

int	aff_three(int *map)
{
  int	i;
  int	end;

  end = 6;
  i = 0;
  if ((my_putstr("* ")) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (map[2] != 0) {
      while (i < map[2]) {
          if ((my_putstr("|")) == EXIT_FAILURE)
            return (EXIT_FAILURE);
          ++i;
          --end;
	  }
  }

  i = 0;
  while (i++ < end)
    if ((my_putstr(" ")) == EXIT_FAILURE)
	    return (EXIT_FAILURE);

  if ((my_putstr("*\n")) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  return (EXIT_SUCCESS);
}

int	aff_four(int *map)
{
  int	i;
  int	end;

  end = 7;
  i = 0;
  if ((my_putstr("*")) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (map[3] != 0) {
    while (i < map[3]) {
	  if ((my_putstr("|")) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  ++i;
	}
  }

  while (i++ < end)
    if ((my_putstr(" ")) == EXIT_FAILURE)
      return (EXIT_FAILURE);

  if ((my_putstr("*\n")) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  return (EXIT_SUCCESS);
}
