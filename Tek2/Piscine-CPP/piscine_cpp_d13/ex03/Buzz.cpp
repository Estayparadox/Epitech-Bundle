//
// Buzz.cpp for Buzz in /home/pereni_j/Rendu/piscine_cpp_d13/ex02
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Mon Jan 18 16:37:59 2016 pereniguez joseph
// Last update Mon Jan 18 20:40:35 2016 pereniguez joseph
//

#include "Buzz.h"
#include "Toy.h"

Buzz::Buzz(std::string const & name, std::string const & picture) : Toy(BUZZ, name, picture)
{
}

void		Buzz::speak(std::string const & statement)
{
  std::cout << "BUZZ: " << _name << "\"" << statement << "\"" << std::endl;
}
