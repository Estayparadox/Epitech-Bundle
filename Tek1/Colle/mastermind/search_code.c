/*
** search_code.c for search_code in /home/pereni_j/Colle4
** 
** Made by joseph pereniguez
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu May 21 19:26:12 2015 joseph pereniguez
** Last update Thu May 21 21:55:45 2015 joseph pereniguez
*/

#include "mastermind.h"

void		fail()
{
  my_putstr("Mais tu fais quoi la ! ");
  my_putstr("Tu es le pire du monde mon gars !\n");
}

int		succes()
{
  my_putstr("Bravo ! Tu es le meilleur du monde mon gars !\n");
  exit(0);
}

void		aff_pawn(int y, int n)
{
  my_putstr("Pions bien places : ");
  my_put_nbr(y);
  my_putstr("\nPions mal places : ");
  my_put_nbr(n);
  my_putchar('\n');
}

void		search_code(char *buffer, t_code code)
{
  t_val		val;

  val.i = 0;
  val.j = 0;
  val.y = 0;
  val.n = 0;
  my_pawns_verify(code, buffer);
  my_pawns_verify2(code, buffer);
  while (code.code[val.i])
    {
      while (buffer[val.j])
	{
	  if (code.code[val.i] == buffer[val.j] && val.i == val.j)
	    val.y = val.y + 1;
	  if (code.code[val.i] == buffer[val.j] && val.i != val.j)
	    val.n = val.n + 1;
	  val.j++;
	}
      val.j = 0;
      val.i++;
    }
  if (val.y == my_strlen(code.code))
    succes();
  aff_pawn(val.y, val.n);
}
