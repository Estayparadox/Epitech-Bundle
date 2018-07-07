//
// Teddy.cpp for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 12:40:16 2016 Luca GUARNIERI
// Last update Sun Jan 17 07:19:05 2016 Luca GUARNIERI
//

#include "Teddy.hh"

Teddy::Teddy(std::string const &title, std::string const &type) : Toy(title, type)
{

}

Teddy::~Teddy()
{

}

void		Teddy::isTaken() const
{
  std::cout << "gra hu" << std::endl;
}
