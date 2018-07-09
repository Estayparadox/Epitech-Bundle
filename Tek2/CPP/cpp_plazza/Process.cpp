//
// process.cpp for  in /home/rosset_p/C++/plazza/work
// 
// Made by Paul Rosset
// Login   <rosset_p@epitech.net>
// 
// Started on  Mon Apr 11 08:48:56 2016 Paul Rosset
// Last update Sun Apr 24 22:14:23 2016 Paul Rosset
//

#include "Process.hpp"

Process::Process()
{
  this->pid = fork();
}

Process::~Process()
{
  if (this->pid > 0)
    {
      kill(this->pid, SIGKILL);
    }
}
