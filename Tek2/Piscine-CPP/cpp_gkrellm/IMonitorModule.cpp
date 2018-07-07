//
// IMonitorModule.cpp for  in /home/vatine_m/piscineTek2/cpp_gkrellm
// 
// Made by vatinelle maxime
// Login   <vatine_m@epitech.net>
// 
// Started on  Sun Jan 24 05:54:46 2016 vatinelle maxime
// Last update Sun Jan 24 06:02:24 2016 vatinelle maxime
//

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

IMonitorModule::IMonitorModule() : _user(getenv("USER"))
{
  initscr();
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_RED, COLOR_WHITE);

  _vec = fileToVector("/proc/meminfo");
  _vecCpu = fileToVector("/proc/cpuinfo");
  _vecVersion = parseVersion("/proc/version");
  _vecSwap = fileToVector("/proc/swaps");
  _vecHost = fileToVector("/proc/sys/kernel/hostname");
}

IMonitorModule::~IMonitorModule()
{
  endwin();
}

std::vector<std::string> IMonitorModule::parseVersion(std::string file)
{
  std::string cpy;
  std::ifstream ifs(file.c_str(), std::ios::in);
  std::vector<std::string> v;
  int	i = 0;

  if (ifs)
    {
      while (getline(ifs, cpy, ' '))
	{
	  v.push_back(cpy);
	}
    }
  return (v);
}

std::string IMonitorModule::getTime() const
{
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%d-%m.%X", &tstruct);

  return buf;
}

std::vector<std::string> IMonitorModule::fileToVector(std::string file)
{
  std::string cpy;
  std::ifstream ifs(file.c_str(), std::ios::in);
  std::vector<std::string> v;
  int	i = 0;

  if (ifs)
    {
      while (getline(ifs, cpy, '\n'))
	{
	  v.push_back(cpy);
	}
    }
  return (v);
}
