/*
** main.c for main in /home/pereni_j/Rendu/BocalEmblem/Path of Radiance
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat May 16 11:19:54 2015 joseph pereniguez
** Last update Sun May 17 21:20:46 2015 Jade Kadri
*/

#include "playradiance.h"

char		*my_memset(char *str)
{
  int		i;

  i = 0;
  while (i < 4096)
    {
      str[i] = 0;
      i = i + 1;
    }
  return (str);
}

int		my_loop(t_map map, int nbr_elem, t_val val)
{
  char		*buffer;
  int		ret;

  buffer = malloc(sizeof(char) * 4096);
  buffer = my_memset(buffer);
  while (42)
    {
      buffer = my_memset(buffer);
      my_putstr(":>");
      buffer = my_memset(buffer);
      ret = read(0, buffer, 4096);
      if (ret == 0)
	{
	  my_putstr("\n");
	  return (0);
	}
      buffer[ret - 1] = '\0';
      if (buffer[0] != '\0')
	my_strategic(buffer, map, nbr_elem, val);
    }
  return (0);
}

int		main(int argc, char **argv)
{
  t_val		val;
  t_map		map;
  char		buffer[4096];
  int		fd;
  int		nbr_elem;

  if (argc != 2)
    my_putstr("Argument error\n");
  else
    if (verify_map(argv[1]) == 0)
      {
	val.name = argv[1];
	fd = open(argv[1], O_RDONLY);
	read(fd, buffer, 4096);
	buffer[4096] = '\0';
	val.x = count_x(buffer) - 1;
	nbr_elem = count_elem(buffer);
	map = map_in_tab(buffer);
	my_loop(map, nbr_elem, val);
      }
  return (0);
}
