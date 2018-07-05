//
// Inventaire.hpp for  in /home/debern_d/2_rendu/PSU_2015_zappy/src_client
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Fri Jun 24 14:41:03 2016 Dylan Debernard
// Last update Sun Jun 26 18:07:13 2016 pereniguez joseph
//

#ifndef			__INVENTAIRE_HPP__
# define		__INVENTAIRE_HPP__

# include		"AI.hpp"

class			Inventaire : public AI
{
public:
  Inventaire();
  ~Inventaire();
  void			cmdInventaire();

protected:
  int			_nourriture;
  int			_linemate;
  int			_deraumere;
  int			_sibur;
  int			_mendiane;
  int			_phiras;
  int			_thystame;
};

#endif			/* __INVENTAIRE_HPP__ */
