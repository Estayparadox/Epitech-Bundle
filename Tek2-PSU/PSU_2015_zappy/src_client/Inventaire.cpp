//
// Inventaire.hpp for  in /home/debern_d/2_rendu/PSU_2015_zappy/src_client
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Fri Jun 24 14:41:03 2016 Dylan Debernard
// Last update Sun Jun 26 18:20:20 2016 pereniguez joseph
//

#include		"head/Inventaire.hpp"

void			Inventaire::cmdInventaire()
{
  std::cout << "{";
  if (_nourriture != 0)
    std::cout << "nourriture " << _nourriture;
  if (_linemate != 0)
    std::cout << ", linemate " << _linemate;
  if (_deraumere != 0)
    std::cout << ", deraumere " << _linemate;
  if (_sibur != 0)
    std::cout << ", sibur " << _linemate;
  if (_mendiane != 0)
    std::cout << ", mendiane " << _linemate;
  if (_phiras != 0)
    std::cout << ", phiras " << _linemate;
  if (_thystame != 0)
    std::cout << ", thystame " << _linemate;
  std::cout << "}" << std::endl;
}

Inventaire::Inventaire()
{
  _nourriture = 0;
  _linemate = 0;
  _deraumere = 0;
  _sibur = 0;
  _mendiane = 0;
  _phiras = 0;
  _thystame = 0;
}

Inventaire::~Inventaire()
{
}
