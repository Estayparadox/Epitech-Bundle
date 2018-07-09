//
// IMutex.hpp for  in /home/rosset_p/C++/plazza/bootstrap/Exercice1
// 
// Made by Paul Rosset
// Login   <rosset_p@epitech.net>
// 
// Started on  Thu Apr 14 16:51:36 2016 Paul Rosset
// Last update Thu Apr 14 17:19:41 2016 Paul Rosset
//

#ifndef IMUTEX_HPP
#define IMUTEX_HPP

class IMutex 
{
public:
  virtual ~IMutex(void) {}
  virtual void lock(void) = 0;
  virtual void unlock(void) = 0;
  virtual bool trylock(void) = 0;
};

#endif // IMUTEX_HPP
