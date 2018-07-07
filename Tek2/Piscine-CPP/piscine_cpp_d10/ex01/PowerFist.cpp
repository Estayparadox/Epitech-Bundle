//
// PowerFist.cpp for PowerFist in /home/pereni_j/Rendu/piscine_cpp_d10/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Sat Jan 16 00:16:30 2016 pereniguez joseph
// Last update Sat Jan 16 00:18:42 2016 pereniguez joseph
//

#include "PowerFist.hh"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist()
{
}

void		PowerFist::attack() const
{
  std::cout << "* pschhh... SBAM! *" << std::endl;
}
