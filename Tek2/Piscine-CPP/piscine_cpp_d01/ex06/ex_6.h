/*
** ex_6.h for ex_6 in /home/pereni_j/Rendu/Tek2-Piscine/piscine_cpp_d01/ex06
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri Sep 30 11:59:35 2016 pereniguez joseph
** Last update Fri Sep 30 12:03:26 2016 pereniguez joseph
*/

#ifndef __EX_6_H__
#define __EX_6_H__

typedef union   s_bar
{
  short int     foo;
  short int     bar;
}               t_bar;

typedef struct  s_struct
{
  short int     foo;
  t_bar         bar;
}               t_struct;

typedef union   s_foo
{
  int           bar;
  t_struct	foo;
}               t_foo;

#endif /* __EX_6_H__ */
