/*
** Exo-1.c for Exo-1 in /home/pereni_j/Rendu/piscine_cpp_d09/ex-1
** 
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Thu Jan 14 09:47:28 2016 pereniguez joseph
** Last update Thu Jan 14 19:20:13 2016 pereniguez joseph
*/

#include "Exo-1.h"

static void     CthulhuInitializer(t_cthulhu* this);
static void     KoalaInitializer(t_koala* this, char* _name, char _isALegend);

t_cthulhu*      NewCthulhu()
{
  t_cthulhu	*init;

  init = malloc(sizeof(t_cthulhu));
  if (init)
    CthulhuInitializer(init);
  return init;
}

static void     CthulhuInitializer(t_cthulhu* this)
{
  printf("----\n");
  this->m_name = malloc(8 * sizeof(char));
  strcpy(this->m_name, "Cthulhu");
  this->m_power = 42;
  printf("Building Cthulhu\n");
}

t_koala*        NewKoala(char* name, char _isALegend)
{
  t_koala	*init;

  init = malloc(sizeof(t_koala));
  if (init)
    KoalaInitializer(init, name, _isALegend);
  return init;
}

static void     KoalaInitializer(t_koala* this, char* _name, char _isALegend)
{
  CthulhuInitializer(&this->m_parent);
  this->m_parent.m_name = _name;
  this->m_parent.m_power = (_isALegend ? 42 : 0);
  this->m_isALegend = _isALegend;
  printf("Building %s\n", this->m_parent.m_name);
}

void		PrintPower(t_cthulhu* this)
{
  if (this)
    printf("Power => %d\n", this->m_power);
}

void		Attack(t_cthulhu* this)
{
  if (this->m_power >= 42)
    {
      this->m_power -= 42;
      printf("%s attacks and destroys the city\n", this->m_name);
    }
  else
    printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void		Sleeping(t_cthulhu* this)
{
  this->m_power += 42000;
  printf("%s sleeps\n", this->m_name);
}

void		Eat(t_koala* this)
{
  this->m_parent.m_power += 42;
  printf("%s eats\n", this->m_parent.m_name);
}
