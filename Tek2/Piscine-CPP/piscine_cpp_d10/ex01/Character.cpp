//
// Character.cpp for Character in /home/pereni_j/Rendu/piscine_cpp_d10/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Fri Jan 15 23:52:50 2016 pereniguez joseph
// Last update Sat Jan 16 00:52:35 2016 pereniguez joseph
//

#include "Character.hh"

Character::Character(std::string const &name) : _NAME(name), _AP(40), _CWEAPON(NULL)
{
}

Character::~Character()
{
}

std::ostream&		operator<<(std::ostream & os, Character const & k)
{
  os << k.getName() << " has " << k.getAP() << " AP and ";
  if (k.getWeapon())
    os << "wields a " << k.getWeapon()->getName();
  else
    os << "is unarmed";
  os << std::endl;
  return os;
}

void			Character::recoverAP()
{
  _AP += 10;
  if (_AP > 40)
    _AP = 40;
}

void			Character::equip(AWeapon *weapon)
{
  _CWEAPON = weapon;
}

std::string const	&Character::getName() const
{
  return _NAME;
}

AWeapon			*Character::getWeapon() const
{
  return _CWEAPON;
}

int			Character::getAP() const
{
  return _AP;
}

bool			Character::checkif(int mana)
{
  if (_AP >= mana)
    {
      _AP -= mana;
      return true;
    }
  return false;
}

void			Character::attack(AEnemy *enemy)
{
  if (_CWEAPON && enemy)
    {
      if (checkif(_CWEAPON->getAPCost()))
	{
	  std::cout << _NAME << " attacks " << enemy->getType() << " with a " << _CWEAPON->getName() << std::endl;
	  _CWEAPON->attack();
	  enemy->takeDamage(_CWEAPON->getDamage());
	  if (enemy->getHP() <= 0)
	    delete enemy;
	}
    }
}
