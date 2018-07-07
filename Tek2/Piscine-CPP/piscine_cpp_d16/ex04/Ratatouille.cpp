//
// Ratatouille.cpp for Ratatouille in /home/pereni_j/Rendu/piscine_cpp_d16/ex04
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Thu Jan 21 20:04:11 2016 pereniguez joseph
// Last update Thu Jan 21 20:17:23 2016 pereniguez joseph
//

#include "Ratatouille.h"

Ratatouille::Ratatouille()
{
}

Ratatouille::Ratatouille(const Ratatouille &name)
{
  pot.str("");
  pot << name.pot.rdbuf();
}

Ratatouille::~Ratatouille()
{
}

std::string		Ratatouille::kooc()
{
  return pot.str();
}

Ratatouille		&Ratatouille::addVegetable(unsigned char vegetable)
{
  pot << vegetable;
  return *this;
}

Ratatouille		&Ratatouille::addCondiment(unsigned int condiment)
{
  pot << condiment;
  return *this;
}

Ratatouille		&Ratatouille::addSpice(double spice)
{
  pot << spice;
  return *this;
}

Ratatouille		&Ratatouille::addSauce(std::string sauce)
{
  pot << sauce;
  return *this;
}

Ratatouille		&Ratatouille::operator=(const Ratatouille &name)
{
  pot.str("");
  pot << name.pot.rdbuf();
  return *this;
}
