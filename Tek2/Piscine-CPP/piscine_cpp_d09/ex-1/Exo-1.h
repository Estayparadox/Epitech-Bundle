/*
** Exo-1.h for Exo-1 in /home/pereni_j/Rendu/piscine_cpp_d09/ex-1
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jan 14 09:47:41 2016 pereniguez joseph
** Last update Thu Jan 14 19:10:00 2016 pereniguez joseph
*/

#ifndef __EXO_1_H__
# define __EXO_1_H__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct	s_cthulhu
{
  int		m_power;
  char*		m_name;

}t_cthulhu;

typedef struct	s_koala
{
  t_cthulhu	m_parent;
  char		m_isALegend;

}t_koala;

t_cthulhu*      NewCthulhu();
void            PrintPower(t_cthulhu* this);
void            Attack(t_cthulhu* this);
void            Sleeping(t_cthulhu* this);
t_koala*	NewKoala(char* name, char _isALegend);
void		Eat(t_koala* this);

#endif /* __EXO_1_H__ */
