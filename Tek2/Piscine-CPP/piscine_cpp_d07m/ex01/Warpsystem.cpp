//
// Warpsystem.cpp for Warpsystem in /home/pereni_j/Rendu/piscine_cpp_d07m/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Tue Jan 12 23:05:59 2016 pereniguez joseph
// Last update Wed Jan 13 08:24:17 2016 pereniguez joseph
//

#include "Warpsystem.hh"

WarpSystem::QuantumReactor::QuantumReactor()
{
  this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

bool	WarpSystem::QuantumReactor::isStable()
{
  return this->_stability;
}

void	WarpSystem::QuantumReactor::setStability(bool stability)
{
  this->_stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *core)
{
  this->_coreReactor = core;
}

WarpSystem::Core::~Core()
{
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
  return _coreReactor;
}
