#include "allum.h"

int	   *fill_map(int *map)
{
    map[0] = 1;
    map[1] = 3;
    map[2] = 5;
    map[3] = 7;
    map[4] = -1;
    return (map);
}

int	display_board(int *map)
{
  if ((my_putstr("*********\n")) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  aff_all(map);
  if ((my_putstr("*********\n")) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  return (EXIT_SUCCESS);
}

int	main()
{
  int   *map;

  if ((map = malloc(sizeof(int) * 5)) == NULL)
    return (EXIT_FAILURE);

  map = fill_map(map);
  if ((display_board(map)) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  if ((play(map, 0)) == EXIT_FAILURE)
    return (EXIT_FAILURE);

  return (EXIT_SUCCESS);
}
