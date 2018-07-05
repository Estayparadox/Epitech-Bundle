/*
** my_puterror.c for my_puterror in /home/pereni_j/rendu/PSU_2014_my_select
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Fri Jan  9 12:00:49 2015 Pereniguez Joseph
** Last update Sun Jan 11 15:39:42 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  exit(0);
}
