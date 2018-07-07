//
// Swap.cpp for  in /home/vatine_m/piscineTek2/cpp_gkrellm
// 
// Made by vatinelle maxime
// Login   <vatine_m@epitech.net>
// 
// Started on  Sun Jan 24 05:43:43 2016 vatinelle maxime
// Last update Sun Jan 24 05:45:37 2016 vatinelle maxime
//

#include "Swap.hpp"

Swap::Swap()
{
  attron(COLOR_PAIR(3));
  mvprintw(10, 45, _vecSwap[1].c_str());      
  mvprintw(11, 45, _vec[5].c_str());
  mvprintw(12, 45, _vec[14].c_str());
  mvprintw(13, 45, _vec[15].c_str());
  attroff(COLOR_PAIR(3));
}

Swap::~Swap()
{

}
