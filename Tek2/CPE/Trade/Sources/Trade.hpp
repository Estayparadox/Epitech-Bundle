//
// Trade.hpp for  in /home/arrazo_p/tek2/trade
//
// Made by pedroantonio arrazolaleon
// Login   <arrazo_p@epitech.net>
//
// Started on  Sat Jun  4 10:29:03 2016 pedroantonio arrazolaleon
// Last update Sun Jun  5 22:17:35 2016 pereniguez joseph
//

#ifndef __TRADE_HPP__
# define __TRADE_HPP__

# include <iostream>
# include <exception>
# include <string>
# include <list>
# include <stdlib.h>
# include <math.h>

# define NBVAL 5

class			Trade
{
private:
  int			_Money;
  int			_Day;
  int			_Today;
  int			_Actions;
  std::list<int>	_Prevalues;
public:
  Trade(int, int);
  ~Trade();
  void			setMoney(int);
  int			getMoney() const;
  void			setDay(int);
  int			getDay() const;
  void			setToday(int);
  int			getToday() const;
  void			addValue(int);
  void			delValue();
  void			buy(int, int);
  void			sell(int, int);
  void			wait();
  void			init(int &, int &, int &);
  int			check_Value(int);
  void			trade(int);
};

#endif /* __TRADE_HPP__ */
