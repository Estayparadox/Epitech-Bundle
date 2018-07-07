//
// Skat.cpp for Skat in /home/pereni_j/Downloads
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Wed Jan 13 23:36:24 2016 pereniguez joseph
// Last update Wed Jan 13 08:43:08 2016 pereniguez joseph
//

#include "Skat.h"

#include <fstream>

std::string const	&Skat::name()
{
  return (this->_name);
}

Skat::Skat()
{
  this->_name = "bob";
  this->_stimPaks = 15;
}

Skat::~Skat()
{
}

Skat::Skat(int stimPaks)
{
  this->_name = "bob";
  this->_stimPaks = stimPaks;
}

Skat::Skat(std::string const& name)
{
  this->_name = name;
  this->_stimPaks = 15;
}

Skat::Skat(std::string const& name, int stimPaks)
{
  this->_name = name;
  this->_stimPaks = stimPaks;
}

unsigned int		Skat::stimPaks()
{
  return (this->_stimPaks);
}

void			Skat::status()
{
  std::cout << "Soldier " << this->_name << " reporting "
	    << this->_stimPaks << " stimpks remaining sir !" << std::endl;
}

void			Skat::addStimPaks(unsigned int number)
{
  if (number == 0)
    std::cout << "Hey boya, did you forget something ?" << std::endl;
  else
    this->_stimPaks = this->_stimPaks + number;
}

void			Skat::useStimPaks()
{
  if (this->_stimPaks == 0)
    std::cout << "Mediiiiiic" << std::endl;
  else 
    {
      std::cout << "Time to kick some ass and chew bubble gum."
		<< std::endl;
      this->_stimPaks = this->_stimPaks - 1;
    }
}

void			Skat::shareStimPaks(unsigned int number, unsigned int stock)
{
  if (number > stock)
    std::cout << "Don't be greedy" << std::endl;
  else
    {
      std::cout << "Keep the change." << std::endl;
      stock = stock - number;
      this->_stimPaks = this->_stimPaks - number;
    }
}
