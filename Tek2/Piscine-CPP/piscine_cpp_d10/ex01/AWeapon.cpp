//
// AWeapon.cpp for AWeapon in /home/pereni_j/Rendu/piscine_cpp_d10/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Fri Jan 15 23:33:40 2016 pereniguez joseph
// Last update Fri Jan 15 23:37:54 2016 pereniguez joseph
//

#include "AWeapon.hh"

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : NAME(name), APCOST(apcost), DAMAGE(damage)
{
}

AWeapon::~AWeapon()
{
}

std::string const	&AWeapon::getName() const
{
  return this->NAME;
}

int			AWeapon::getAPCost() const
{
  return this->APCOST;
}

int			AWeapon::getDamage() const
{
  return this->DAMAGE;
}
