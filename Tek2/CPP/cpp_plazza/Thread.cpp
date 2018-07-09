//
// Thread.cpp for  in /home/rosset_p/C++/plazza/bootstrap/Exercice4
// 
// Made by Paul Rosset
// Login   <rosset_p@epitech.net>
// 
// Started on  Fri Apr 15 12:53:19 2016 Paul Rosset
// Last update Sun Apr 24 22:14:41 2016 Paul Rosset
//

#include "Thread.hpp"

Thread::Thread()
{
  this->_dead = false;
  this->_running = false;
  this->_notStarted = true;
  this->_thread = new pthread_t;
}

Thread::~Thread()
{
  this->_dead = true;
  this->_running = false;
  this->_notStarted = false;
  delete this->_thread;
}

void	*Thread::func1(void *arg)
{
  IMutex *polo;
  IParser *email;
  std::string command1;
  std::string command2;
  std::getline(std::cin, command1, ' ');
  std::getline(std::cin, command2, '\n');

  email = new Parser;
  polo = new Mutex;
  polo->trylock();
  email->find_Enum(command1, command2);
  polo->unlock();
}

void	Thread::start()
{
  pthread_create(this->_thread, NULL, Thread::func1, this->_arg);
}

void	Thread::join()
{
  this->_running = true;
  pthread_join(*this->_thread, NULL);
  this->_running = false;
}
