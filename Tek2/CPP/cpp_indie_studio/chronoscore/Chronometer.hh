//
// Chronometer.hh for Chronometer in /home/pereni_j/Rendu/tools
//
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
//
// Started on  Wed May  4 15:44:18 2016 pereniguez joseph
// Last update Thu Apr  6 14:41:28 2017 pereniguez joseph
//

#ifndef __CHRONOMETER_HH__
# define __CHRONOMETER_HH__

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <map>
# include <list>
# include <deque>
# include <vector>
# include <string>
# include <utility>
# include <string.h>
# include <algorithm>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>
# include "../sources/Core.hpp"

class				Score
{
private:
  int				mil;
  int				sec;
  int				min;
  std::string			laps;
public:
  Score();
  ~Score();
  void				scoreWritter(std::string, std::string);
  void				recup(int, int, int);
  void				sortTab(std::map<std::string, int >, std::string, Core, std::string);
  std::map<std::string,int>	PushTab(std::string);
};

#endif /* __CHRONOMETER_HH__ */
