//
// OperatingModule.cpp for  in /home/vatine_m/piscineTek2/cpp_gkrellm
// 
// Made by vatinelle maxime
// Login   <vatine_m@epitech.net>
// 
// Started on  Sun Jan 24 05:25:27 2016 vatinelle maxime
// Last update Sun Jan 24 05:28:01 2016 vatinelle maxime
//

#include "OperatingModule.hpp"

OperatingModule::OperatingModule()
{
  attron(COLOR_PAIR(1));
  mvprintw(4, 8, _vecCpu[4].c_str());
  mvprintw(5, 8, _vecVersion[0].c_str());
  mvprintw(5, 14, _vecVersion[1].c_str());
  mvprintw(5, 22, _vecVersion[2].c_str());
  attroff(COLOR_PAIR(1));
}

OperatingModule::~OperatingModule()
{

}
