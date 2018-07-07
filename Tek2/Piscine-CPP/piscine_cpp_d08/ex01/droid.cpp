//
// droid.cpp for droid in /home/pereni_j/Rendu/piscine_cpp_d08/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Wed Jan 13 08:58:42 2016 pereniguez joseph
// Last update Thu Jan 14 08:39:22 2016 pereniguez joseph
//

#include <iostream>
#include <string>

#include "droid.hh"

Droid::Droid(std::string serial) : Id(serial), Energy(50), Attack(25), Toughness(15)
{
  this->Status = new std::string("Standing by");
  battleData = new DroidMemory();
  Id = serial;
  std::cout << "Droid '" << this->Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &adresse) : Id(adresse.Id), Energy(adresse.Energy), Attack(adresse.Attack), Toughness(adresse.Toughness)
{
  if (adresse.Status)
    this->Status = new std::string (*(adresse.Status));
  else
    this->Status = new std::string("Standing by");
  std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
  std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
}

DroidMemory*	Droid::getBattleData() const
{
  return battleData;
}

void		Droid::setBattleData(DroidMemory* mem)
{
  delete battleData;
  battleData = mem;
}

Droid&		Droid::operator<<(size_t &reloader)
{
  if (Energy + reloader >= 100)
    {
      reloader = reloader - (100 - Energy);
      Energy = 100;
    }
  else
    {
      Energy = Energy + reloader;
      reloader = 0;
    }
  return *this;
}

bool		Droid::operator!=(Droid const &d2) const
{
  return !(*this == d2);
}

bool            Droid::operator==(Droid const &d2) const
{
  if ((this->Id.compare(d2.Id) == 0) && this->Energy == d2.Energy && this->Attack == d2.Attack &&
      this->Toughness == d2.Toughness && (this->Status->compare(*(d2.Status)) == 0))
    return true;
  return false;
}

std::ostream&	operator<<(std::ostream& os, Droid const & k)
{
  os << "Droid '" << k.getId() << "', " << *k.getStatus() << ", " << k.getEnergy();
  return (os);
}

Droid&		Droid::operator=(Droid const & other)
{
  this->Id = other.Id;
  this->Energy = other.Energy;
  Status = new std::string(*(other.Status));
  return *this;
}

void		Droid::setId(std::string id)
{
  this->Id = id;
}

void		Droid::setEnergy(size_t energy)
{
  this->Energy = energy;
}

void            Droid::setStatus(std::string *status)
{
  this->Status = status;
}

std::string	Droid::getId() const
{
  return this->Id;
}

size_t		Droid::getEnergy() const
{
  return this->Energy;
}

size_t		Droid::getAttack() const
{
  return this->Attack;
}

size_t		Droid::getToughness() const
{
  return this->Toughness;
}

std::string	*Droid::getStatus() const
{
  return this->Status;
}
