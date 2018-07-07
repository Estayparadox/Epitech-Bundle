//
// Warrior.hh for Warrior in /home/pereni_j/Rendu/piscine_cpp_d09/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Thu Jan 14 16:22:02 2016 pereniguez joseph
// Last update Thu Jan 14 17:08:10 2016 pereniguez joseph
//

#ifndef __WARRIOR_HH__
#define __WARRIOR_HH__

#include <iostream>
#include <string>

class			Warrior
{
private:
  std::string		weaponName;
public:
  Warrior();
  ~Warrior();
  int			CloseAttack();
  int			RangeAttack();
  void			Heal();
  void			RestorePower();
};

#endif
