//
// IThread.hpp for  in /home/rosset_p/C++/plazza/bootstrap/Exercice4
// 
// Made by Paul Rosset
// Login   <rosset_p@epitech.net>
// 
// Started on  Fri Apr 15 12:50:13 2016 Paul Rosset
// Last update Tue Apr 19 16:06:01 2016 Paul Rosset
//

#ifndef ITHREAD_HPP
#define ITHREAD_HPP

class IThread
{
public:
  virtual ~IThread() {}
  virtual void join() = 0;
  virtual void start() = 0;
};

#endif // ITHREAD_HPP
