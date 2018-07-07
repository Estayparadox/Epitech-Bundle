//
// AEnemy.cpp for AEnemy in /home/pereni_j/Rendu/piscine_cpp_d10/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Fri Jan 15 23:17:54 2016 pereniguez joseph
// Last update Sat Jan 16 00:46:00 2016 pereniguez joseph
//

#include "AEnemy.hh"

AEnemy::AEnemy(int hp, std::string const &type) : _HP(hp), _TYPE(type)
{
}

AEnemy::~AEnemy()
{
}

int			AEnemy::getHP() const
{
  return _HP;
}

std::string const	&AEnemy::getType() const
{
  return _TYPE;
}

void			AEnemy::takeDamage(int damage)
{
  if (damage > 0)
    _HP -= damage;
}
