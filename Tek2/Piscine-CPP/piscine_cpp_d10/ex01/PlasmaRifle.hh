//
// PlasmaRifle.hh for PlasmaRifle in /home/pereni_j/Rendu/piscine_cpp_d10/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Sat Jan 16 00:12:08 2016 pereniguez joseph
// Last update Sat Jan 16 00:14:15 2016 pereniguez joseph
//

#ifndef __PLASMARIFLE_HH__
#define __PLASMARIFLE_HH__

#include <string>
#include <iostream>
#include "AWeapon.hh"

class		PlasmaRifle : public AWeapon
{
public:
  PlasmaRifle();
  ~PlasmaRifle();
  virtual void	attack() const;
};

#endif /* __PLASMARIFLE_HH__ */
