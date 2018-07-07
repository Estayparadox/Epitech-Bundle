//
// Sorcerer.cpp for Sorcerer in /home/pereni_j/Rendu/piscine_cpp_d10/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Fri Jan 15 09:42:36 2016 pereniguez joseph
// Last update Fri Jan 15 23:15:11 2016 pereniguez joseph
//

#include "Sorcerer.hh"
#include "Victim.hh"
#include "Peon.hh"

Sorcerer::Sorcerer(std::string name, std::string title)
{
  this->NAME = name;
  this->TITLE = title;
  std::cout << this->NAME << ", " << this->TITLE << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer()
{
  std::cout << this->NAME << ", " << this->TITLE << ", is dead. Consequences will never be the same !" << std::endl;
}

void			Sorcerer::polymorph(Victim const & k) const
{
  k.getPolymorphed();
}

std::string             Sorcerer::getNAME()
{
  return this->NAME;
}

std::string		Sorcerer::getTITLE()
{
  return this->TITLE;
}

std::ostream&		operator<<(std::ostream & os, Sorcerer & k)
{
  os << "I am " << k.getNAME() << ", " << k.getTITLE() << ", and I like ponies !" << std::endl;
  return os;
}
