//
// Character.cpp for Character in /home/pereni_j/Rendu/piscine_cpp_d09/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Thu Jan 14 12:48:54 2016 pereniguez joseph
// Last update Fri Jan 15 07:53:57 2016 pereniguez joseph
//

#include "Character.hh"

Character::Character(const std::string &addname, int addlvl)
{
  this->Hp = 100;
  this->Energy = 100;
  this->Strenght = 5;
  this->Intelligence = 5;
  this->Spirit = 5;
  this->Stamina = 5;
  this->Agility = 5;
  this->name = new std::string (addname);
  this->lvl = addlvl;
  this->Race = "koala";
  this->Range = Character::CLOSE;
  std::cout << *this->name << " Created" << std::endl;
}

Character::~Character()
{
}

int			Character::getStrenght()
{
  return this->Strenght;
}

int			Character::getStamina()
{
  return this->Stamina;
}

int			Character::getIntelligence()
{
  return this->Intelligence;
}

int			Character::getSpirit()
{
  return this->Spirit;
}

int			Character::getAgility()
{
  return this->Agility;
}

const std::string&	Character::getName() const
{
  return *this->name;
}

int			Character::getLvl() const
{
  return this->lvl;
}

int			Character::getPv() const
{
  return this->Hp;
}

int			Character::getPower() const
{
  return this->Energy;
}

int			Character::CloseAttack()
{
  int			Damage = 0;

  if (this->Energy >= 10)
    {
      this->Energy -= 10;
      Damage = (10 + this->Strenght);
      std::cout << *this->name << " strikes with a wood stick" << std::endl;
    }
  else
    std::cout << *this->name << " out of power" << std::endl;
  return Damage;
}

int			Character::RangeAttack()
{
  int			Damage = 0;

  if (this->Energy >= 10)
    {
      this->Energy -= 10;
      Damage = (5 + this->Strenght);
      std::cout << *this->name << " launches a stone" << std::endl;
    }
  else
    std::cout << *this->name << " out of power" << std::endl;
  return Damage;
}

void			Character::Heal()
{
  if (this->Hp <= 100)
    {
      this->Hp += 50;
      std::cout << *this->name << " takes a potion" << std::endl;
      if (this->Hp >= 100)
	this->Hp = 100;
    }
}

void			Character::RestorePower()
{
  if (this->Energy <= 100)
    {
      this->Energy += 100;
      std::cout << *this->name << " eats" << std::endl;
      if (this->Energy >= 100)
	this->Energy = 100;
    }
}

void			Character::TakeDamage(int _damage)
{
  if ((this->Hp - _damage) > 0)
    {
      this->Hp -= _damage;
      std::cout << *this->name << " takes " << _damage << " damage" << std::endl;
    }
  else
    {
      this->Hp = 0;
      std::cout << *this->name << " out of combat" << std::endl;
    }
}
