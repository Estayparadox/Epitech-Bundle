//
// Thread.cpp for  in /home/rosset_p/C++/plazza/bootstrap/Exercice4
// 
// Made by Paul Rosset
// Login   <rosset_p@epitech.net>
// 
// Started on  Fri Apr 15 12:53:19 2016 Paul Rosset
// Last update Sun Apr 24 15:03:53 2016 vatinelle maxime
//

#include "Namedpipe.hpp"
#include <stdio.h>
#include <iostream>

Namedpipe::Namedpipe()
{
  this->name = "namedPipe";
  createNamedPipe();
}

Namedpipe::~Namedpipe()
{
}

void	Namedpipe::createNamedPipe()
{
  mkfifo("nPipe", 0777);
}
