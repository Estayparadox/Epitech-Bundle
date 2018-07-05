//
// Core.hpp for  in /home/debern_d/2_rendu/zappy
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Mon Jun 20 10:42:31 2016 Dylan Debernard
// Last update Sun Jun 26 18:20:13 2016 pereniguez joseph
//

#include		"head/Core.hpp"
#include		"head/Socket.hpp"
#include		"head/AI.hpp"

void			Core::initClient()
{
  Socket *socket = new Socket(_port, _hostname);
  AI *ai = new AI(_teamname, _port, _hostname);
  ai->initAI();
}

Core::Core(int ac, char **av)
{
  _port = 0;
  _hostname = "127.0.0.1";
  for(int i = 0; av[i]; i++)
    {
      if ((std::string)av[i] == "-n" && av[i + 1])
	_teamname = av[i + 1];
      else if ((std::string)av[i] == "-p" && av[i + 1])
	_port = atoi(av[i + 1]);
      else if ((std::string)av[i] == "-h" && av[i + 1])
	_hostname = av[i + 1];
    }
  if (_port == 0 || _teamname.empty())
    {
      std::cerr << "Usage : zappy_ai -p PORT -n TEAMNAME [-h IP]" << std::endl;
      exit(1);
    }
  std::cout << "teamname : " << _teamname << std::endl;
  std::cout << "port : " << _port << std::endl;
  std::cout << "hostname : " << _hostname << std::endl;
}

Core::Core()
{
}

Core::~Core()
{
  std::cout << "Disconnected" << std::endl;
}

int	Core::getPort()
{
  return (_port);
}

void	Core::setPort(int port)
{
  _port = port;
}
