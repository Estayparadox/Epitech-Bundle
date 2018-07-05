/*
** verify.c for verify in /home/pereni_j/Rendu/BocalEmblem/II : Path of Radiance
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat May 16 16:56:44 2015 joseph pereniguez
** Last update Sun May 17 17:58:26 2015 joseph pereniguez
*/

#include "playradiance.h"

int             verify_elem(char **line, char *str)
{
  char          **first;
  char          **last;
  char          **elem;
  int           i;

  i = 0;
  first = my_str_to_wordtab(line[0], ' ');
  last = my_str_to_wordtab(line[cpt_y(line) - 1], ' ');
  while (first[i] && last[i])
    {
      if ((my_getnbr(first[i]) > 1 || my_getnbr(first[i]) < 1) ||
          (my_getnbr(last[i]) > 1 || my_getnbr(last[i]) < 1))
        return (-1);
      i++;
    }
  i = 0;
  while (line[i])
    {
      elem = my_str_to_wordtab(line[i], ' ');
      if ((my_getnbr(elem[0]) > 1 || my_getnbr(elem[0]) < 1) ||
          (my_getnbr(elem[cpt_x(str)]) > 1 || my_getnbr(elem[cpt_x(str)]) < 1))
        return (-1);
      i++;
    }
  return (0);
}

int             verify_soldiers(char *str)
{
  t_sold        sold;

  sold.y = 0;
  sold.x = 0;
  sold.line = my_str_to_wordtab(str, '\n');
  while (sold.line[sold.y] != NULL)
    {
      sold.elem = my_str_to_wordtab(sold.line[sold.y], ' ');
      while (sold.elem[sold.x] != NULL)
        {
          if (verify_elem(sold.line, str) == -1 ||
              my_getnbr(sold.elem[sold.x]) > 70)
            {
	      my_puterror("Invalid map file!\n");
	      return (-1);
	    }
          sold.x++;
        }
      sold.x = 0;
      sold.y++;
    }
  return (0);
}

int		verify_extension(char *file)
{
  int		len;

  len = my_strlen(file);
  if (file[len - 1] != 'p' && file[len - 2] != 'a' &&
      file[len - 3] != 'm' && file[len - 4] != '.')
    {
      my_puterror("File isn't a [.map] file!\n");
      return (-1);
    }
  else if (file[len - 1] == 'p' && file[len - 2] == 'a' &&
           file[len - 3] == 'm' && file[len - 4] == '.')
    return (0);
  return (0);
}

int             verify_double(char *str)
{
  char          **tab;
  int           i;
  int           k;

  tab = my_str_to_wordtab_2(str, ' ', '\n');
  i = 0;
  k = 0;
  while (tab[i])
    {
      if (my_getnbr(tab[i]) >= 11 && my_getnbr(tab[i]) <= 70)
        {
          k = i + 1;
          while (tab[k])
            {
              if (my_getnbr(tab[i]) == my_getnbr(tab[k]))
		{
		  my_puterror("Invalid map file, double soldier in file!\n");
		  return (-1);
		}
              k++;
            }
	}
      k = 0;
      i++;
    }
  return (0);
}

int		verify_map(char *file)
{
  int		fd;
  char		buffer[4096];

  if ((fd = open(file, O_RDONLY)) == -1)
    {
      my_puterror("File doesn't exist!\n");
      return (-1);
    }
  else
    {
      read(fd, buffer, 4095);
      buffer[4096] = '\0';
      if (buffer[0] == '\0' || buffer == NULL)
        {
          my_puterror("File is empty!\n");
          return (-1);
        }
      if (verify_extension(file) == -1)
	return (-1);
      else
	{
	  if (verify_soldiers(buffer) == -1 || verify_double(buffer) == -1)
	    return (-1);
	}
    }
  return (0);
}
