/*
** main.c for main in /home/pereni_j/Colle_6
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Jun  2 18:13:23 2015 joseph pereniguez
** Last update Tue Jun  2 21:49:48 2015 joseph pereniguez
*/

#include "my_boogle.h"

int		my_puterror(char *str)
{
  my_putstr(str);
  exit(0);
}

int		check_char(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 'a' || str[i] > 'z')
	return (-1);
      i++;
    }
  return (0);
}

int		main(int argc, char **argv)
{
  if (argc < 3)
    classic_boogle();
  else if (argc == 3 && argv[1][0] == '-' && argv[1][1] == 'g' &&
      argv[1][2] == '\0')
    {
      if (check_char(argv[2]) == -1)
      	my_puterror("Invalid grid!\n");
      boogle_g(argv[2]);
    }
  else if (argc > 3)
    return (0);
  return (0);
}
