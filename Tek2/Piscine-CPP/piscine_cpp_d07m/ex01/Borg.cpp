//
// Borg.cpp for Borg in /home/pereni_j/Rendu/piscine_cpp_d07m/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Tue Jan 12 22:59:01 2016 pereniguez joseph
// Last update Wed Jan 13 08:23:43 2016 pereniguez joseph
//

#include "Borg.hh"
#include "Federation.hh"
#include "Warpsystem.hh"

#include <string>
#include <iostream>

Borg::Ship::Ship()
{
  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
  std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
  std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

Federation::Starfleet::Captain::Captain(std::string name)
{
  this->_name = name;
}

Federation::Starfleet::Captain::~Captain()
{
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
  this->name = name;
  std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

void	Borg::Ship::setupCore(WarpSystem::Core *core)
{
  this->core = core;
}

void	Borg::Ship::checkCore()
{
  if (this->core && this->core->checkReactor()->isStable() == true)
    std::cout << "Everything is in order." << std::endl;
  else
    std::cout << "Critical failure imminent." << std::endl;
}

std::string Federation::Starfleet::Captain::getName()
{
  return this->_name;
}

int Federation::Starfleet::Captain::getAge()
{
  return this->_age;
}

void	Federation::Starfleet::Captain::setAge(int nb)
{
  this->_age = nb;
}

void	Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *capt)
{
  this->capt = capt;
  std::cout << capt->getName() << ": I'm glad to be the captain of the USS " << 
    this->_name << "." << std::endl;
}
