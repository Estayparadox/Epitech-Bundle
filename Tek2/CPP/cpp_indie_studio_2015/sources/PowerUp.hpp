//
// PowerUp.hpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Thu May 12 15:28:59 2016 Dylan Debernard
// Last update Mon Jun  6 17:10:47 2016 Dylan Debernard
//

#ifndef					_POWERUP_HPP_
# define				_POWERUP_HPP_

#include				<irrlicht.h>

class					PowerUp
{
public:
  PowerUp(irr::scene::ISceneManager *sceneManager);
  PowerUp(irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::core::vector3df vector);
  ~PowerUp();

  void	setRocket(irr::scene::IAnimatedMeshSceneNode *rocket);
  void	setBonus();
  const irr::scene::ISceneNode		*getBonus();
  const irr::scene::IAnimatedMeshSceneNode *getRocket();

public:
  irr::scene::ISceneNode		*_bonus;
  irr::scene::ISceneNodeAnimator	*_bonusA;
  irr::scene::IAnimatedMeshSceneNode	*_rocket;
};

#endif					/* !_POWERUP_HPP_ */
