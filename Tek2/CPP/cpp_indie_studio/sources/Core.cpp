//
// Core.hpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Wed May 11 18:12:33 2016 Dylan Debernard
// Last update Thu Jun  2 16:01:55 2016 Paul Rosset
//

#include			"Core.hpp"

Core::Core()
{
  _cam = 2;
  _nbPlayer = 1;
  _nbBot = 1;
  _winX = 640;
  _winY = 480;
  _fullscreen = false;
  _button = 30;
  _laps = 3;
  _fps = true;
  _collision = false;
  _powerUp = true;
  _record = false;
  _levelBot = 1;
}

Core::~Core()
{
}

void                            Core::setName(std::string name)
{
  this->_name = name;
}

const std::string                       &Core::getName()
{
  return (this->_name);
}

void				Core::setCam(int cam)
{
  _cam = cam;
}

void				Core::setNbPlayer(int nbPlayer)
{
  _nbPlayer= nbPlayer;
}

void				Core::setWinX(int winX)
{
  _winX = winX;
}

void				Core::setWinY(int winY)
{
  _winY= winY;
}

void				Core::setMapPath(std::string mapPath)
{
  _mapPath = mapPath;
}

void				Core::setFullscreen(bool fullscreen)
{
  _fullscreen = fullscreen;
}

void				Core::setButton(int button)
{
  _button = button;
}

void				Core::setLaps(int laps)
{
  _laps = laps;
}

void				Core::setFPS(bool fps)
{
  _fps = fps;
}

void				Core::setCollision(bool collision)
{
  _collision = collision;
}

void				Core::setPowerUp(bool powerUp)
{
  _powerUp = powerUp;
}

void				Core::setNbBot(int nbBot)
{
  _nbBot = nbBot;
}

void				Core::setLevelBot(int levelBot)
{
  _levelBot = levelBot;
}

const int			&Core::getCam()
{
  return (_cam);
}

const int			&Core::getNbPlayer()
{
  return (_nbPlayer);
}

const int			&Core::getWinX()
{
  return (_winX);
}

const int			&Core::getWinY()
{
  return (_winY);
}

const std::string		&Core::getMapPath()
{
  return (_mapPath);
}

const bool			&Core::getFullscreen()
{
  return (_fullscreen);
}

const int			&Core::getButton()
{
  return (_button);
}

const int			&Core::getLaps()
{
  return (_laps);
}

const bool			&Core::getFPS()
{
  return (_fps);
}

const bool			&Core::getCollision()
{
  return (_collision);
}

const bool			&Core::getPowerUp()
{
  return (_powerUp);
}

const int			&Core::getNbBot()
{
  return (_nbBot);
}

const int			&Core::getLevelBot()
{
  return (_levelBot);
}
