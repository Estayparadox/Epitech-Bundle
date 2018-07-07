//
// MachineName.cpp for  in /home/vatine_m/piscineTek2/cpp_gkrellm
// 
// Made by vatinelle maxime
// Login   <vatine_m@epitech.net>
// 
// Started on  Sun Jan 24 05:34:26 2016 vatinelle maxime
// Last update Sun Jan 24 05:36:10 2016 vatinelle maxime
//

#include "MachineName.hpp"

MachineName::MachineName()
{
  attron(COLOR_PAIR(1));
  mvprintw(6, 8, _user.c_str());
  mvprintw(7, 8, _vecHost[0].c_str());
  attroff(COLOR_PAIR(1));
}

MachineName::~MachineName()
{

}
