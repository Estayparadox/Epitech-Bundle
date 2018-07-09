//
// Trade.cpp for  in /home/arrazo_p/tek2/trade
//
// Made by pedroantonio arrazolaleon
// Login   <arrazo_p@epitech.net>
//
// Started on  Sat Jun  4 10:28:51 2016 pedroantonio arrazolaleon
// Last update Sun Jun  5 22:23:29 2016 pereniguez joseph
//

#include "Trade.hpp"

Trade::Trade(int money, int day) : _Money(money), _Day(day), _Today(0), _Actions(0)
{
}

Trade::~Trade()
{
}

void		Trade::init(int &moyenne, int &variance, int &ecartType)
{
  int		i;

  i = 0;
  moyenne = 0;

  for (std::list<int>::iterator it = this->_Prevalues.begin(); it != this->_Prevalues.end(); ++it)
    {
      if (i < NBVAL)
	moyenne += (*it);
      else
	break ;
      i++;
    }

  moyenne /= i;
  i = 0;
  variance = 0;

  for (std::list<int>::iterator it = this->_Prevalues.begin(); it != this->_Prevalues.end(); ++it)
    {
      if (i < NBVAL)
	variance += pow(((*it) - moyenne), 2);
      else
	break ;
      i++;
    }

  variance /= i;
  ecartType = sqrt(variance);
}

int		Trade::check_Value(int newValue)
{
  int		i;
  int		moyenne;
  int		variance;
  int		ecartType;

  this->init(moyenne, variance, ecartType);

  if (newValue > moyenne + ecartType)
    {
      i = 0;

      while (newValue > moyenne + ecartType)
	{
	  i++;
	  moyenne += ecartType * i;
	}
      return (1);
    }
  else if (newValue < moyenne - ecartType)
    {
      i = 0;

      while (newValue < moyenne + ecartType)
	{
	  i++;
	  moyenne -= ecartType * i;
	}
      return (-1);
    }
  else
    return (0);
}

void		Trade::trade(int newValue)
{
  int		nb;

  if (this->_Today == this->_Day - 1)
    this->sell(newValue, this->_Actions);
  else if (this->_Prevalues.size() < NBVAL)
    this->wait();
  else
    {
      nb = this->check_Value(newValue);

      if (nb > 0)
	this->buy(newValue, nb);
      else if (nb < 0)
	this->sell(newValue, 0 - nb);
      else
	this->wait();
    }
  this->addValue(newValue);
  this->_Today++;
}
