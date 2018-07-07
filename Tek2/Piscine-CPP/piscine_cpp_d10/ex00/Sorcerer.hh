//
// Sorcerer.hh for Sorcerer in /home/pereni_j/Rendu/piscine_cpp_d10/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Fri Jan 15 09:31:16 2016 pereniguez joseph
// Last update Fri Jan 15 22:23:27 2016 pereniguez joseph
//

#ifndef __SORCERER_HH__
#define __SORCERER_HH__

#include <string>
#include <iostream>

#include "Victim.hh"

class			Sorcerer
{
private:
  std::string		TITLE;
  std::string		NAME;
public:
  Sorcerer(std::string, std::string);
  ~Sorcerer();
  std::string		getNAME();
  std::string		getTITLE();
  void			polymorph(Victim const &) const;
};

std::ostream&		operator<<(std::ostream&, Sorcerer &);

#endif /* __SORCERER_HH__ */
