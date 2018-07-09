//
// main.cpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Wed Apr 27 17:05:38 2016 Dylan Debernard
// Last update Thu Oct 26 09:28:30 2017 pereniguez joseph
//


#include		<hyper_sprint.h>
#include		<irrKlang.h>
#include		<../chronoscore/Chronometer.hh>

Score			*minuteur(Core core, irr::gui::IGUIFont* font, const irr::u32 DeltaTime, Score *chrono)
{
  int minutes;
  int seconde;
  int miliseconde;
  int copy;
  copy = (int)DeltaTime;
  miliseconde = copy % 100;
  copy = copy / 1000;
  seconde = copy % 60;
  copy = copy / 60;
  minutes = copy % 60;
  copy = copy / 60;
  irr::core::stringw s;
  if (minutes < 10)
    {
      s += L"0";
      s += minutes;
      s += ":";
    }
  if (minutes >= 10)
    {
      s += minutes;
      s += ":";
    }
  if (seconde < 10)
    {
      s += L"0";
      s += seconde;
      s += ":";
    }
  if (seconde >= 10)
    {
      s += seconde;
      s += ":";
    }
  if (miliseconde < 10)
    {
      s += L"0";
      s += miliseconde;
      s += ":";
    }
  if (miliseconde >= 10)
    {
      s += miliseconde;
      s += "\n";
    }
  font->draw(s,irr::core::rect<irr::s32>(core.getWinX()/2 - 50, 0, 0, 0), irr::video::SColor(255,255,0,0));
  chrono->recup(minutes, seconde, miliseconde);
  return (chrono);
}

void			compteur(Core core, irr::IrrlichtDevice *device,
				 irr::video::IVideoDriver *driver,
				 irr::scene::ISceneManager *sceneManager,
				 Camera *camera, std::vector<Cars> player)
{
  irr::ITimer *timer = device->getTimer();
  irr::u32 beginTime = timer->getRealTime();
  irr::gui::IGUIFont* font = device->getGUIEnvironment()->getFont("media/font/myfont.xml");
  while (device->run())
    {
      irr::core::stringw count;
      irr::u32 current = timer->getRealTime();
      irr::u32 deltaTime = current - beginTime;
      if(deltaTime < 1000)
        count = L"3";
      else if(deltaTime < 2000)
        count = L"2";
      else if(deltaTime < 3000)
        count = L"1";
      else if(deltaTime < 3500)
        count = L"GO!";
      else
        break;
      driver->beginScene (true, true, irr::video::SColor(255,180,180,180));
      if (core.getCam() == 1)
	camera->moveCamera(sceneManager, driver, player, core);
      else
	sceneManager->drawAll();
      driver->setViewPort(irr::core::rect<irr::s32>(0, 0, core.getWinX(),core.getWinY()));
      font->draw(count,irr::core::rect<irr::s32>(core.getWinX()/2 - 10, core.getWinY()/2 - 100, 0, 0), irr::video::SColor(255,255,0,0));
      driver->endScene();
    }
}

bool			collision(irr::scene::ISceneNode* one, const irr::scene::ISceneNode* two)
{
  irr::core::aabbox3d<irr::f32> b1;
  irr::core::aabbox3d<irr::f32> b2;

  b1 = one->getBoundingBox();
  b2 = two->getBoundingBox();

  one->getRelativeTransformation().transformBoxEx(b1);
  two->getRelativeTransformation().transformBoxEx(b2);
  return (b1.intersectsWithBox(b2));
}

Core                    readSettingFile(Core core, std::string filename)
{
  std::ifstream         file(filename.c_str(), std::ios::in);
  std::string           line;
  int                   i(0);

  while (getline(file, line, '\n'))
    {
      switch (i)
	{
	case 0:
	  core.setWinX(atoi(line.c_str()));
	case 1:
	  core.setWinY(atoi(line.c_str()));
	case 2:
	  {
	    if (line == "true")
	      core.setFullscreen(true);
	    else
	      core.setFullscreen(false);
	  }
	}
      i++;
    }
  return (core);
}


void			saveGame(std::vector<Cars> player, Core core)
{
  std::ofstream         file("save.txt", std::ios::out);

  file << "player 1\n";
  file << player[0]._px << std::endl;
  file << player[0]._py << std::endl;
  file << player[0]._pz << std::endl;
  file << player[0]._rx << std::endl;
  file << player[0]._ry << std::endl;
  file << player[0]._rz << std::endl;
  file << player[0]._speed << std::endl;
  file << player[0]._maxSpeed << std::endl;
}

int			HyperSprint(Core core, irr::IrrlichtDevice *device,
				    irr::video::IVideoDriver *driver,
				    irr::scene::ISceneManager *sceneManager)
{
  KeyEvent	keyEvent;

  device->setEventReceiver(&keyEvent);
  irr::gui::IGUIEnvironment* env = device->getGUIEnvironment();
  loadingScreen(device, driver, env);

  std::vector<Cars> player;
  for (int numPlayer = 1; numPlayer <= core.getNbPlayer(); ++numPlayer)
    player.push_back(Cars(core, sceneManager, driver, numPlayer));

  std::vector<Cars> bot;
  for (int numPlayer = 1; numPlayer <= core.getNbBot(); ++numPlayer)
    bot.push_back(Cars(core, sceneManager, numPlayer));

  Camera *camera = new Camera(sceneManager, driver, player, core);
  irr::u32 then = device->getTimer()->getTime();

  irrklang::ISoundEngine*		MapS = irrklang::createIrrKlangDevice();
  irr::scene::ISceneNode *skybox = 0;
  irr::scene::ISceneNode *map = 0;
  irr::scene::ISceneNode *map2 = 0;
  irr::scene::ISceneNode *avion = 0;
  std::vector<PowerUp>  powerUp;
  skybox = initSkyBox(driver, sceneManager, skybox);

  map = initMap(sceneManager, core, player, bot);
  if (core.getMapPath() == "media/mapSW/MapSnowV4.obj")
    {
      MapS->play2D("media/sounds/Star_Wars.wav", true);
      map2 = initMapDecors(sceneManager);
      if (core.getPowerUp() == true)
	{
	  powerUp.push_back(PowerUp(sceneManager, driver, irr::core::vector3df(337, -89.3f, 50)));
	  powerUp.push_back(PowerUp(sceneManager, driver, irr::core::vector3df(307, -89.3f, 50)));
	  powerUp.push_back(PowerUp(sceneManager, driver, irr::core::vector3df(277, -89.3f, 50)));
	}
    }
  else
    {
      MapS->play2D("media/sounds/Dinos.wav", true);
      if (core.getPowerUp() == true)
	{
	  powerUp.push_back(PowerUp(sceneManager, driver, irr::core::vector3df(0, -50, 210)));
	  powerUp.push_back(PowerUp(sceneManager, driver, irr::core::vector3df(0, -50, 240)));
	  powerUp.push_back(PowerUp(sceneManager, driver, irr::core::vector3df(0, -50, 270)));
	}
    }
  avion = nodePlane(sceneManager, core.getMapPath(), avion);

  irr::scene::ISceneNode *start = sceneManager->addCubeSceneNode();
  irr::scene::ISceneNode *cp = sceneManager->addCubeSceneNode();
  std::vector<irr::scene::ISceneNode*> flag;
  start = startFlag(core, driver, start);
  cp = cpFlag(core, driver, cp);

  flag.push_back(start);
  flag.push_back(cp);
  compteur(core, device, driver, sceneManager, camera, player);

  irr::gui::IGUIFont* font = device->getGUIEnvironment()->getFont("media/font/fonthaettenschweiler.bmp");

  int		p;
  int		end = 0;
  int		count = 0;
  irrklang::ISoundEngine*	winJingle = irrklang::createIrrKlangDevice();
  Score		*chrono = new Score();

  std::string	filename = getBot(core);
  std::ifstream	file(filename.c_str(), std::ios::in);
  int		a(0);
  int		nbLine(0);

  nbLine = initBot(filename);

  std::string	filenameScore = getScoreFilename(core);
  std::string	filenameScoreSort = getScoreSortFilename(core);
  irr::ITimer	*timer = device->getTimer();
  irr::u32	beginTime = timer->getRealTime();
  while (device->run())
    {
      int i = 0;
      int j = 0;
      const irr::u32 now = device->getTimer()->getTime();
      const irr::f32 frameDeltaTime = (irr::f32)(now - then) / (1000 * 1);
      then = now;
      const irr::u32 current = timer->getRealTime();
      const irr::u32 DeltaTime = (current - beginTime);
      driver->beginScene (true, true, irr::video::SColor(255,180,180,180));
      if (core.getNbPlayer() == 2 && core.getCollision() == true &&
	  collision(player[0]._node, player[1]._node) == true)
	{
	  player[0]._speed = -40;
	  player[1]._speed = -40;
        }
      for (std::vector<Cars>::iterator it = player.begin(); it != player.end(); ++it)
	{
	  p = player[i++].controle_car(sceneManager, keyEvent, frameDeltaTime, player, core, powerUp, flag);
	  if ((p == 1 || p == 2) && end == 0)
	    end = p;
	  else if (p == 3)
	    player[0]._speed = 0;
	  else if (p == 4 && core.getNbPlayer() == 2)
	    player[1]._speed = 0;
	}
      for (std::vector<Cars>::iterator it = bot.begin(); it != bot.end(); ++it)
	{
	  botCommand(filename, a, bot, j++);
	  if (a >= nbLine && end == 0 && core._record == false)
	    end = bot[0]._player + 10;
	}
      a += 6;
      if (core.getCam() == 1)
	camera->moveCamera(sceneManager, driver, player, core);
      else
	sceneManager->drawAll();
      if (keyEvent.IsKeyDown(irr::KEY_KEY_C) && core.getCam() == 1 && core.getButton() == 30)
	{
	  core.setCam(2);
	  camera->changeCameraToSkyview(sceneManager, core, player, driver);
	  core.setButton(0);
	}
      else if (keyEvent.IsKeyDown(irr::KEY_KEY_C) && core.getCam() == 2 && core.getButton() == 30)
	{
	  core.setCam(1);
	  camera->changeCameraTo3rd(sceneManager, core, player);
	  core.setButton(0);
	}
      if (keyEvent.IsKeyDown(irr::KEY_ESCAPE))
	break;
      if (core.getButton() < 30)
	core.setButton(core.getButton() + 1);
      if (core.getFPS() == true)
	printFPS(core, driver, font);
      if (end == 0)
	{
	  chrono = minuteur(core, font, DeltaTime, chrono);
	  printInfo(core, driver, font, 0, player);
	  if (core.getNbPlayer() == 2)
	    printInfo(core, driver, font, 1, player);
	  driver->endScene();
	}
      else
	{
	  if (end < 9)
	    {
	      std::map<std::string, int> scoreTab;
	      if (count == 0)
		{
		  winJingle->play2D("media/sounds/Win.wav");
		  std::stringstream ss;
		  std::string	mode;
		  ss << core.getLaps();
		  mode = ss.str();
		  chrono->scoreWritter(core.getName(), filenameScoreSort);
		  scoreTab = chrono->PushTab(filenameScoreSort);
		  chrono->sortTab(scoreTab, mode, core, filenameScore);
		}
	    }
	  printWinner(core, device, driver, end);
	  count++;
	  if (count == 50)
	    break;
	}
    }
  core.setCam(2);
  camera->changeCameraToSkyview(sceneManager, core, player, driver);
  delete camera;
  file.close();
  player[0]._node->remove();
  player[0]._rocketMesh->remove();
  player[0]._shieldMesh->remove();
  if (core.getNbPlayer() == 2)
    {
      player[1]._node->remove();
      player[1]._rocketMesh->remove();
      player[1]._shieldMesh->remove();
    }
  if (core.getNbBot() == 1)
    {
      bot[0]._node->remove();
      bot.clear();
    }
  skybox->remove();
  avion->remove();
  start->remove();
  map->remove();
  MapS->removeAllSoundSources();
  if (core.getMapPath() == "media/mapSW/MapSnowV4.obj")
    map2->remove();
  player.clear();
  if (core.getPowerUp() == true)
    {
      powerUp[0].setBonus();
      powerUp[1].setBonus();
      powerUp[2].setBonus();
      powerUp.clear();
    }
  device->getCursorControl()->setVisible(true);
  return (0);
}

int	main()
{
  Core          core;

  core = readSettingFile(core, "config/setting.txt");
  irr::IrrlichtDevice   *device;
  device = irr::createDevice(irr::video::EDT_OPENGL,
			     irr::core::dimension2d<irr::u32>(core.getWinX(), core.getWinY())
			     ,32, core.getFullscreen(), true, true, 0);

  device->getCursorControl()->setVisible(true);
  device->setWindowCaption(L"Hyper Sprint");
  irr::video::IVideoDriver *driver = device->getVideoDriver();
  irr::scene::ISceneManager *sceneManager = device->getSceneManager();
  splashScreen(device, driver, sceneManager);
  Menu *menu = new Menu(core, device, driver, sceneManager);
  int	i = 10;
  while (i != -1)
    {
      i = menu->menu(core, device, driver, sceneManager);
      if (i == 0 || i == 1)
	break;
    }
  delete menu;
  return (0);
}
