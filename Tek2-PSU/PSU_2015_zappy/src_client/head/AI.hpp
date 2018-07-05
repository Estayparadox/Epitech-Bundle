//
// AI.hpp for  in /home/debern_d/2_rendu/PSU_2015_zappy/src_client
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Thu Jun 23 19:00:31 2016 Dylan Debernard
// Last update Sun Jun 26 18:14:34 2016 pereniguez joseph
//

#ifndef			__AI_HPP__
# define		__AI_HPP__

# include		"Core.hpp"

enum
  {
    LINEMATE = 1,
    DERAUMERE = 2,
    SIBUR = 3,
    MENDIANE = 4,
    PHIRAS = 5,
    THYSTAME = 6
  };

class			AI : public Core
{
public:
  AI();
  AI(const std::string teamname, const int port, const std::string hostname);
  ~AI();
  void			initAI();

protected:
  std::string		_AITeamname;
  int			_AIPort;
  std::string		_AIHostname;
};

#endif			/* __AI_HPP__ */
