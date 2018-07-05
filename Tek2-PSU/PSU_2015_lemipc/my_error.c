/*
** my_error.c for  in /home/vatine_m/PSU/PSU_2015_lemipc
** 
** Made by vatinelle maxime
** Login   <vatine_m@epitech.net>
** 
** Started on  Sat Mar 26 10:10:27 2016 vatinelle maxime
** Last update Sat Mar 26 13:27:53 2016 vatinelle maxime
*/

#include "lemipc.h"

void		my_error(char *str)
{
  write(2, str, strlen(str));
  exit (0);
}
