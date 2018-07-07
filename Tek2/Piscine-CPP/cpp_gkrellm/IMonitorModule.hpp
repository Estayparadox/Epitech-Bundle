//
// IMonitorModule.hpp for  in /home/vatine_m/piscineTek2/cpp_gkrellm
// 
// Made by vatinelle maxime
// Login   <vatine_m@epitech.net>
// 
// Started on  Sun Jan 24 05:53:46 2016 vatinelle maxime
// Last update Sun Jan 24 05:54:32 2016 vatinelle maxime
//

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

class IMonitorModule
{
protected:
  std::string _user;
  std::string _time;
  std::vector<std::string> _vec;
  std::vector<std::string> _vecCpu;
  std::vector<std::string> _vecHost;
  std::vector<std::string> _vecVersion;
  std::vector<std::string> _vecSwap;
public:
  IMonitorModule();
  virtual ~IMonitorModule();
  std::vector<std::string> fileToVector(std::string);
  std::vector<std::string> parseVersion(std::string);
  std::string getTime() const;
};

#endif
