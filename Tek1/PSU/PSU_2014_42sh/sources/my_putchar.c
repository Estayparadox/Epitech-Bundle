/*
** my_putchar.c for 42sh in /home/arrazo_p/Systeme_Unix/PSU_2014_minishell1
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Fri Jan 23 14:46:48 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:52:29 2015 Vatinelle Maxime
*/

#include "../42sh.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
