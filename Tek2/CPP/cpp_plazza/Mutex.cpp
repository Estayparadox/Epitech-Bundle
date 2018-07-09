//
// Mutex.cpp for  in /home/rosset_p/C++/plazza/bootstrap/Exercice2
// 
// Made by Paul Rosset
// Login   <rosset_p@epitech.net>
// 
// Started on  Thu Apr 14 16:56:15 2016 Paul Rosset
// Last update Thu Apr 21 16:16:18 2016 Paul Rosset
//

#include "Mutex.hpp"

Mutex::Mutex() 
{
  pthread_mutex_init(&this->_mutex, NULL);
  //  std::cout << "Creation du Mutex" << std::endl;
}

Mutex::~Mutex() 
{
  pthread_mutex_destroy(&this->_mutex);
  //std::cout << "Destruction du Mutex" << std::endl;
}

void	Mutex::lock()
{
  pthread_mutex_lock(&this->_mutex);
  //std::cout << "Lock du mutex" << std::endl;
}

void	Mutex::unlock()
{
  pthread_mutex_unlock(&this->_mutex);
  //std::cout << "Unlock du mutex" << std::endl;
}

bool	Mutex::trylock()
{
  if (!(pthread_mutex_trylock(&this->_mutex) == 0))
    exit (-1);
  //std::cout << "Trylock du mutex" << std::endl;
}
