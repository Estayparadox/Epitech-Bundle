//
// AI.hpp for  in /home/debern_d/2_rendu/PSU_2015_zappy/src_client
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Thu Jun 23 19:00:31 2016 Dylan Debernard
// Last update Sun Jun 26 18:19:52 2016 pereniguez joseph
//

#include	"head/AI.hpp"
#include	"head/Inventaire.hpp"

void		AI::initAI()
{
  std::string	str;
  Inventaire	*i = new Inventaire();
  while (1)
    {
      std::cin >> str;
      if (str == "quit")
        break;
      i->cmdInventaire();
    }
}

AI::AI(const std::string teamname, const int port, const std::string hostname)
{
  _AITeamname = teamname;
  _AIPort = port;
  _AIHostname = hostname;
}

AI::AI()
{
}

AI::~AI()
{
}
