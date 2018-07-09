//
// SetGet.cpp for SetGet in /home/pereni_j/Rendu/trade
//
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
//
// Started on  Sun Jun  5 21:52:57 2016 pereniguez joseph
// Last update Sun Jun  5 22:18:09 2016 pereniguez joseph
//

#include "Trade.hpp"

void		Trade::setMoney(int money)
{
  this->_Money = money;
}

int		Trade::getMoney() const
{
  return (this->_Money);
}

void		Trade::setDay(int day)
{
  this->_Day = day;
}

int		Trade::getDay() const
{
  return (this->_Day);
}

void		Trade::setToday(int today)
{
  this->_Today = today;
}

int		Trade::getToday() const
{
  return (this->_Today);
}

void		Trade::addValue(int value)
{
  this->_Prevalues.push_front(value);
}

void		Trade::delValue()
{
  this->_Prevalues.pop_back();
}
