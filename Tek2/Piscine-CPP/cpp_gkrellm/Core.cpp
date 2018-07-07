//
// Core.cpp for  in /home/vatine_m/piscineTek2/cpp_gkrellm
// 
// Made by vatinelle maxime
// Login   <vatine_m@epitech.net>
// 
// Started on  Sun Jan 24 05:40:21 2016 vatinelle maxime
// Last update Sun Jan 24 05:41:19 2016 vatinelle maxime
//

#include "Core.hpp"

Core::Core()
{
  attron(COLOR_PAIR(2));
  mvprintw(10, 8, _vec[0].c_str());
  mvprintw(11, 8, _vec[1].c_str());
  mvprintw(13, 8, _vecCpu[7].c_str());
  mvprintw(14, 8, _vecCpu[33].c_str());
  mvprintw(15, 8, _vecCpu[59].c_str());
  mvprintw(16, 8, _vecCpu[85].c_str());
  attroff(COLOR_PAIR(2));
}

Core::~Core()
{

}
