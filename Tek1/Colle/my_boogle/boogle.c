/*
** boogle.c for boogle in /home/pereni_j/Colle_6
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jun  2 18:35:03 2015 joseph pereniguez
** Last update Tue Jun  2 22:01:40 2015 joseph pereniguez
*/

#include "my_boogle.h"

char		*my_memset(char *buffer)
{
  int		i;

  i = 0;
  while (buffer[i])
    {
      buffer[i] = 0;
      i++;
    }
  return (buffer);
}

int		look_at_char(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 'a' || str[i] > 'z')
	{
	  put_error(str);
	  return (-1);
	}
      i++;
    }
  return (0);
}

void		put_error(char *buffer)
{
  my_putstr("Le mot '");
  my_putstr(buffer);
  my_putstr("' n'est pas dans la grille.\n");
}

void		classic_boogle()
{
  char		*buffer;
  char		*str;

  str = aff_rand_str();
  buffer = malloc(sizeof(char) * 4096);
  while (42)
    {
      buffer = my_memset(buffer);
      print_grid(str);
      my_putstr("> ");
      read(0, buffer, 4095);
      buffer[my_strlen(buffer) - 1] = '\0';
      if (buffer[0] != '\0' || buffer[0] != '\n')
	{
	  if (look_at_char(buffer) == 0)
	    {
	      if (try(str, buffer) == 0)
		str = after_check(str, buffer);
	      else
		put_error(buffer);
	    }
	}
      buffer = my_memset(buffer);
    }
}

void		boogle_g(char *str)
{
  char		*buffer;

  buffer = malloc(sizeof(char) * 4096);
  if (my_strlen(str) < 16 || my_strlen(str) > 16)
    my_puterror("Invalid grid!\n");
  while (42)
    {
      buffer = my_memset(buffer);
      print_grid(str);
      my_putstr("> ");
      read(0, buffer, 4095);
      buffer[my_strlen(buffer) - 1] = '\0';
      if (buffer[0] != '\0' || buffer[0] != '\n')
	{
	  if (look_at_char(buffer) == 0)
	    {
	      if (try(str, buffer) == 0)
		str = after_check(str, buffer);
	      else
		put_error(buffer);
	    }
	}
      buffer = my_memset(buffer);
    }
}
