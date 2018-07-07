//
// droidmemory.hh for droidmemory in /home/pereni_j/Rendu/piscine_cpp_d08/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Wed Jan 13 18:27:35 2016 pereniguez joseph
// Last update Wed Jan 13 21:25:34 2016 pereniguez joseph
//

#ifndef __DROIDMEMORY_HH__
#define __DROIDMEMORY_HH__

#include <string>
#include <cstdlib>
#include <iostream>

class			DroidMemory
{
private:
  size_t		FingerPrint;
  size_t		Exp;
  static void		fusion(DroidMemory &, DroidMemory const &, DroidMemory const &);
public:
  DroidMemory();
  ~DroidMemory();
  size_t		getFingerPrint() const;
  void			setFingerPrint(size_t);
  size_t		getExp() const;
  void			setExp(size_t);
  DroidMemory&		operator<<(DroidMemory const &);
  DroidMemory const &	operator>>(DroidMemory&) const;
  DroidMemory&		operator+=(DroidMemory const &);
  DroidMemory&		operator+=(size_t);
  DroidMemory&		operator+(DroidMemory const &) const;
  DroidMemory&		operator+(size_t) const;
};

  std::ostream&		operator<<(std::ostream&, DroidMemory const &);

#endif /* __DROIDMEMORY_HH__ */
