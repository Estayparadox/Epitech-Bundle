//
// Woody.cpp for Woody in /home/pereni_j/Rendu/piscine_cpp_d13/ex02
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Mon Jan 18 17:00:08 2016 pereniguez joseph
// Last update Mon Jan 18 20:31:48 2016 pereniguez joseph
//

#include "Woody.h"
#include "Toy.h"

Woody::Woody(std::string const & name, std::string const & picture) : Toy(WOODY, name, picture)
{
}

void		Woody::speak(std::string const & statement)
{
  std::cout << "WOODY: "<< _name << " \"" << statement << "\"" << std::endl;
}
