//
// Warpsystem.hh for Warpsystem in /home/pereni_j/Rendu/piscine_cpp_d07m/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Tue Jan 12 23:06:34 2016 pereniguez joseph
// Last update Wed Jan 13 08:24:23 2016 pereniguez joseph
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
    bool	isStable();
    void	setStability(bool);
  };
  class		Core
  {
  private:
    QuantumReactor	*_coreReactor;
  public:
    Core(QuantumReactor *_coreReactor);
    ~Core();
    QuantumReactor	*checkReactor();
  };
}

#endif /* __WARPSYSTEM_HH__ */
