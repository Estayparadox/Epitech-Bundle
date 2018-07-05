/*
** my_strlen.c for my_strlen in /home/pereni_j/rendu/Piscine_C_J04
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Oct  2 18:45:51 2014 joseph pereniguez
** Last update Thu Oct  2 19:55:02 2014 joseph pereniguez
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
