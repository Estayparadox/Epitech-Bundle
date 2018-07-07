//
// Warpsystem.hh for Warpsystem in /home/pereni_j/Rendu/piscine_cpp_d07m/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Tue Jan 12 09:39:02 2016 pereniguez joseph
// Last update Tue Jan 12 16:48:03 2016 pereniguez joseph
//

#ifndef __WARPSYSTEM_HH__
#define __WARPSYSTEM_HH__

#include <iostream>
#include <string>

namespace       WarpSystem
{
  class		QuantumReactor
  {
  private:
    bool	_stability;
  public:
    QuantumReactor();
    ~QuantumReactor();
    bool isStable();
    void	setStability(bool);
  };
  class		Core
  {
  private:
    QuantumReactor *_coreReactor;
  public:
    Core(QuantumReactor *_coreReactor);
    ~Core();
    QuantumReactor *checkReactor();
  };
}

#endif /* __WARPSYSTEM_HH__ */
