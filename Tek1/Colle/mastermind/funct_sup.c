/*
** funct_sup.c for funct_sup in /home/pereni_j/Colle4
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu May 21 21:20:36 2015 joseph pereniguez
** Last update Thu May 21 21:58:21 2015 joseph pereniguez
*/

#include "mastermind.h"

void		my_prompt(int i)
{
  my_putstr("Round ");
  my_put_nbr(i);
  my_putstr("\n>");
}

void		my_puterror_loop(char *str, t_code code)
{
  my_putstr(str);
  (void)code;
  return;
}

void		my_pawns_verify(t_code code, char *prop)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (code.pawn[i])
    {
      while (prop[j])
	{
	  if (prop[j] != code.pawn[i])
	    j++;
	  if (prop[j] == code.pawn[i])
	    {
	      j = 0;
	      i++;
	    }
	  if (prop[j] == '\0')
	    {
	      my_putstr("Mais tu fais quoi la ! Tu es le pire du monde mon gars !\n");
	      my_loop(code);
	    }
	}
    }
}

int            my_pawns_verify2(t_code code, char *prop)
{
  int           i;
  int           j;

  i = 0;
  j = 0;
  while (code.code[i])
    {
      while (prop[j])
        {
          if (prop[j] != code.code[i])
            j++;
          if (prop[j] == code.code[i])
            {
              j = 0;
              i++;
            }
          if (prop[j] == '\0')
            {
              my_putstr("Mais tu fais quoi la ! Tu es le pire du monde mon gars !\n");
              exit(0);
            }
        }
    }
  return (0);
}
