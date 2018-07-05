/*
** my_puterror.c for my_puterror in /home/pereni_j/rendu/CPE_2014_bsq
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jan 14 13:54:52 2015 Pereniguez Joseph
** Last update Sun Jan 18 20:34:04 2015 Pereniguez Joseph
*/

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

void     my_puterror(char c)
{
  write(2, &c, 1);
}
