/*
** main.c for main in /home/pereni_j/rendu/PSU_2014_my_select
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Jan 10 10:51:02 2015 Pereniguez Joseph
** Last update Sun Jan 11 15:41:01 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <curses.h>
#include <ncurses.h>
#include <term.h>
#include <sys/ioctl.h>
#include "my.h"

int                     main(int argc, char **argv)
{
  struct termios	term;
  int                   nb;

  nb = 1;
  if (argc >= 2)
    {
      if (tcgetattr(0, &term) == -1)
	return (-1);
      else if ((tgetent(0, "xterm") == 0 || (tgetent(0, "xterm") == -1)))
	my_puterror("[Error]: Terminal error\n");
      else
	{
	  tputs(tgetstr("cl", NULL), 1, call_putchar);
	  raw_mode(&term);
	  while (1)
	    {
	      my_putstr(argv[nb]);
	      nb = nb + 1;
	      my_putchar('\n');
	      while (argc == nb)
		{
		  my_buffer();
		}
	    }
	}
    }
  return (0);
}
