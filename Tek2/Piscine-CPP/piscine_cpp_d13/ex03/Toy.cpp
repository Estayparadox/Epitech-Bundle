//
// Toy.cpp for Toy in /home/pereni_j/Rendu/piscine_cpp_d13/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Mon Jan 18 11:16:37 2016 pereniguez joseph
// Last update Mon Jan 18 20:39:43 2016 pereniguez joseph
//

#include "Toy.h"

Toy::Toy() : _type(BASIC_TOY), _name("toy"), _picture()
{
}

Toy::Toy(ToyType type, std::string const & name, std::string const & picture) : _type(type), _name(name), _picture(picture)
{
}

Toy::Toy(Toy const & toy)
{
  _type = toy._type;
  _name = toy._name;
  _picture = toy._picture;
}

Toy			&Toy::operator=(Toy const & toy)
{
  _type= toy._type;
  _name= toy._name;
  _picture = toy._picture;
  return *this;
}

void			Toy::speak(std::string const & statement)
{
  std::cout << this->_name << " \"" << statement << "\"" << std::endl;
}

Toy::ToyType		Toy::getType() const
{
  return _type;
}

std::string const	&Toy::getName() const
{
  return _name;
}

void			Toy::setName(std::string const & name)
{
  _name = name;
}

bool			Toy::setAscii(const std::string & file)
{
  if (!_picture.getPictureFromFile(file))
    return false;
  return true;
}

std::string const	&Toy::getAscii() const
{
  return _picture.data;
}
