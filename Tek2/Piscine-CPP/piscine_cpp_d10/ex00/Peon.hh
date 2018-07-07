//
// Peon.hh for Peon in /home/pereni_j/Rendu/piscine_cpp_d10/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Fri Jan 15 10:11:23 2016 pereniguez joseph
// Last update Fri Jan 15 22:56:21 2016 pereniguez joseph
//

#ifndef __PEON_HH__
#define __PEON_HH__

#include <string>
#include <iostream>

#include "Victim.hh"

class				Peon : public Victim
{
private:
  
public:
  Peon(std::string);
  virtual ~Peon();
  virtual void			getPolymorphed() const;
};

#endif /* __PEON_HH__ */
