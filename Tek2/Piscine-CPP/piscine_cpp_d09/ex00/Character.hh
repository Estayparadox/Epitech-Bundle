//
// Character.hh for Character in /home/pereni_j/Rendu/piscine_cpp_d09/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Thu Jan 14 12:43:44 2016 pereniguez joseph
// Last update Thu Jan 14 16:03:22 2016 pereniguez joseph
//

#ifndef __CHARACTER_HH__
#define __CHARACTER_HH__

#include <iostream>
#include <string>

class			Character
{
public:
  enum			AttackRange
    {
      CLOSE,
      RANGE
    };
private:
  const std::string	*name;
  std::string		Race;
  int			lvl;
  int			Hp;
  int			Energy;
  int			Strenght;
  int			Stamina;
  int			Intelligence;
  int			Spirit;
  int			Agility;
public:
  Character(const std::string&, int);
  ~Character();
  int			Range;
  void                  TakeDamage(int _damage);
  int			getStrenght();
  int			getStamina();
  int			getIntelligence();
  int			getSpirit();
  int			getAgility();
  int			CloseAttack();
  int			RangeAttack();
  void			Heal();
  void			RestorePower();
  const std::string&	getName() const;
  int			getLvl() const;
  int			getPv() const;
  int			getPower() const;
};

#endif
