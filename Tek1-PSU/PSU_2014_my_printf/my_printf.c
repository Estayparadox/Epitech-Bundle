/*
** my_printf.c for my_printf in /home/pereni_j/rendu/PSU_2014_my_printf
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** *
** Started on  Tue Nov 11 15:15:24 2014 Pereniguez Joseph
** Last update Sun Nov 16 18:13:28 2014 Pereniguez Joseph
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

char	*tab(char *tab)
{
  tab = malloc(sizeof(char) * 11);

  tab[0] = 'd';
  tab[1] = 'o';
  tab[2] = 'u';
  tab[3] = 'x';
  tab[4] = 'X';
  tab[5] = 'c';
  tab[6] = 's';
  tab[7] = 'p';
  tab[8] = 'b';
  tab[9] = 'S';
  tab[10] = 'i';
  return (tab);
}

flag	*tab_fonction(flag *tab_fonction)
{
  tab_fonction = malloc(sizeof(flag) * 11);

  tab_fonction[0] = fonction_d;
  tab_fonction[1] = fonction_o;
  tab_fonction[2] = fonction_u;
  tab_fonction[3] = fonction_x;
  tab_fonction[4] = fonction_X;
  tab_fonction[5] = fonction_c;
  tab_fonction[6] = fonction_s;
  tab_fonction[7] = fonction_p;
  tab_fonction[8] = fonction_b;
  tab_fonction[9] = fonction_S;
  tab_fonction[10] = fonction_d;
  return (tab_fonction);
}

int	direct(char *fonct, char *flag_tab, flag *tableau, int a, va_list liste)
{
  int	b;

  b = 0;
  while ((fonct[a] != flag_tab[b]) && (flag_tab[b] != '\0'))
    b = b + 1;
  if (flag_tab[b] == '\0')
    {
      my_putchar('%');
      my_putchar(fonct[a]);
    }
  else
    tableau[b](liste);
  return (a);
}

int	my_printf(char *fonction, ...)
{
  va_list	ap;
  flag	*tableau;
  char	*flag_tab;
  int	a;

  va_start(ap, fonction);
  tableau = tab_fonction(tableau);
  flag_tab = tab(flag_tab);
  a = 0;
  while (fonction[a])
    {
      if (fonction[a] == '%')
        {
          a = a + 1;
          if (fonction[a] == '%')
            my_putchar('%');
          else
            direct(fonction, flag_tab, tableau, a, ap);
        }
      else
        my_putchar(fonction[a]);
      a = a + 1;
    }
}
