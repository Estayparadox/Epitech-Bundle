//
// sickkoala.cpp for sickkoala in /home/pereni_j/Rendu/piscine_cpp_d06/ex02
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Mon Jan 11 15:48:20 2016 pereniguez joseph
// Last update Mon Jan 11 22:24:34 2016 pereniguez joseph
//

#include <iostream>
#include <cstring>
#include "sickkoala.h"

SickKoala::SickKoala(std::string name)
{
  this->name = name;
}

SickKoala::~SickKoala()
{
  std::cout << "Mr." << this->name << ": Kreooogg !! Je suis gueriiii !" << std::endl;
}

void		SickKoala::poke()
{
  std::cout << "Mr." << this->name << ": Gooeeeeerrk !! :’(" << std::endl;
}

bool		SickKoala::takeDrug(std::string data)
{
  if (strcasecmp(data.c_str(), "mars") == 0)
    {
      std::cout << "Mr." << this->name << ": Mars, et ca kreog !" << std::endl;
      return true;
    }
  else if (data == "Buronzand")
    {
      std::cout<< "Mr." << this->name << ": Et la fatigue a fait son temps !" << std::endl;
      return true;
    }
  else
    {
      std::cout << "Mr." << this->name << ": Goerkreog !" << std::endl;
      return false;
    }
}

void		SickKoala::overDrive(std::string data)
{
  while (data.find("Kreog !") != std::string::npos)
    data.replace(data.find("Kreog !"), 7, "1337 !");
  std::cout << "Mr." << this->name << ": " << data << std::endl;
}
