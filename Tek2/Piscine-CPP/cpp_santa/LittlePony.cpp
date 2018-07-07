//
// LittlePony.cpp for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 12:45:09 2016 Luca GUARNIERI
// Last update Sun Jan 17 07:38:27 2016 Luca GUARNIERI
//

#include "LittlePony.hh"

LittlePony::LittlePony(std::string const &title, std::string const &type) : Toy(title, type)
{

}

LittlePony::~LittlePony()
{

}

void		LittlePony::isTaken() const
{
  std::cout << "yo man" << std::endl;
}
