//
// Victim.hh for Victim in /home/pereni_j/Rendu/piscine_cpp_d10/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Fri Jan 15 09:49:53 2016 pereniguez joseph
// Last update Fri Jan 15 22:46:42 2016 pereniguez joseph
//

#ifndef __VICTIM_HH__
#define __VICTIM_HH__

#include <string>
#include <iostream>

class				Victim
{
protected:
  std::string			NAME;
public:
  Victim(std::string);
  virtual ~Victim();
  virtual void			getPolymorphed() const;
    std::string			getNAME();
};
  
std::ostream&			operator<<(std::ostream &, Victim &);

#endif /* __VICTIM_HH__ */
