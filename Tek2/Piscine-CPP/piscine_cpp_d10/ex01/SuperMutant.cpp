//
// SuperMutant.cpp for SuperMutant in /home/pereni_j/Rendu/piscine_cpp_d10/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Sat Jan 16 00:23:03 2016 pereniguez joseph
// Last update Sat Jan 16 01:04:47 2016 pereniguez joseph
//

#include "SuperMutant.hh"

SuperMutant::SuperMutant() : AEnemy (170, "Super Mutant")
{
  std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
  std::cout << "Aaargh..." << std::endl;
}

void		SuperMutant::takeDamage(int damage)
{
  AEnemy::takeDamage(damage - 3);
}
