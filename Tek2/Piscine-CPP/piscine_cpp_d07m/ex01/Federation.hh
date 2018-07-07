//
// Federation.hh for Federation in /home/pereni_j/Rendu/piscine_cpp_d07m/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Tue Jan 12 23:08:34 2016 pereniguez joseph
// Last update Wed Jan 13 08:24:09 2016 pereniguez joseph
//

#ifndef __FEDERATION_HH__
#define __FEDERATION_HH__

#include <iostream>
#include <string>

#include "Warpsystem.hh"

namespace		Federation
{
  namespace		Starfleet
  {
    class               Captain
    {
    public:
      Captain(std::string name);
      ~Captain();
      std::string       getName();
      int               getAge();
      void              setAge(int nb);

    private:
      std::string       _name;
      int               _age;
    };

    class               Ensign
    {
    public:
      Ensign(std::string name);
      ~Ensign();
      std::string       name;
    };

    class		Ship
    {
    private:
      int               _length;
      int               _width;
      std::string       _name;
      short             _maxWarp;
      WarpSystem::Core  *Core;
      Federation::Starfleet::Captain *capt;
    public:
      Ship(int lenght,int width, std::string name, short maxWarp);
      ~Ship();
      void		setupCore(WarpSystem::Core*);
      void		checkCore();
      void		promote(Federation::Starfleet::Captain *capt);
    };
  };

  class			Ship
  {
  private:
    int			_length;
    int			_width;
    std::string		_name;
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
