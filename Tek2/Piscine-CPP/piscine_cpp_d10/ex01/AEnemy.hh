//
// AEnemy.hh for AEnemy in /home/pereni_j/Rendu/piscine_cpp_d10/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Fri Jan 15 23:24:07 2016 pereniguez joseph
// Last update Sat Jan 16 00:45:08 2016 pereniguez joseph
//

#ifndef __AENEMY_HH__
#define __AENEMY_HH__

#include <string>
#include <iostream>

class			AEnemy
{
private:
  int			_HP;
  std::string const	_TYPE;
public:
  AEnemy(int, std::string const &);
  virtual ~AEnemy();
  std::string const	&getType() const;
  int			getHP() const;
  virtual void		takeDamage(int);
};

#endif /* __AENEMY_HH__ */
