//
// Peon.cpp for Peon in /home/pereni_j/Rendu/piscine_cpp_d10/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Fri Jan 15 10:13:27 2016 pereniguez joseph
// Last update Fri Jan 15 22:54:52 2016 pereniguez joseph
//

#include "Peon.hh"

Peon::Peon(std::string name) : Victim(name)
{
  std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
  std::cout << "Bleuark..." << std::endl;
}

void			Peon::getPolymorphed() const
{
  std::cout << this->NAME << " has been turned into a pink pony !" << std::endl;
}
