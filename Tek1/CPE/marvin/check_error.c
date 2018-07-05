/*
** check_error.c for check_error in /home/pereni_j/rendu/marvin
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sun Jan  4 13:44:03 2015 Pereniguez Joseph
** Last update Sun Jan  4 23:09:56 2015 georges valentin
*/

#include <unistd.h>

int	check_param(char *str)
{
  int	a;
  int	b;
  int	i;
  
  i = 0;
  a = 0;
  b = 0;
  while (str[i])
    {
      if (str[i] == '(')
	a = a + 1;
      if (str[i] == ')')
	b = b + 1;
      i = i + 1;
    }
  if (a != b)
    {
      my_putstr("erreur: parenthese manquante\n");
      return (0);
    }
}

int	check_error(char *str)
{
  int	i;
  
  i = 0;
  if (str[0] == ' ')
    my_putstr("erreur: espace avant la déclaration\n");
  while (str[i] != '\0')
    {
      if (str[i] == ' ' && str[i + 1] == ' ')
	my_putstr("erreur: espaces consecutifs\n");
      else if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
	my_putstr("erreur: une '*' suffit largement\n");
      else if (str[i] == '(' && str[i - 1] == ' '
	       || str[i] == ')' && str[i - 1] == ' ')
	my_putstr("erreur: espace avant une parenthese\n");
      else if (str[i] == '(' && str[i + 1] == ' '
	       || str[i] == ')' && str[i + 1] == ' ')
	my_putstr("erreur: espace apres une parenthese\n");
      else if (str[i] == ';' && str[i + 1] != '\0')
	my_putstr("erreur: charactere(s) en trop apres le ';' ou charactere ';' mal placé\n");
      else if (str[i + 1] == '\0' && str[i] != ';')
	my_putstr("erreur: charactere ';' manquant ou charactere ';' mal placé\n");
      else if (str[i] == ';' && str[i - 1] == ' ')
	my_putstr("erreur: espace avant le charactere ';'\n");
      else if (str[i] == '[' && str[i + 1] != ']' || str[i] == ']' && str[i - 1] != '[')
	my_putstr("erreur: crochet manquant\n");
      else if (str[i] == ',' && str[i + 1] != ' ')
	my_putstr("erreur: espace manquant apres le charactere ','\n");
      i = i + 1;
    }
}
