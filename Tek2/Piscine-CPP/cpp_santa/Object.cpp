//
// Object.cpp for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 11:09:20 2016 Luca GUARNIERI
// Last update Sun Jan 17 07:30:49 2016 Luca GUARNIERI
//

#include "Object.hh"

Object::Object(std::string const &name, std::string const &type)
{
  _title = new std::string (name);
  _type = new std::string (type);
}

Object::~Object()
{

}

const std::string	&Object::getTitle() const
{
  return *_title;
}

const std::string	&Object::getType() const
{
  return *_type;
}

Object		&Object::operator=(Object const &k)
{
  _title = k._title;
  _type = k._type;
  return *this;
}
