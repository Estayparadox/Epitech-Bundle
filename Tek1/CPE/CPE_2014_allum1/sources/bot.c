#include "allum.h"

int	    aff_ai(int match, int line, int *map)
{
  if ((my_putstr("AI removed ")) ==EXIT_FAILURE)
    return (EXIT_FAILURE);

  my_put_nbr(match);
  if ((my_putstr(" match(es) from line ")) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  my_put_nbr(line + 1);
  if ((my_putchar('\n')) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  map[line] -= match;
  display_board(map);

  if ((is_over(map)) == EXIT_FAILURE)
    play(map, 0);
  else {
    if ((my_putstr("I lost.. snif.. but I'll ")) ==EXIT_FAILURE)
	    return (EXIT_FAILURE);

    if ((my_putstr("get you next time!!\n")) ==EXIT_FAILURE)
        return (EXIT_FAILURE);
    }

  return (EXIT_SUCCESS);
}



int	    ai(int *map, int line, int match)
{
  if ((my_putstr("\nAI's turn...\n")) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  srand(time(NULL));
  line = 0;
  while (line == 0) {
    line = rand() % 4;
    if (map[line] == 0)
        line = 0;
  }

  match = 0;
  while (match == 0)  {
    match = rand() % map[line];
    if (map[line] == 1)
	    match = 1;
    if (match > map[line])
        match = 0;
  }

  if ((aff_ai(match, line, map)) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  return (EXIT_SUCCESS);
}
