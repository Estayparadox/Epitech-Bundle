/*
** my_strcat.c for 42sh in /home/arrazo_p/semestre2/SystemeUnix/PSU_2014_minishell2
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Wed Mar  4 17:03:52 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:52:47 2015 Vatinelle Maxime
*/

#include "../42sh.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*s3;

  i = 0;
  j = 0;
  s3 = malloc(sizeof(s3) * 4096);
  while (dest[i])
    {
      s3[i] = dest[i];
      i++;
    }
  while (src[j])
    s3[i++] = src[j++];
  s3[i] = '\0';
  return (s3);
}
