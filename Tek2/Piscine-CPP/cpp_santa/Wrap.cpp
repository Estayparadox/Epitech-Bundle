//
// Wrap.cpp for  in /home/guarni_l/cpp_santa
// 
// Made by Luca GUARNIERI
// Login   <guarni_l@epitech.net>
// 
// Started on  Sat Jan 16 14:36:20 2016 Luca GUARNIERI
// Last update Sun Jan 17 07:18:17 2016 Luca GUARNIERI
//

#include "Wrap.hh"

Wrap::Wrap(std::string const &title, std::string const &type) : Object(title, type)
{
  _open = false;
  _gift = NULL;
}

Wrap::~Wrap()
{

}

Wrap	&Wrap::operator=(Wrap const &New)
{
  *this = New;
  _open = New._open;
  _gift = New._gift;
  return *this;
}

void    Wrap::closeMe()
{
  _open = false;
}

void    Wrap::openMe()
{
  _open = true;
}

bool    Wrap::isOpen()
{
  return _open;
}

bool	Wrap::isWrapped()
{
  if (_gift == NULL)
    return false;
  return true;
}
