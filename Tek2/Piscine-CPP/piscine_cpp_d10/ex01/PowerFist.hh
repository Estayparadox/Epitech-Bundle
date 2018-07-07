//
// PowerFist.hh for PowerFist in /home/pereni_j/Rendu/piscine_cpp_d10/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Sat Jan 16 00:14:45 2016 pereniguez joseph
// Last update Sat Jan 16 00:59:22 2016 pereniguez joseph
//

#ifndef __POWERFIST_HH__
#define __POWERFIST_HH__

#include <string>
#include <iostream>
#include "AWeapon.hh"

class		PowerFist : public AWeapon
{
public:
  PowerFist();
  ~PowerFist();
  virtual void	attack() const;
};

#endif /* __POWERFIST_HH__ */
