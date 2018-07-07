/*
** main.c for main in /home/pereni_j/Rendu/piscine_cpp_d01/ex01
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jan  6 13:46:56 2016 pereniguez joseph
** Last update Wed Jan  6 20:39:41 2016 pereniguez joseph
*/

#include <stdio.h>

int	my_getnbr(char *str);
void	writter(int i, int level, int x, int y);

int	main(int argc, char **argv)
{
  if (argc == 3)
    {
      if (my_getnbr(argv[2]) < my_getnbr(argv[1]))
	{
	  writter(my_getnbr(argv[1]), my_getnbr(argv[2]), 0, 0);
	}
    }
  return (0);
}
