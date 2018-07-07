//
// Time.cpp for  in /home/vatine_m/piscineTek2/cpp_gkrellm
// 
// Made by vatinelle maxime
// Login   <vatine_m@epitech.net>
// 
// Started on  Sun Jan 24 05:05:14 2016 vatinelle maxime
// Last update Sun Jan 24 05:22:44 2016 vatinelle maxime
//

#include "Time.hpp"

Time::Time()
{
  _time = getTime();
  attron(A_BOLD);
  mvprintw(2, 8, _time.c_str());
  attroff(A_BOLD);
}

Time::~Time()
{

}
