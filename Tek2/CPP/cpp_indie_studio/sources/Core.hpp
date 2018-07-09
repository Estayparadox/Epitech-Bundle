//
// Core.hpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
// 
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
// 
// Started on  Wed May 11 18:30:18 2016 Dylan Debernard
// Last update Thu Jun  2 16:04:06 2016 Paul Rosset
//

#ifndef			_CORE_HPP_
# define		_CORE_HPP_

#include		<irrlicht.h>
#include		<iostream>
#include		<vector>
#include		<KeyEvent.hpp>

class			Core : public KeyEvent
{
public:
  Core();
  ~Core();

  void			setCam(int cam);
  void			setNbPlayer(int nbPlayer);
  void			setWinX(int winX);
  void			setWinY(int winY);
  void			setMapPath(std::string mapPath);
  void			setFullscreen(bool fullscreen);
  void			setButton(int button);
  void			setLaps(int laps);
  void			setFPS(bool fps);
  void			setCollision(bool collsion);
  void			setPowerUp(bool powerUp);
  void			setNbBot(int nbBot);
  void			setLevelBot(int levelBot);
  void                  setName(std::string name);

  const std::string     &getName();
  const int		&getCam();
  const int		&getNbPlayer();
  const int		&getWinX();
  const int		&getWinY();
  const std::string	&getMapPath();
  const bool		&getFullscreen();
  const int		&getButton();
  const int		&getLaps();
  const bool		&getFPS();
  const bool		&getCollision();
  const bool		&getPowerUp();
  const int		&getNbBot();
  const int		&getLevelBot();

public:
  bool			_record;
protected:
  int			_cam;
  int			_nbPlayer;
  int			_nbBot;
  int			_winX;
  int			_winY;
  std::string		_mapPath;
  std::string		_name;
  bool			_fullscreen;
  int			_button;
  int			_laps;
  bool			_fps;
  bool			_collision;
  bool			_powerUp;
  int			_levelBot;
};

#endif			/* !_CORE_HPP_ */
