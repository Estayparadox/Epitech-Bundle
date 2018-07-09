//
// Cars.hpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Mon May 02 18:26:28 2016 Dylan Debernard
// Last update Mon Jun  6 17:09:07 2016 Dylan Debernard
//

#ifndef			_CARS_HPP_
# define		_CARS_HPP_

#include		<irrlicht.h>
#include		<iostream>
#include		<vector>
#include		<fstream>
#include		<KeyEvent.hpp>
#include		"PowerUp.hpp"
#include		"Core.hpp"

class			Cars : public KeyEvent
{
public:
  Cars();
  Cars(int player);
  Cars(Core core, irr::scene::ISceneManager *sceneManager, int player);
  Cars(Core core, irr::scene::ISceneManager *sceneManager,
       irr::video::IVideoDriver *driver, int player);
  ~Cars();
  int			controle_car(irr::scene::ISceneManager *sceneManager,
				     KeyEvent keyEvent, const irr::f32 frameDeltaTime,
				     std::vector<Cars> player, Core core,
				     std::vector<PowerUp> powerUp,
				     std::vector<irr::scene::ISceneNode*> flag);
  void			carsGetTurbo(KeyEvent keyEvent, PowerUp p);
  void			carsGetRocket(KeyEvent keyEvent, PowerUp p);
  void			carsGetShield(KeyEvent keyEvent, PowerUp p);
  void			carsShield(KeyEvent keyEvent,
				   irr::scene::ISceneManager *sceneManager);
  void			carsMouvement(KeyEvent keyEvent, const irr::f32 frameDeltaTime);
  void			carsTurbo(KeyEvent keyEvent);
  int			carsPowerUpRocket(irr::scene::ISceneManager *sceneManager,
				    KeyEvent keyEvent, const irr::f32 frameDeltaTime,
				    std::vector<Cars> player, Core core);
  void			isUnderTheMap(KeyEvent keyEvent);
  void			loadGame(std::vector<Cars> player);
  void			getControle();
  void			setControle();
  int			carsStartLine(Core core, std::vector<irr::scene::ISceneNode*> flag);
  void			setSpeed(int speed);

public:
  int			_player;
  int			_laps;
  bool			_cp;

  irr::f32		_speed;
  irr::f32		_maxSpeed;

  irr::EKEY_CODE	_up;
  irr::EKEY_CODE	_down;
  irr::EKEY_CODE	_right;
  irr::EKEY_CODE	_left;
  irr::EKEY_CODE	_turbo;
  irr::EKEY_CODE	_rocketkey;
  irr::EKEY_CODE	_shieldkey;

  float			_px;
  float			_py;
  float			_pz;

  float			_rx;
  float			_ry;
  float			_rz;

  irr::scene::IMeshSceneNode	*_node;
  irr::scene::IMeshSceneNode	*_rocketMesh;
  irr::scene::ISceneNode	*_shieldMesh;

  int			_powerup;
  int			_rocketPU;
  int			_shield;
  bool			_rocket;
};

#endif			/* !_CARS_HPP_ */
