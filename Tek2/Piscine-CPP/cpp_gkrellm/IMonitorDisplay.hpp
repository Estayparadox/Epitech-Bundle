//
// IMonitorDisplay.hpp for  in /home/vatine_m/piscineTek2/cpp_gkrellm
// 
// Made by vatinelle maxime
// Login   <vatine_m@epitech.net>
// 
// Started on  Sun Jan 24 05:57:10 2016 vatinelle maxime
// Last update Sun Jan 24 06:02:23 2016 vatinelle maxime
//

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include "IMonitorModule.hpp"
#include "Time.hpp"
#include "OperatingModule.hpp"
#include "MachineName.hpp"
#include "Core.hpp"
#include "Swap.hpp"

class IMonitorDisplay : public IMonitorModule
{
public:
  IMonitorDisplay();
  virtual ~IMonitorDisplay();
};

#endif
