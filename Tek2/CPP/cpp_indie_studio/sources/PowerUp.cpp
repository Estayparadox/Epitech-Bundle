//
// PowerUp.hpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Thu May 12 15:28:59 2016 Dylan Debernard
// Last update Mon Jun  6 17:31:44 2016 Dylan Debernard
//

#include			"PowerUp.hpp"

PowerUp::PowerUp(irr::scene::ISceneManager *sceneManager)
{
  _rocket = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh("media/map7/F-35_Lightning_II.obj"));
}

PowerUp::PowerUp(irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::core::vector3df vector)
{
  _bonus = sceneManager->addCubeSceneNode(5);
  _bonus->setPosition(vector);
  _bonus->setMaterialTexture(0, driver->getTexture("media/wall.bmp"));
  _bonus->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  _bonusA = sceneManager->createRotationAnimator(irr::core::vector3df(0, 1, 0));
  _bonus->addAnimator(_bonusA);
  _bonusA->drop();
}

PowerUp::~PowerUp()
{
}

void	PowerUp::setRocket(irr::scene::IAnimatedMeshSceneNode *rocket)
{
  _rocket = rocket;
}

const irr::scene::ISceneNode *PowerUp::getBonus()
{
  return (_bonus);
}

const irr::scene::IAnimatedMeshSceneNode *PowerUp::getRocket()
{
  return (_rocket);
}

void	PowerUp::setBonus()
{
  _bonus->remove();
}
