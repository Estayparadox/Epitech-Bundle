/*
** func_ptr.c for func_ptr in /home/pereni_j/Rendu/piscine_cpp_d02m/ex03
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Thu Jan  7 12:37:53 2016 pereniguez joseph
** Last update Sat Oct  1 11:52:41 2016 pereniguez joseph
*/

#include "func_ptr.h"

void	print_normal(char *str)
{
  printf("%s\n", str);
}

void	print_reverse(char *str)
{
  int	a = strlen(str) - 1;

  while (a > 0)
    {
      printf("%c", str[a]);
      a--;
    }
  printf("%c\n", str[a]);
}

void	print_upper(char *str)
{
  int	i = 0;
  char	*ptr = malloc((strlen(str) + 1) * sizeof(char));

  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	{
	  while (str[i] >= 'a' && str[i] <= 'z')
	    {
	      ptr[i] = str[i] - 32;
	      i++;
	    }
	}
      ptr[i] = str[i];
      i++;
    }
  printf("%s\n", tmp);
}

void	print_42(char *str)
{
  (void)str;

  printf("42\n");
}

void	(*func_action[4])(char*) = {print_normal,
				    print_reverse,
				    print_upper,
				    print_42};

void	do_action(t_action action, char *str)
{
  func_action[action](str);
}
