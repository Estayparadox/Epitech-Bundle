//
// Victim.cpp for Victim in /home/pereni_j/Rendu/piscine_cpp_d10/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Fri Jan 15 09:52:54 2016 pereniguez joseph
// Last update Fri Jan 15 23:15:34 2016 pereniguez joseph
//

#include "Victim.hh"

Victim::Victim(std::string name) : NAME(name)
{
  std::cout << "Some random victim called " << this->NAME << " just popped !" << std::endl;
}

Victim::~Victim()
{
  std::cout << "Victim " << this->NAME << " just died for no apparent reason !" << std::endl;
}

std::string		Victim::getNAME()
{
  return this->NAME;
}

std::ostream&		operator<<(std::ostream & os, Victim & k)
{
  os << "I'm " << k.getNAME() << " and i like otters !" << std::endl;
  return os;
}

void			Victim::getPolymorphed() const
{
  std::cout << this->NAME << " has been turned into a cute little sheep !" << std::endl;
}
