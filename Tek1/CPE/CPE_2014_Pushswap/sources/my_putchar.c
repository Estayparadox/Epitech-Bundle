/*
** my_putchar.c for my_putchar in /home/pereni_j/rendu/CPE_2014_Pushswap
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sun Dec 14 20:26:50 2014 Pereniguez Joseph
** Last update Sun Dec 14 20:27:41 2014 Pereniguez Joseph
*/

#include <unistd.h>
#include "pushswap.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
