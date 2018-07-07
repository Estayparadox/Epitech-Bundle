//
// SuperMutant.hh for SuperMutant in /home/pereni_j/Rendu/piscine_cpp_d10/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Sat Jan 16 00:25:42 2016 pereniguez joseph
// Last update Sat Jan 16 00:27:30 2016 pereniguez joseph
//

#ifndef __SUPERMUTANT_HH__
#define __SUPERMUTANT_HH__

#include <string>
#include <iostream>
#include "AEnemy.hh"

class		SuperMutant : public AEnemy
{
  SuperMutant();
  ~SuperMutant();
  virtual void	takeDamage(int);
};

#endif /* __SUPERMUTANT_HH__ */
