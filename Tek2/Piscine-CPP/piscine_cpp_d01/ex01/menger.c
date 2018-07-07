/*
** menger.c for menger in /home/pereni_j/Rendu/piscine_cpp_d01/ex01
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Wed Jan  6 13:47:11 2016 pereniguez joseph
** Last update Wed Jan  6 15:41:06 2016 pereniguez joseph
*/

#include <stdio.h>

int     my_getnbr(char *str)
{
  int   nb = 0;
  int   i = 1;

  while (*str == '+' || *str == '-')
    if (*str == '-')
      {
	i = i * -1;
	str = str + 1;
      }
  while (*str != '\0')
    {
      if (*str >= '0' && *str <= '9')
	{
          nb = nb * 10;
          nb = nb + *str - '0';
          str = str + 1;
	}
      else
        return (nb * i);
    }
  return (nb * i);
}

void	aff_line(int size)
{
  if (size >= 0 && size <= 9)
    printf("00%d", size);
  else if (size >= 10 && size <= 99)
    printf("0%d", size);
  else
    printf("%d", size);
}

void	writter(int size, int level, int x, int y)
{
  int	i;

  i = 0;
  if (!(size % 3) && level > 0 && level < size)
    {
      i = size / 3;
      aff_line(i);
      printf(" ");
      aff_line(i + x);
      printf(" ");
      aff_line(i + y);
      printf("\n");
      level--;
      writter(i, level, x, y);
      writter(i, level, x, y + i);
      writter(i, level, x, y + 2 * i);
      writter(i, level, x + i, y);
      writter(i, level, x + i, y + 2 * i);
      writter(i, level, x + 2 * i, y);
      writter(i, level, x + 2 * i, y + i);
      writter(i, level, x + 2 * i, y + 2 * i);
    }
}
