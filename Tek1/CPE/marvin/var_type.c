/*
** var_type.c for var_type in /home/pereni_j/rendu/marvin
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Sat Jan  3 14:19:28 2015 Pereniguez Joseph
** Last update Sun Jan  4 23:24:15 2015 georges valentin
*/

#include <unistd.h>
#include "my.h"

void	var_type(char *str)
{
  char	*type;
  int	i;
  
  i = 0;
  my_strcomp(str , "int") == 1 ? (type == "entier" && i == 1) : 0; 
  my_strcomp(str, "char") == 1 ? (type == "caractere" && i == 1) : 0;
  my_strcomp(str, "long") == 1 ? (type == "entier long" && i == 1) : 0;
  my_strcomp(str, "float") == 1 ? (type == "nombre reel simple" && i == 1) : 0;
  my_strcomp(str, "double") == 1 ? (type == "nombre reel double" && i == 1) : 0;
  my_strcomp(str, "short") == 1 ? (type == "entier court" && i == 1) : 0;
  if(i == 1) 
    {
      my_putstr("Déclaration de la variable de type");
      my_putstr(type);
      my_putstr(" ");
    }
  else 
    my_putstr(" non pris en charge ou non valable\n");
  exit(0);
}
