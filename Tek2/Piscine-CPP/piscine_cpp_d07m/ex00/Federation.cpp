//
// Federation.cpp for Federation in /home/pereni_j/Rendu/piscine_cpp_d07m/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Tue Jan 12 09:12:21 2016 pereniguez joseph
// Last update Tue Jan 12 23:27:06 2016 pereniguez joseph
//

#include "Federation.hh"
#include "Warpsystem.hh"

void	Federation::Starfleet::Ship::setupCore(WarpSystem::Core *_core)
{
  this->Core = _core;
  std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void    Federation::Ship::setupCore(WarpSystem::Core *_core)
{
  this->Core = _core;
  std::cout << this->_name << ": The core is set." << std::endl;
}

void	Federation::Starfleet::Ship::checkCore()
{
  if (this->Core && this->Core->checkReactor()->isStable() == true)
    std::cout << "USS " << _name << ": The core is stable at the time." << std::endl;
  else
    std::cout << "USS " << _name << ": The core is unstable at the time." << std::endl;
}

void    Federation::Ship::checkCore()
{
  if (this->Core && this->Core->checkReactor()->isStable() == true)
    std::cout << _name << ": The core is stable at the time." << std::endl;
  else
    std::cout << _name << ": The core is unstable at the time." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = 1;
  std::cout << "The independant ship " << _name << " just finished its construction. It is " << _length << " m in length and " << _width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;
  std::cout << "The ship USS " << _name << " has been finished. It is " << _length << " m in length and " << _width << " m in width." << std::endl;
  std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}
