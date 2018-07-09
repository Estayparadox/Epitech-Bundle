//
// Namedpipe.hpp for  in /home/rosset_p/C++/plazza/bootstrap/Exercice4
// 
// Made by Paul Rosset
// Login   <rosset_p@epitech.net>
// 
// Started on  Fri Apr 15 12:51:13 2016 Paul Rosset
// Last update Sun Apr 24 14:55:49 2016 vatinelle maxime
//

#ifndef NAMEDPIPE_HPP
#define NAMEDPIPE_HPP

#include "Process.hpp"
#include <pthread.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class Namedpipe
{
public:
  Namedpipe();
  ~Namedpipe();
  void	createNamedPipe();
protected:
  std::string	name;
};

#endif // NAMEDPIPE_HPP
