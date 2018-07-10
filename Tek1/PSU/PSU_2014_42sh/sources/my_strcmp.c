/*
** my_strcmp.c for 42sh in /home/arrazo_p/Systeme_Unix/PSU_2014_minishell1/sources
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Mon Jan 26 18:32:27 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:52:56 2015 Vatinelle Maxime
*/

#include "../42sh.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && s2[i])
    i++;
  if (!s1[i] && !s2[i])
    return (0);
  return (1);
}
