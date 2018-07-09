//
// Camera.hpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Wed May 11 17:26:40 2016 Dylan Debernard
// Last update Mon Jun  6 23:31:23 2016 Dylan Debernard
//

#include			"Camera.hpp"

Camera::Camera(irr::scene::ISceneManager *sceneManager,
	       irr::video::IVideoDriver *driver,
	       std::vector<Cars> player, Core core)
{
  if (core.getCam() == 1)
    changeCameraTo3rd(sceneManager, core, player);
  else if (core.getCam() == 2)
    changeCameraToSkyview(sceneManager, core, player, driver);
  else if (core.getCam() == 3)
    _camera[0] = sceneManager->addCameraSceneNodeFPS();
  driver->setViewPort(irr::core::rect<irr::s32>(core.getWinX() / 2, 0, core.getWinX(),
						core.getWinY() / 2));

}

Camera::~Camera()
{
}

void	Camera::moveCamera(irr::scene::ISceneManager *sceneManager,
			   irr::video::IVideoDriver *driver,
			   std::vector<Cars> player, Core core)
{
  driver->setViewPort(irr::core::rect<irr::s32>(0, 0, core.getWinX(), core.getWinY()));
  driver->beginScene (true, true, irr::video::SColor(255,180,180,180));
  irr::core::vector3df forward;
  forward = irr::core::vector3df(sin(player[0]._node->getRotation().Y * 3.14 /180.0),
				 0, cos(player[0]._node->getRotation().Y * 3.14 /180.0)) *-1;
  _camera[0]->setPosition(player[0]._node->getPosition() - forward * 20 +
			  irr::core::vector3df(0, 10.0, 0));
  _camera[0]->setTarget(player[0]._node->getPosition());

  sceneManager->setActiveCamera(_camera[0]);
  if (core.getNbPlayer() == 2)
    driver->setViewPort(irr::core::rect<irr::s32>(0, 0, core.getWinX() / 2,
						  core.getWinY() / 2));
  else
    driver->setViewPort(irr::core::rect<irr::s32>(0, 0, core.getWinX(),
						  core.getWinY()));
  sceneManager->drawAll();
  if (core.getNbPlayer() == 2)
    {
      forward = irr::core::vector3df(sin(player[1]._node->getRotation().Y * 3.14 /180.0),0,
				     cos(player[1]._node->getRotation().Y * 3.14 /180.0))*-1;
      _camera[1]->setPosition(player[1]._node->getPosition() - forward * 20 +
			      irr::core::vector3df(0, 10.0, 0));
      _camera[1]->setTarget(player[1]._node->getPosition());
      driver->setViewPort(irr::core::rect<irr::s32>(core.getWinX() / 2, 0, core.getWinX(),
						    core.getWinY() / 2));
      sceneManager->setActiveCamera(_camera[1]);
      sceneManager->drawAll();
    }
}

void	Camera::changeCameraToSkyview(irr::scene::ISceneManager *sceneManager,
				      Core core, std::vector<Cars> player,
				      irr::video::IVideoDriver *driver)
{
  if (core.getMapPath() == "media/mapSW/MapSnowV4.obj")
    _camera[0] = sceneManager->addCameraSceneNode(0, irr::core::vector3df(0, 500, 100),
						  irr::core::vector3df(0, 0, 101));
  else
    _camera[0] = sceneManager->addCameraSceneNode(0, irr::core::vector3df(0, 300, 100),
                                                  irr::core::vector3df(0, 0, 101));
  if (core.getNbPlayer() == 2)
    {
      driver->setViewPort(irr::core::rect<irr::s32>(0, 0, core.getWinX(),
                                                    core.getWinY()));
      sceneManager->setActiveCamera(_camera[0]);
      sceneManager->drawAll();
    }
}

void    Camera::changeCameraTo3rd(irr::scene::ISceneManager *sceneManager,
				      Core core, std::vector<Cars> player)
{
  _camera[0] = sceneManager->addCameraSceneNodeFPS(0, 100, 0.05);
  _camera[0]->setPosition(irr::core::vector3df(0,15,103));
  _camera[0]->setPosition(player[0]._node->getPosition() + irr::core::vector3df(-20, 10.0,0));
  _camera[0]->setTarget(player[0]._node->getPosition());
  _camera[0]->setInputReceiverEnabled(false);
  
  if (core.getNbPlayer() == 2)
    {
      _camera[1] = sceneManager->addCameraSceneNodeFPS(0, 100, 0.05);
      _camera[1]->setPosition(irr::core::vector3df(0,15,103));
      _camera[1]->setPosition(player[1]._node->getPosition() + irr::core::vector3df(-20, 10.0,0));
      _camera[1]->setTarget(player[1]._node->getPosition());
      _camera[1]->setInputReceiverEnabled(false);
    }
}
