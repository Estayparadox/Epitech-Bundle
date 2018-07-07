//
// Fruit.cpp for Fruit in /home/pereni_j/Rendu/piscine_cpp_d14m/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Tue Jan 19 09:15:27 2016 pereniguez joseph
// Last update Tue Jan 19 19:01:56 2016 pereniguez joseph
//

#include "Fruit.h"

Fruit::Fruit() : _name("fruit"), _vitamins(0)
{
}

Fruit::Fruit(std::string const name, int vitamins) : _name(name), _vitamins(vitamins)
{
}

Fruit::~Fruit()
{
}

std::string const	&Fruit::getName() const
{
  return _name;
}

int			Fruit::getVitamins() const
{
  return _vitamins;
}
