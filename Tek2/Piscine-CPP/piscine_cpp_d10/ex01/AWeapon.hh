//
// AWeapon.hh for AWeapon in /home/pereni_j/Rendu/piscine_cpp_d10/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Fri Jan 15 23:38:05 2016 pereniguez joseph
// Last update Fri Jan 15 23:42:05 2016 pereniguez joseph
//

#ifndef __AWEAPON_HH__
#define __AWEAPON_HH__

#include <string>
#include <iostream>

class			AWeapon
{
private:
  std::string		NAME;
  int			APCOST;
  int			DAMAGE;
public:
  AWeapon(std::string const &, int, int);
  virtual ~AWeapon();
  std::string const	&getName() const;
  int			getAPCost() const;
  int			getDamage() const;
  virtual void		attack() const = 0;
};

#endif /* __AWEAPON_HH__ */
