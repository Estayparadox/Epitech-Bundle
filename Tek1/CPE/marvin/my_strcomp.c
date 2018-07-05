/*
** strcomp.c for strcomp in /home/valent_g/rendu/rush1
** 
** Made by georges valentin
** Login   <valent_g@epitech.net>
** 
** Started on  Sun Jan  4 22:05:18 2015 georges valentin
** Last update Sun Jan  4 23:22:13 2015 georges valentin
*/

int	my_strcomp(char *src, char *src1)
{
  int i;

  i = 0;
  while (src1[i] != '\0' && src[i] != '\0')
    {
      if (src1[i] != src[i])
	return (1);
      i++;
    }
  if (src1[i] == '\0' && src[i] == '\0')
    return (0);
  return (1);
}
