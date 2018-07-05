/*
** my_putstr.c for my_putstr in /home/pereni_j/rendu/Piscine_C_J04
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Oct  2 16:28:10 2014 joseph pereniguez
** Last update Tue Oct 14 16:11:58 2014 joseph pereniguez
*/

int	my_putstr(char *str)
{
  char	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
