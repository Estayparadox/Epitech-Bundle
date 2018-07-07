//
// Borg.hh for Borg in /home/pereni_j/Rendu/piscine_cpp_d07m/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Tue Jan 12 22:58:43 2016 pereniguez joseph
// Last update Wed Jan 13 08:23:55 2016 pereniguez joseph
//

#ifndef __BORG_HH__
#define __BORG_HH__

#include "Warpsystem.hh"
#include "Federation.hh"

namespace	Borg
{
  class		Ship
  {
  private:
    int		_side;
    short	_maxWarp;
    WarpSystem::Core *core;
  public:
    Ship();
    ~Ship();
    void	setupCore(WarpSystem::Core *core);
    void        checkCore();
  };
};

#endif /* __BORG_HH__ */
