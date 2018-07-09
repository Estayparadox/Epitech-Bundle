//
// main.cpp for  in /home/rosset_p/C++/plazza/work
// 
// Made by Paul Rosset
// Login   <rosset_p@epitech.net>
// 
// Started on  Fri Apr 22 17:50:39 2016 Paul Rosset
// Last update Sun Apr 24 14:58:16 2016 vatinelle maxime
//

#include "Thread.hpp"
#include "Process.hpp"
#include "Namedpipe.hpp"

int main(int argc, char **argv)
{
  Process	polo1;
  Namedpipe	pipe;
  int		i;

  if (argc < 2)
    {
      std::cout << "Usage: ./plazza [nb Threads]" << std::endl;
      return (0);
    }
  IThread *polo[atoi(argv[1])];
  for (i=0; i < atoi(argv[1]); ++i)
    {
      polo[i] = new Thread;
      polo[i]->start();
      polo[i]->join();
      delete polo[i];
    }
}
