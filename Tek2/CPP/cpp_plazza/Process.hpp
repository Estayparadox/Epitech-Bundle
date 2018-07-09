
//
// process.hpp for  in /home/rosset_p/C++/plazza/work
// 
// Made by Paul Rosset
// Login   <rosset_p@epitech.net>
// 
// Started on  Mon Apr 11 08:49:03 2016 Paul Rosset
// Last update Thu Apr 21 12:57:58 2016 Paul Rosset
//

#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

class Process//CLASSE MERE
{
public:
  Process();
  virtual ~Process(); //virtual destructor pour attraper le real type et non le Process class
  
  //virtual void		create_process(); //pareil ici
  
protected:
  pid_t pid;
};

#endif // PROCESS_HPP
