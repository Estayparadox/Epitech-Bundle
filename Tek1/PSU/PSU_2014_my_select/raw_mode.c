/*
** raw_mode.c for raw_mode in /home/pereni_j/rendu/PSU_2014_my_select
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan  9 11:25:18 2015 Pereniguez Joseph
** Last update Sat Jan 10 16:21:44 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <curses.h>
#include "my.h"

int	raw_mode(struct termios *term)
{
  if (tcgetattr(0, term) ==-1)
    return (-1);
  term->c_lflag &= ~(ICANON);
  term->c_lflag &= ~(ECHO);
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  if (tcsetattr(0, 0, term) == -1)
    return (-1);
  return (0);
}

int     end_raw_mode(struct termios *term)
{
  if (tcgetattr(0, term) ==-1)
    return (-1);
  term->c_lflag = (ICANON | ECHO);
  if (tcsetattr(0, 0, term) == -1)
    return (-1);
  return (0);
}
