/*
** proto5.c for proto5 in /home/valent_g/rendu/rush1
** 
** Made by georges valentin
** Login   <valent_g@epitech.net>
** 
** Started on  Sun Jan  4 21:23:06 2015 georges valentin
** Last update Sun Jan  4 22:02:48 2015 georges valentin
*/
#include <stdlib.h>
#include <stdio.h> 
void    proto51(char *str)
{
  int   i;
  int   j;
  int   a;
  int   b;
  a = 0;
  i = 0;
  b = 0;
  j = 0;

  while(str)
    {
      if(str[i] == ' ')
        {
          a = i + 1;
        }
      if(str[i] == '(')
        {
          b = i - 1;
        }
      i++;
    }
  my_putstr("Déclaration de la fonction ");
  while(a != b)
    {
      my_putchar(str[a]);
      a++;
    }
  my_putstr(" qui prend en parametre ");
}


void proto52(char *str)
{
  int i;
  int a;
  int b;
  char *type;
  char *cmp;
  char *name;
  int j;
  
  j = 0;
  i = 0;
  while(str)
    {
      if(str[i] == '(')
        a = i + 1;
      if(str[i] == ' ')
        b = i - 1;
    }
  cmp = malloc(sizeof(char)*(b - a));
  while(a != b)
    {
      type[j] = str[a];
      a++;
      j++;
    }
  my_strcomp(cmp , "int") == 1 ? (type == "un entier" && i == 1) : 0;
  my_strcomp(cmp, "char") == 1 ? (type == "un caractere" && i == 1) : 0;
  my_strcomp(cmp, "long") == 1 ? (type == "un  entier long" && i == 1) : 0;
  my_strcomp(cmp, "float") == 1 ? (type == "un nombre reel simple" && i == 1) : 0;
  my_strcomp(cmp, "double") == 1 ? (type == "un nombre reel double" && i == 1) : 0;
  my_strcomp(cmp, "short") == 1 ? (type == "un entier court" && i == 1) : 0;
  my_strcomp(cmp, "_") == 1 ? (type == cmp && i == 1) : 0;
  my_strcomp(cmp, "void") == 1 ? (type == "rien" && i == 1) : 0;
  if(i == 1)
    {
      my_putstr(type);
      my_putstr(" et renvoyant un pointeur sur ");
    }
  
}

void	proto53(char *str)
{
  char *cmp;
  char *type;
  int a;
  int i;
  int e;
  int j;
  int b;

  e = 0;
  a = 0;
  i = 0;
  j = 0;
  while(str)
    {
      if(str[i] == ' ')
	e++;
      if(e == 1)
	b = i - 1;
    }
  cmp = malloc(sizeof(char)*(b -a));
  while(a != b)
    {
      cmp[j] = str[a];
      a++;
      j++;
    }
  my_strcomp(cmp , "int") == 1 ? (type == "un entier" && i == 1) : 0;
  my_strcomp(cmp, "char") == 1 ? (type == "un caractere" && i == 1) : 0;
  my_strcomp(cmp, "long") == 1 ? (type == "un  entier long" && i == 1) : 0;
  my_strcomp(cmp, "float") == 1 ? (type == "un nombre reel simple" && i == 1) : 0;
  my_strcomp(cmp, "double") == 1 ? ( type == "un nombre reel double" && i == 1) : 0;
  my_strcomp(cmp, "short") == 1 ? (type == "un entier court" && i == 1) : 0;
  my_strcomp(cmp, "_") == 1 ? (type == cmp && i == 1) : 0;
  my_strcomp(cmp, "void") == 1 ? (type == "rien" && i == 1) : 0;
  if(i == 1)
    {
      my_putstr(type);
      my_putstr(".\n ");
    }
  
}
