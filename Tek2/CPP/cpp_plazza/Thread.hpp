//
// Thread.hpp for  in /home/rosset_p/C++/plazza/bootstrap/Exercice4
// 
// Made by Paul Rosset
// Login   <rosset_p@epitech.net>
// 
// Started on  Fri Apr 15 12:51:13 2016 Paul Rosset
// Last update Sun Apr 24 22:14:54 2016 Paul Rosset
//

#ifndef THREAD_HPP
#define THREAD_HPP

#include "IThread.hpp"
#include <pthread.h>
#include <iostream>
#include "Mutex.hpp"
#include "Parser.hpp"

class Thread : public IThread
{
public:
  Thread();
  virtual ~Thread();
  static void	*func1(void *arg);
  virtual void	join();
  virtual void start();
protected:
  pthread_t *_thread;
  bool _dead;
  bool _running;
  bool _notStarted;
  void	*_arg;
  
  int		_nbthread;  
};

#endif // THREAD_HPP
