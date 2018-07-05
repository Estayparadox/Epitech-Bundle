/*
** funct.c for  in /home/guarni_l/epitech/PSU_2015_zappy/src_server
**
** Made by Luca Guarnieri
** Login   <guarni_l@epitech.net>
**
** Started on  Sun Jun 26 13:42:20 2016 Luca Guarnieri
** Last update Sun Jun 26 21:36:56 2016 pereniguez joseph
*/

#include "head/funct.h"

void		print_usage()
{
  char		*str;
  char		*str2;
  char		*str3;

  str = "Usage: ./zappy_server -n 'team_name' [-p 'port_nbr'] ";
  str2 = "[-x 'world_width'] [-y 'world_height'] ";
  str3 = "[-c 'client_nbr'] [-t 'time_exec'] [-z to print map]\n";
  my_puterror(str);
  my_puterror(str2);
  my_puterror(str3);
  exit(-1);
}

int		is_number(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	i = i + 1;
      else
	return (-1);
    }
  return (0);
}

char		**strtabcpy(int argc, char **argv)
{
  char		**tab;
  int		i;

  i = 0;
  tab = xmalloc(sizeof(char *) * argc + 1);
  while (argv[i])
    {
      tab[i] = xmalloc(sizeof(char) * (strlen(argv[i]) + 1));
      strcpy(tab[i], argv[i]);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
