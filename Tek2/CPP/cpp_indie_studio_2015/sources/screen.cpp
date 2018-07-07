//
// screen.cpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Thu May 19 21:27:19 2016 Dylan Debernard
// Last update Mon Jun  6 17:19:38 2016 Dylan Debernard
//

#include		<hyper_sprint.h>
#include		<irrKlang.h>

void                    splashScreen(irr::IrrlichtDevice *device,
                                     irr::video::IVideoDriver *driver,
                                     irr::scene::ISceneManager *sceneManager)
{
  irrklang::ISoundEngine*	engine = irrklang::createIrrKlangDevice();
  
  device->getGUIEnvironment()->addImage(driver->getTexture("media/SplashScreen/SplashScreen4.jpg"), irr::core::position2d<irr::s32>(0,0));
  sceneManager->drawAll();
  device->getGUIEnvironment()->drawAll();
  engine->play2D("media/sounds/Jingle.wav");
  driver->endScene();
  while (device->run())
    {
      driver->beginScene(true, true, irr::video::SColor(0,200,200,200));
      sleep(6);
      driver->endScene();
      break;
    }
}

void                    loadingScreen(irr::IrrlichtDevice *device,
                                      irr::video::IVideoDriver *driver,
                                      irr::gui::IGUIEnvironment* env)
{
  device->getGUIEnvironment()->addImage(driver->getTexture("media/LoadingScreen/LoadingMenuSansExplosion.jpg"), irr::core::position2d<irr::s32>(0,0));
  driver->beginScene(true, true, irr::video::SColor(0,200,200,200));
  env->drawAll();
  driver->endScene();
}
