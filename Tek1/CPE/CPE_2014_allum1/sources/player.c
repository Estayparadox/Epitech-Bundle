#include "allum.h"

int     is_number(char *buffer)
{
  int   i;

  i = 0;
  while (buffer && buffer[i]) {
      if ((buffer[i] >= '0' && buffer[i] <= '9') || buffer[i] == '-')
        ++i;
      else {
	    if ((my_putstr("Error: invalid input ")) == EXIT_FAILURE)
	        return (EXIT_FAILURE);
	    if ((my_putstr("(positiv number expected)\n")) == EXIT_FAILURE)
	        return (EXIT_FAILURE);
	    return (EXIT_FAILURE);
      }
  }

  return (EXIT_SUCCESS);
}

int	    get_nb_line(int *map, t_play *turn)
{
  turn->nb_line = 0;
  while (turn->nb_line == 0) {
      my_putstr("Line: ");
      turn->buffer = get_next_line(0);
      if (turn->buffer == NULL)
        return (EXIT_FAILURE);
      if (is_number(turn->buffer) == EXIT_FAILURE)
        turn->nb_line = 0;
      else {
	    turn->nb_line = my_getnbr(turn->buffer);
	  if ((check_line(turn->nb_line, map)) == EXIT_FAILURE)
	    turn->nb_line = 0;
	  }
  }

  return (EXIT_SUCCESS);
}

int	get_nb_matches(int *map, t_play *turn)
{
  turn->nb_matches = 0;
  while (turn->nb_matches == 0) {
      my_putstr("Matches: ");
      turn->buffer = get_next_line(0);
      if (turn->buffer == NULL)
	    return (EXIT_FAILURE);
      if (is_number(turn->buffer) == EXIT_FAILURE)
        turn->nb_matches = 0;
      else {
          turn->nb_matches = my_getnbr(turn->buffer);
          if ((check_match(turn->nb_matches, map, turn->nb_line)) == EXIT_FAILURE) {
              turn->nb_line = 0;
              turn->nb_matches = 0;
              get_nb_line(map, turn);
          }
	  }
  }

  return (EXIT_SUCCESS);
}

int	        play(int *map, int bin)
{
  t_play	turn;

  if (bin == 0)
    if ((my_putstr("\nYour turn:\n")) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  if ((get_nb_line(map, &turn)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((get_nb_matches(map, &turn)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  map[turn.nb_line - 1] = map[turn.nb_line - 1] - turn.nb_matches;
  aff_del(turn.nb_line, turn.nb_matches);
  display_board(map);
  if ((is_over(map)) == EXIT_FAILURE)
    ai(map, 1, 1);
  else
    if ((my_putstr("You lost, too bad..\n")) == EXIT_FAILURE)
      return (EXIT_FAILURE);

  return (EXIT_SUCCESS);
}
