/*
** my_buffer.c for my_buffer in /home/pereni_j/rendu/PSU_2014_my_select
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Jan 10 15:06:21 2015 Pereniguez Joseph
** Last update Sun Jan 11 15:38:17 2015 Pereniguez Joseph
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int		my_buffer()
{
  char			buffer[3];
  struct termios	term;

  while (1)
    {
      read(1, buffer, 3);
      if (buffer[0] == 27 && buffer[1] == 0
	  && buffer[2] == 0 && buffer[3] == 0)
	{
	  end_raw_mode(&term);
	  exit (0);
	}
      else
	{
	  my_putstr("[Unknown command] >Please press 'ESC' to exit<\n");
	}
      buffer[0] = 0;
      buffer[1] = 0;
      buffer[2] = 0;
      buffer[3] = 0;
    }
  return (0);
}
