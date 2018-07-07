//
// Character.hh for Character in /home/pereni_j/Rendu/piscine_cpp_d10/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Fri Jan 15 23:43:00 2016 pereniguez joseph
// Last update Sat Jan 16 00:49:40 2016 pereniguez joseph
//

#ifndef __CHARACTER_HH__
#define __CHARACTER_HH__

#include <string>
#include <iostream>
#include "AWeapon.hh"
#include "AEnemy.hh"

class			Character
{
private:
  std::string		_NAME;
  int			_AP;
  AWeapon		*_CWEAPON;
public:
  Character(std::string const &);
  ~Character();
  bool			checkif(int);
  int			getAP() const;
  AWeapon		*getWeapon() const;
  void			recoverAP();
  void			equip(AWeapon*);
  void			attack(AEnemy*);
  std::string const	&getName() const;
};

std::ostream&		operator<<(std::ostream &, Character const &);

#endif /* __CHARACTER_HH__ */
