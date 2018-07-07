//
// Action.cpp for Action in /home/pereni_j/Rendu/trade
//
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
//
// Started on  Sun Jun  5 21:48:46 2016 pereniguez joseph
// Last update Sun Jun  5 22:21:58 2016 pereniguez joseph
//

#include "Trade.hpp"

void		Trade::buy(int newValue, int nb)
{
  while ((nb * newValue) + (0.0015 * nb * newValue) > this->_Money)
    nb--;

  if (nb != 0)
    {
      this->_Actions += nb;
      this->_Money -= ((nb * newValue) + (0.0015 * nb * newValue));
      std::cout << "buy " << nb << std::endl;
    }
  else
    this->wait();
}

void		Trade::sell(int newValue, int nb)
{
  if (nb > this->_Actions)
    nb = this->_Actions;

  if (nb != 0)
    {
      this->_Actions -= nb;
      this->_Money += ((nb * newValue) - (0.0015 * nb * newValue));
      std::cout << "sell " << nb << std::endl;
    }
  else
    this->wait();
}

void		Trade::wait()
{
  std::cout << "wait" << std::endl;
}
