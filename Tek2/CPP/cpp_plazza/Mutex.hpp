//
// IMutex.hpp for  in /home/rosset_p/C++/plazza/bootstrap/Exercice1
// 
// Made by Paul Rosset
// Login   <rosset_p@epitech.net>
// 
// Started on  Thu Apr 14 16:51:36 2016 Paul Rosset
// Last update Fri Apr 15 11:15:45 2016 Paul Rosset
//

#ifndef MUTEX_HPP
#define MUTEX_HPP

#include <iostream>
#include "IMutex.hpp"
#include <pthread.h>

class Mutex : public IMutex
{
public:
  Mutex();
  virtual ~Mutex(void);
  virtual void lock(void);
  virtual void unlock(void);
  virtual bool trylock(void);

protected:
  pthread_mutex_t	_mutex;
};

#endif // MUTEX_HPP
