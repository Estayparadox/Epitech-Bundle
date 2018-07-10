/*
** my_strcpy.c for 42sh in /home/arrazo_p/semestre2/SystemeUnix/PSU_2014_minishell2/sources
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Sun Mar  8 03:59:00 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:53:07 2015 Vatinelle Maxime
*/

#include "../42sh.h"

char	*my_strcp(char *s1, char *s2)
{
  char	*dest;
  int	index;
  int	count;

  if ((dest = malloc(sizeof(char)
                     * (my_strlen(s1) * (my_strlen(s2) + 2)))) == NULL)
    return (NULL);
  index = 0;
  count = 0;
  while (s1[index])
    dest[count++] = s1[index++];
  index = 0;
  while (s2[index])
    dest[count++] = s2[index++];
  dest[count] = '\0';
  return (dest);
}
