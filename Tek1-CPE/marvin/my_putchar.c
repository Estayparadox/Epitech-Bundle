/*
** my_putchar.c for my_putchar in /home/valent_g/rendu/Piscine_C_J07
** 
** Made by georges valentin
** Login   <valent_g@epitech.net>
** 
** Started on  Wed Oct  8 10:08:57 2014 georges valentin
** Last update Sun Jan  4 23:39:30 2015 georges valentin
*/

#include "my.h"

void	my_putchar (char c)
{
  write (1, &c, 1);
}
