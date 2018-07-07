//
// IMonitorDisplay.cpp for  in /home/vatine_m/piscineTek2/cpp_gkrellm
// 
// Made by vatinelle maxime
// Login   <vatine_m@epitech.net>
// 
// Started on  Sun Jan 24 05:57:56 2016 vatinelle maxime
// Last update Sun Jan 24 06:00:16 2016 vatinelle maxime
//

#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay()
{

}

IMonitorDisplay::~IMonitorDisplay()
{

}

int	main()
{
  IMonitorModule *mo = new IMonitorModule;
  while (1)
    {
      OperatingModule *o = new OperatingModule;
      Time *t = new Time;
      MachineName *ma = new MachineName;
      Core *c = new Core;
      Swap *s = new Swap;
      
      curs_set(0);
      refresh();
      sleep(1);
    }
  return (0);
}
