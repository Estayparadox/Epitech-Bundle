//
// Federation.hh for Federation in /home/pereni_j/Rendu/piscine_cpp_d07m/ex00
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Tue Jan 12 09:06:29 2016 pereniguez joseph
// Last update Tue Jan 12 16:57:38 2016 pereniguez joseph
//

#ifndef __FEDERATION_HH__
#define __FEDERATION_HH__

#include <iostream>
#include <string>

#include "Warpsystem.hh"

namespace Federation
{
  namespace Starfleet
  {
    class       Ship
    {
    private:
      int               _length;
      int               _width;
      std::string       _name;
      short             _maxWarp;
      WarpSystem::Core  *Core;

  public:
      Ship(int lenght,int width, std::string name, short maxWarp);
      ~Ship();
      void		setupCore(WarpSystem::Core*);
      void		checkCore();
    };
  };

  class	Ship
  {
  private:
    int		_length;
    int		_width;
    std::string	_name;
    short		_maxWarp;
    WarpSystem::Core	*Core;

  public:
    Ship(int lenght, int width, std::string name);
    ~Ship();
    void		setupCore(WarpSystem::Core*);
    void		checkCore();
  };
};
#endif /* __FEDERATION_HH__ */
