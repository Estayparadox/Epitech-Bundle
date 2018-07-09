//
// Menu.hpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Wed May 18 10:14:05 2016 Dylan Debernard
// Last update Mon Jun  6 17:46:24 2016 Dylan Debernard
//

#include			<irrlicht.h>
#include			<irrKlang.h>
#include			<KeyEvent.hpp>
#include			<KeyEventMenu.hpp>
#include			"Core.hpp"
#include			"Cars.hpp"
#include			"Menu.hpp"

Menu::Menu()
{
}

Menu::Menu(Core core, irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver,
	   irr::scene::ISceneManager *sceneManager)
{
}

Menu::~Menu()
{
}

int				Menu::menuPlay(Core core, irr::IrrlichtDevice *device,
					       irr::video::IVideoDriver *driver,
					       irr::scene::ISceneManager *sceneManager,
					       SAppContext context)
{
  irr::gui::IGUIEnvironment* env = device->getGUIEnvironment();
  irr::gui::IGUIButton  *button[10];
  device->getGUIEnvironment()->addImage(driver->getTexture("media/SplashScreen/menu2.jpg"),
                                        irr::core::position2d<irr::s32>(0,0));

  button[0] = env->addButton(irr::core::rect<irr::s32>(10,900,10 + 200,900 + 50),
			     0,GUI_BACK_MENU, L"", L"");
  button[1] = env->addButton(irr::core::rect<irr::s32>(900,640,900 + 200,640 + 50),
			     0,GUI_ID_PLAY_BUTTON, L"", L"");
  button[2] = env->addButton(irr::core::rect<irr::s32>(500,240,500 + 200,240 + 50),
			     0,GUI_ID_SCORE_BUTTON, L"", L"");
  button[3] = env->addButton(irr::core::rect<irr::s32>(500,340,500 + 200,340 + 50),
                             0,GUI_ID_SETTING_BUTTON, L"", L"");
  button[4] = env->addButton(irr::core::rect<irr::s32>(500,440,500 + 200,440 + 50),
			     0,GUI_UP_CONTROLE_1, L"", L"");
  button[5] = env->addButton(irr::core::rect<irr::s32>(500,540,500 + 200,540 + 50),
                             0,GUI_DOWN_CONTROLE_1, L"", L"");
  button[6] = env->addButton(irr::core::rect<irr::s32>(500,640,500 + 200,640 + 50),
                             0,GUI_RIGHT_CONTROLE_1, L"", L"");
  button[7] = env->addButton(irr::core::rect<irr::s32>(500,740,500 + 200,740 + 50),
                             0,GUI_LEFT_CONTROLE_1, L"", L"");
  button[8] = env->addButton(irr::core::rect<irr::s32>(500,840,500 + 200,840 + 50),
                             0,GUI_TURBO_CONTROLE_1, L"", L"");
  button[0]->setImage(driver->getTexture("media/Bouton/BoutonBack.png"));
  button[1]->setImage(driver->getTexture("media/Bouton/BoutonPlay.png"));
  button[2]->setImage(driver->getTexture("media/Bouton/1Player.jpg"));
  button[3]->setImage(driver->getTexture("media/Bouton/BoutonMap1.jpg"));
  button[4]->setImage(driver->getTexture("media/Bouton/Tour3.jpg"));
  button[5]->setImage(driver->getTexture("media/Bouton/BoutonBot.jpg"));
  button[6]->setImage(driver->getTexture("media/Bouton/BoutonCamera.jpg"));
  button[7]->setImage(driver->getTexture("media/Bouton/Normal.jpg"));
  button[8]->setImage(driver->getTexture("media/Bouton/PowerUpON.jpg"));
  context.device = device;
  context.button = 0;
  context.bind1 = 0;
  KeyEventMenu receiver(context);
  KeyEvent      keyEvent;
  irrklang::ISoundEngine*	MenuS = irrklang::createIrrKlangDevice();
  MenuS->play2D("media/sounds/Accueil.wav", true);
  context.device->setEventReceiver(&receiver);
  keyEvent.Key = (irr::EKEY_CODE)0;
  core.setMapPath("media/map7/mapOvalGood6.obj");

  irr::gui::IGUIElement* root = env->getRootGUIElement();
  env->addEditBox(L"ENTER YOUR NAME", irr::core::rect<irr::s32>(900, 600, 900 + 200, 600 + 20), true, root,42);
  irr::core::stringc	s;
  std::string		tmp;
  s = root->getElementFromId(42, true)->getText();
  while (context.device->run())
    {
      driver->beginScene(true, true, irr::video::SColor(0,200,200,200));
      env->drawAll();
      s = root->getElementFromId(42, true)->getText();
      tmp = s.c_str();
      core.setName(tmp);
      driver->endScene();
      if (context.button == 1)
	{
	  MenuS->drop();
	  context.button = 0;
	  button[0]->remove();
	  button[1]->remove();
	  button[2]->remove();
	  button[3]->remove();
	  button[4]->remove();
	  button[5]->remove();
	  button[6]->remove();
	  button[7]->remove();
	  button[8]->remove();
	  device->getCursorControl()->setVisible(false);
	  HyperSprint(core, device, driver, sceneManager);
	  return (1);
	}
      if (context.button == 2)
	{
	  if (core.getNbPlayer() == 1)
	    {
	      core.setNbPlayer(2);
	      button[2]->setImage(driver->getTexture("media/Bouton/2Players.jpg"));
	    }
	  else if (core.getNbPlayer() == 2)
	    {
	      core.setNbPlayer(1);
	      button[2]->setImage(driver->getTexture("media/Bouton/1Player.jpg"));
	    }
	  context.button = 0;
	}
      if (context.button == 3)
	{
	  if (core.getMapPath() == "media/mapSW/MapSnowV4.obj")
	    {
	      core.setMapPath("media/map7/mapOvalGood6.obj");
	      button[3]->setImage(driver->getTexture("media/Bouton/BoutonMap1.jpg"));
	    }
	  else
	    {
	      button[3]->setImage(driver->getTexture("media/Bouton/BoutonMap2.jpg"));
	      core.setMapPath("media/mapSW/MapSnowV4.obj");
	    }
	  context.button = 0;
	}
      if (context.button == 4)
        {
	  MenuS->drop();
          context.button = 0;
	  return (2);
        }
      if (context.bind1 == 1)
	{
	  if (core.getLaps() == 1)
	    {
	      button[4]->setImage(driver->getTexture("media/Bouton/Tour3.jpg"));
	      core.setLaps(3);
	    }
	  else if (core.getLaps() == 3)
	    {
	      button[4]->setImage(driver->getTexture("media/Bouton/Tour5.jpg"));
	      core.setLaps(5);
	      }
	  else if (core.getLaps() == 5)
	    {
	      button[4]->setImage(driver->getTexture("media/Bouton/Tour1.jpg"));
	      core.setLaps(1);
	    }
	  context.bind1 = 0;
	}
      if (context.bind1 == 2)
	{
	  if (core.getNbBot() == 1)
	    {
	      button[5]->setImage(driver->getTexture("media/Bouton/BoutonWithoutBot.jpg"));
              core.setNbBot(0);
	    }
	  else
	    {
	      button[5]->setImage(driver->getTexture("media/Bouton/BoutonBot.jpg"));
              core.setNbBot(1);
            }
	  context.bind1 = 0;
	}
      if (context.bind1 == 3)
	{
	  if (core.getCam() == 1)
	    {
	      button[6]->setImage(driver->getTexture("media/Bouton/BoutonCamera.jpg"));
	      core.setCam(2);
	    }
	  else
	    {
	      button[6]->setImage(driver->getTexture("media/Bouton/BoutonCamera2.jpg"));
	      core.setCam(1);
	    }
	  context.bind1 = 0;
	  }
      if (context.bind1 == 4)
	{
	  if (core.getLevelBot() == 1)
	    {
	      button[7]->setImage(driver->getTexture("media/Bouton/HardCore.jpg"));
	      core.setLevelBot(2);
	    }
	  else
	    {
	      button[7]->setImage(driver->getTexture("media/Bouton/Normal.jpg"));
	      core.setLevelBot(1);
	    }
	  context.bind1 = 0;
	}
      if (context.bind1 == 5)
	{
	  if (core.getPowerUp() == true)
	    {
	      button[8]->setImage(driver->getTexture("media/Bouton/PowerUpOFF.jpg"));
	      core.setPowerUp(false);
	    }
	  else
	    {
	      button[8]->setImage(driver->getTexture("media/Bouton/PowerUpON.jpg"));
	      core.setPowerUp(true);
	    }
	  context.bind1 = 0;
	}
    }
  return (0);
}

int				Menu::menuScore(Core core, irr::IrrlichtDevice *device,
						 irr::video::IVideoDriver *driver,
						 irr::scene::ISceneManager *sceneManager,
						 SAppContext context)
{
  irr::gui::IGUIEnvironment* env = device->getGUIEnvironment();
  irr::gui::IGUIButton  *button[2];
  device->getGUIEnvironment()->addImage(driver->getTexture("media/SplashScreen/menu2.jpg"),
					irr::core::position2d<irr::s32>(0,0));
  button[0] = env->addButton(irr::core::rect<irr::s32>(10,900,10 + 200,900 + 50),
			     0,GUI_BACK_MENU, L"", L"");
  button[0]->setImage(driver->getTexture("media/Bouton/BoutonBack.png"));

  context.device = device;
  context.button = 0;
  context.bind1 = 0;
  KeyEventMenu	receiver(context);
  KeyEvent	keyEvent;
  irrklang::ISoundEngine*	MenuS = irrklang::createIrrKlangDevice();
  MenuS->play2D("media/sounds/Accueil.wav", true);
  context.device->setEventReceiver(&receiver);
  keyEvent.Key = (irr::EKEY_CODE)0;
  irr::gui::IGUIFont* font = device->getGUIEnvironment()->getFont("media/font/fonthaettenschweiler.bmp");
  irr::core::stringw	score[6];
  std::string		filename[6] = 
    {"config/scoreUnTourMap1", "config/scoreUnTourMap2",
     "config/scoreTroisToursMap1", "config/scoreTroisToursMap2",
     "config/scoreCinqToursMap1", "config/scoreCinqToursMap2"};
  std::string		info[6] = 
    {"Map 1\n1 Tour\n", "Map 2\n1 Tour\n", "Map 1\n3 Tours\n",
     "Map 2\n3 Tours\n", "Map 1\n5 Tours\n", "Map 2\n5 Tours\n"};

  int	i(0);
  while (i < 6)
    {
      std::ifstream	file(filename[i].c_str(), std::ios::in);
      std::string	line;
      while (getline(file, line, '\n'))
	{
	  score[i] += info[i].c_str();
	  score[i] += line.c_str();
	  score[i] += "\n";
	}
      i++;
    }
  while (context.device->run())
    {
      driver->beginScene(true, true, irr::video::SColor(0,200,200,200));
      env->drawAll();
      font->draw(score[0],irr::core::rect<irr::s32>(core.getWinX()/3+50, core.getWinY()/2-100, 0,0),irr::video::SColor(255,0,255,0));
      font->draw(score[1],irr::core::rect<irr::s32>(core.getWinX()/3+150, core.getWinY()/2-100, 0,0),irr::video::SColor(255,0,255,0));
      font->draw(score[2],irr::core::rect<irr::s32>(core.getWinX()/3+250, core.getWinY()/2-100, 0,0),irr::video::SColor(255,0,255,0));
      font->draw(score[3],irr::core::rect<irr::s32>(core.getWinX()/3+350, core.getWinY()/2-100, 0,0),irr::video::SColor(255,0,255,0));
      font->draw(score[4],irr::core::rect<irr::s32>(core.getWinX()/3+450, core.getWinY()/2-100, 0,0),irr::video::SColor(255,0,255,0));
      font->draw(score[5],irr::core::rect<irr::s32>(core.getWinX()/3+550, core.getWinY()/2-100, 0,0),irr::video::SColor(255,0,255, 0));
      driver->endScene();
      if (context.button == 4)
        {
	  MenuS->drop();
          context.button = 0;
	  button[0]->remove();
	  return (1);
        }
    }
  return (0);
}

int				Menu::menuSetting(Core core, irr::IrrlichtDevice *device,
						  irr::video::IVideoDriver *driver,
						  irr::scene::ISceneManager *sceneManager,
						  SAppContext context)
{
  irr::gui::IGUIEnvironment* env = device->getGUIEnvironment();
  irr::gui::IGUIButton  *button[14];
  device->getGUIEnvironment()->addImage(driver->getTexture("media/SplashScreen/menu2.jpg"),
					irr::core::position2d<irr::s32>(0,0));

  device->getGUIEnvironment()->addImage(driver->getTexture("media/Bouton/PlayerOne.png"), irr::core::position2d<irr::s32>(10,10));
  device->getGUIEnvironment()->addImage(driver->getTexture("media/Bouton/PlayerTwo.png"), irr::core::position2d<irr::s32>(10,460));

  button[0] = env->addButton(irr::core::rect<irr::s32>(10, 110, 10 + 200, 110 + 50),
			     0,GUI_UP_CONTROLE_1, L"", L"");
  button[1] = env->addButton(irr::core::rect<irr::s32>(10, 160, 10 + 200, 160 + 50),
			     0,GUI_DOWN_CONTROLE_1, L"", L"");
  button[2] = env->addButton(irr::core::rect<irr::s32>(10, 210, 10 + 200, 210 + 50),
			     0,GUI_RIGHT_CONTROLE_1, L"", L"");
  button[3] = env->addButton(irr::core::rect<irr::s32>(10, 260, 10 + 200, 260 + 50),
			     0,GUI_LEFT_CONTROLE_1, L"", L"");
  button[4] = env->addButton(irr::core::rect<irr::s32>(10, 310, 10 + 200, 310 + 50),
			     0,GUI_TURBO_CONTROLE_1, L"", L"");
  button[5] = env->addButton(irr::core::rect<irr::s32>(10, 360, 10 + 200, 360 + 50),
			     0,GUI_ROCKETKEY_CONTROLE_1, L"", L"");
  button[6] = env->addButton(irr::core::rect<irr::s32>(10,900,10 + 200,900 + 50),
                             0, GUI_BACK_MENU, L"", L"");
  button[7] = env->addButton(irr::core::rect<irr::s32>(10, 560, 10 + 200, 560 + 50),
			     0,GUI_UP_CONTROLE_2, L"", L"");
  button[8] = env->addButton(irr::core::rect<irr::s32>(10, 610, 10 + 200, 610 + 50),
			     0,GUI_DOWN_CONTROLE_2, L"", L"");
  button[9] = env->addButton(irr::core::rect<irr::s32>(10, 660, 10 + 200, 660 + 50),
			     0,GUI_RIGHT_CONTROLE_2, L"", L"");
  button[10] = env->addButton(irr::core::rect<irr::s32>(10, 710, 10 + 200, 710 + 50),
			     0,GUI_LEFT_CONTROLE_2, L"", L"");
  button[11] = env->addButton(irr::core::rect<irr::s32>(10, 760, 10 + 200, 760 + 50),
			     0,GUI_TURBO_CONTROLE_2, L"", L"");
  button[12] = env->addButton(irr::core::rect<irr::s32>(10, 810, 10 + 200, 810 + 50),
			     0,GUI_ROCKETKEY_CONTROLE_2, L"", L"");

  button[0]->setImage(driver->getTexture("media/Bouton/BoutonUp.png"));
  button[1]->setImage(driver->getTexture("media/Bouton/BoutonDown.png"));
  button[2]->setImage(driver->getTexture("media/Bouton/BoutonRight.png"));
  button[3]->setImage(driver->getTexture("media/Bouton/BoutonLeft.png"));
  button[4]->setImage(driver->getTexture("media/Bouton/BoutonTurbo.png"));
  button[5]->setImage(driver->getTexture("media/Bouton/BoutonRocket.png"));
  button[6]->setImage(driver->getTexture("media/Bouton/BoutonBack.png"));
  button[7]->setImage(driver->getTexture("media/Bouton/BoutonUp.png"));
  button[8]->setImage(driver->getTexture("media/Bouton/BoutonDown.png"));
  button[9]->setImage(driver->getTexture("media/Bouton/BoutonRight.png"));
  button[10]->setImage(driver->getTexture("media/Bouton/BoutonLeft.png"));
  button[11]->setImage(driver->getTexture("media/Bouton/BoutonTurbo.png"));
  button[12]->setImage(driver->getTexture("media/Bouton/BoutonRocket.png"));

  context.device = device;
  context.button = 0;
  context.bind1 = 0;
  KeyEventMenu receiver(context);
  KeyEvent	keyEvent;
  irrklang::ISoundEngine*	MenuS = irrklang::createIrrKlangDevice();
  MenuS->play2D("media/sounds/Accueil.wav", true);
  context.device->setEventReceiver(&receiver);
  keyEvent.Key = (irr::EKEY_CODE)0;
  irr::gui::IGUIFont* font = device->getGUIEnvironment()->getFont("media/font/myfont.xml");
  while (context.device->run())
    {
      driver->beginScene(true, true, irr::video::SColor(0,200,200,200));
      env->drawAll();
      irr::core::stringw str;
      if (context.button == 4)
        {
	  MenuS->drop();
	  context.button = 0;
	  button[0]->remove();
	  button[1]->remove();
	  button[2]->remove();
	  button[3]->remove();
	  button[4]->remove();
	  button[5]->remove();
	  button[6]->remove();
	  button[7]->remove();
	  button[8]->remove();
	  button[9]->remove();
	  button[10]->remove();
	  button[11]->remove();
	  button[12]->remove();
	  return (1);
	}
      if (context.bind1 == 1)
	{
	  device->setEventReceiver(&keyEvent);
          if (keyEvent.Key != 0)
            {
	      Cars *player = new Cars(1);
	      player->_up = keyEvent.Key;
	      player->setControle();
              delete player;
              context.device->setEventReceiver(&receiver);
              keyEvent.Key = (irr::EKEY_CODE)0;
              context.bind1 = 0;
	    }
	}
      else if (context.bind1 == 2)
	{
          device->setEventReceiver(&keyEvent);
          if (keyEvent.Key != 0)
            {
              Cars *player = new Cars(1);
              player->_down = keyEvent.Key;
              player->setControle();
              delete player;
              context.device->setEventReceiver(&receiver);
              keyEvent.Key = (irr::EKEY_CODE)0;
              context.bind1 = 0;
            }
	}
      else if (context.bind1 == 3)
	{
          device->setEventReceiver(&keyEvent);
          if (keyEvent.Key != 0)
            {
              Cars *player = new Cars(1);
              player->_right = keyEvent.Key;
              player->setControle();
              delete player;
              context.device->setEventReceiver(&receiver);
              keyEvent.Key = (irr::EKEY_CODE)0;
              context.bind1 = 0;
            }
	}
      else if (context.bind1 == 4)
	{
          device->setEventReceiver(&keyEvent);
          if (keyEvent.Key != 0)
            {
              Cars *player = new Cars(1);
              player->_left = keyEvent.Key;
              player->setControle();
              delete player;
              context.device->setEventReceiver(&receiver);
              keyEvent.Key = (irr::EKEY_CODE)0;
              context.bind1 = 0;
            }
	}
      else if (context.bind1 == 5)
	{
          device->setEventReceiver(&keyEvent);
          if (keyEvent.Key != 0)
            {
              Cars *player = new Cars(1);
              player->_turbo = keyEvent.Key;
              player->setControle();
              delete player;
              context.device->setEventReceiver(&receiver);
              keyEvent.Key = (irr::EKEY_CODE)0;
              context.bind1 = 0;
            }
	}
      else if (context.bind1 == 6)
	{
          device->setEventReceiver(&keyEvent);
          if (keyEvent.Key != 0)
            {
              Cars *player = new Cars(1);
              player->_rocketkey = keyEvent.Key;
              player->setControle();
              delete player;
              context.device->setEventReceiver(&receiver);
              keyEvent.Key = (irr::EKEY_CODE)0;
              context.bind1 = 0;
            }
	}
      if (context.bind2 == 1)
        {
          device->setEventReceiver(&keyEvent);
          if (keyEvent.Key != 0)
            {
              Cars *player = new Cars(2);
              player->_up = keyEvent.Key;
              player->setControle();
              delete player;
              context.device->setEventReceiver(&receiver);
              keyEvent.Key = (irr::EKEY_CODE)0;
              context.bind2 = 0;
            }
        }
      else if (context.bind2 == 2)
        {
          device->setEventReceiver(&keyEvent);
          if (keyEvent.Key != 0)
            {
              Cars *player = new Cars(2);
              player->_down = keyEvent.Key;
              player->setControle();
              delete player;
              context.device->setEventReceiver(&receiver);
              keyEvent.Key = (irr::EKEY_CODE)0;
              context.bind2 = 0;
            }
        }
      else if (context.bind2 == 3)
        {
          device->setEventReceiver(&keyEvent);
          if (keyEvent.Key != 0)
            {
              Cars *player = new Cars(2);
              player->_right = keyEvent.Key;
              player->setControle();
              delete player;
              context.device->setEventReceiver(&receiver);
              keyEvent.Key = (irr::EKEY_CODE)0;
              context.bind2 = 0;
            }
        }
      else if (context.bind2 == 4)
        {
          device->setEventReceiver(&keyEvent);
          if (keyEvent.Key != 0)
            {
              Cars *player = new Cars(2);
              player->_left = keyEvent.Key;
              player->setControle();
              delete player;
              context.device->setEventReceiver(&receiver);
              keyEvent.Key = (irr::EKEY_CODE)0;
              context.bind2 = 0;
            }
        }
      else if (context.bind2 == 5)
        {
          device->setEventReceiver(&keyEvent);
          if (keyEvent.Key != 0)
            {
              Cars *player = new Cars(2);
              player->_turbo = keyEvent.Key;
              player->setControle();
              delete player;
              context.device->setEventReceiver(&receiver);
              keyEvent.Key = (irr::EKEY_CODE)0;
              context.bind2 = 0;
            }
        }
      else if (context.bind2 == 6)
        {
          device->setEventReceiver(&keyEvent);
          if (keyEvent.Key != 0)
            {
              Cars *player = new Cars(2);
              player->_rocketkey = keyEvent.Key;
              player->setControle();
              delete player;
              context.device->setEventReceiver(&receiver);
              keyEvent.Key = (irr::EKEY_CODE)0;
              context.bind2 = 0;
            }
        }
      if (context.bind1 != 0 || context.bind2 != 0)
	{
	  str += L"Press a key";
	  font->draw(str,irr::core::rect<irr::s32>(core.getWinX()/3+50, core.getWinY()/2-100, 0,0),irr::video::SColor(255,255,255,255));
	}
      driver->endScene();
    }
  return (0);
}

int				Menu::menu(Core core, irr::IrrlichtDevice *device,
					   irr::video::IVideoDriver *driver,
					   irr::scene::ISceneManager *sceneManager)
{
  irr::gui::IGUIEnvironment* env = device->getGUIEnvironment();
  irr::gui::IGUIButton  *button[5];
  irrklang::ISoundEngine*		MenuS = irrklang::createIrrKlangDevice();
  device->getGUIEnvironment()->addImage(driver->getTexture("media/SplashScreen/menu2.jpg"), irr::core::position2d<irr::s32>(0,0));

  button[0] = env->addButton(irr::core::rect<irr::s32>(900,640,900 + 200,640 + 50),
			     0,GUI_ID_PLAY_BUTTON, L"", L"");
  button[1] = env->addButton(irr::core::rect<irr::s32>(550,780,550 + 200,780 + 50),
			     0, GUI_ID_SCORE_BUTTON, L"", L"");
  button[2] = env->addButton(irr::core::rect<irr::s32>(1210,800,1210 + 200,800 + 50),
			     0, GUI_ID_SETTING_BUTTON, L"", L"");
  button[3] = env->addButton(irr::core::rect<irr::s32>(10,900,10 + 200,900 + 50),
			     0, GUI_ID_QUIT_BUTTON, L"", L"");
  button[0]->setImage(driver->getTexture("media/Bouton/BoutonPlay.png"));
  button[1]->setImage(driver->getTexture("media/Bouton/BoutonScores.png"));
  button[2]->setImage(driver->getTexture("media/Bouton/BoutonSettings.png"));
  button[3]->setImage(driver->getTexture("media/Bouton/BoutonQuit.png"));

  SAppContext context;
  context.device = device;
  context.button = 0;
  context.bind1 = 0;
  KeyEventMenu receiver(context);
  device->setEventReceiver(&receiver);
  int	i;
  MenuS->play2D("media/sounds/Accueil.wav", true);
  while (context.device->run())
    {
      driver->beginScene(true, true, irr::video::SColor(0,200,200,200));
      env->drawAll();
      driver->endScene();
      if (context.button == 1)
	{
	  MenuS->drop();
	  i = menuPlay(core, device, driver, sceneManager, context);
	  button[0]->remove();
	  button[1]->remove();
	  button[2]->remove();
	  button[3]->remove();
	  if (i == 1 || i == 2)
	    return (2);
	}
      else if (context.button == 2)
	{
	  MenuS->drop();
	  if (menuScore(core, device, driver, sceneManager, context) == 1)
	    return (2);
	}
      else if (context.button == 3)
	{
	  MenuS->drop();
	  if (menuSetting(core, device, driver, sceneManager, context) == 1)
	    return (2);
	}
      else if (context.button == 4)
	{
	  MenuS->drop();
	  return (0);
	}
    }
  if (!device->run())
    return (-1);
  return (0);
}
