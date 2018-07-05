/*
** my_pow.c for my_pow in /home/pereni_j/rendu/PSU_2014_minitalk/serveur
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Mar 18 11:42:24 2015 Pereniguez Joseph
** Last update Wed Mar 18 11:45:11 2015 Pereniguez Joseph
*/

#include "my_client.h"

int		my_pow(int nb, int pow)
{
  if (pow > 0)
    return nb *= my_pow(nb, pow - 1);
  return (1);
}
