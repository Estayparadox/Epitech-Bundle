//
// main.cpp for  in /home/arrazo_p/tek2/trade
//
// Made by pedroantonio arrazolaleon
// Login   <arrazo_p@epitech.net>
//
// Started on  Sat Jun  4 10:25:17 2016 pedroantonio arrazolaleon
// Last update Sat Jun  4 14:59:54 2016 pedroantonio arrazolaleon
//

#include "Trade.hpp"

int			main()
{
  int		money;
  int		day;
  std::string	overMoney;

  std::cin >> money;
  std::cin >> day;

  Trade		trader(money, day);

  std::cin >> overMoney;

  while (overMoney != "--END--" && trader.getToday() < trader.getDay())
    {
      trader.trade(atoi(overMoney.c_str()));
      overMoney = "";

      std::cin >> overMoney;
    }
}
