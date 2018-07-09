//
// Cars.hpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Mon May 02 18:26:28 2016 Dylan Debernard
// Last update Thu Oct 26 09:28:49 2017 pereniguez joseph
//

#include		"Cars.hpp"
#include		"PowerUp.hpp"
#include		<fstream>
#include		<irrKlang.h>

Cars::Cars()
{
}

Cars::Cars(int player)
{
  if (player == 1)
    {
      _player = 1;
      getControle();
    }
  else if (player == 2)
    {
      _player = 2;
      getControle();
    }
}

Cars::Cars(Core core, irr::scene::ISceneManager *sceneManager, int player)
{
  _speed = 0;

  _px = 50;
  _py = 0;
  _pz = -40;

  _rx = 0;
  _ry = 90;
  _rz = 0;
  _laps = 0;
  _cp = false;
  _node = sceneManager->addMeshSceneNode(sceneManager->getMesh("media/formule1/F1.obj"));
  if (player == 1)
    {
      _player = 1;
      _pz = -20;
    }
  else if (player == 2)
    {
      _player = 2;
      _px += 30;
    }
  else if (player == 3)
    {
      _player = 3;
      _pz = -20;
      _px += 30;
    }

  if (_node && core.getMapPath() == "media/map7/mapOvalGood6.obj")
    {
      _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      _node->setPosition(irr::core::vector3df(_px, -56.4269, _pz));
      _node->setRotation(irr::core::vector3df(_rx, _ry, _rz));
      _node->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
      _node->setScale(irr::core::vector3df(2.f, 2.f, 2.f));
    }
  else if (_node && core.getMapPath() == "media/mapSW/MapSnowV4.obj")
    {
      _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      _node->setPosition(irr::core::vector3df(_px - 40, -95.3182, _pz + 30));
      _node->setRotation(irr::core::vector3df(_rx, _ry, _rz));
      _node->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
      _node->setScale(irr::core::vector3df(2.f, 2.f, 2.f));
    }
}

Cars::Cars(Core core, irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, int player)
{
  _speed = 0;

  _px = 50;	// 0
  _py = 0;
  _pz = -40;	//-210;

  _rx = 0;	// 90
  _ry = 90;	// 180
  _rz = 0;

  _laps = 0;
  _cp = false;
  _powerup = 200;
  _rocket = false;
  _rocketMesh = sceneManager->addMeshSceneNode(sceneManager->getMesh("media/rocket/rocketlauncher_shell2.obj"));
  //_rocketMesh = sceneManager->addMeshSceneNode(sceneManager->getMesh("media/rocket/goat/Goat.obj"));
  _rocketPU = 0;
  _rocketMesh->setPosition(irr::core::vector3df(0, -200, 0));
  _shield = 0;
  _rocketMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  _rocketMesh->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
  _rocketMesh->setScale(irr::core::vector3df(1.f, 1.f, 1.f)); //7
  _shieldMesh = sceneManager->addSphereSceneNode();
  _shieldMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  _shieldMesh->setPosition(irr::core::vector3df(0, -200, 0));
  _shieldMesh->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL);
  _shieldMesh->setScale(irr::core::vector3df(1.5f, 1.5f, 2.7f));
  if (player == 1)
    {
      _player = 1;
      getControle();
      _shieldMesh->setMaterialTexture(0, driver->getTexture("media/ShieldB.png"));
      if (core.getMapPath() == "media/map7/mapOvalGood6.obj")
	_node = sceneManager->addMeshSceneNode(sceneManager->getMesh("media/ford/1967-shelby-ford-mustang.obj"));
      else
	_node = sceneManager->addMeshSceneNode(sceneManager->getMesh("media/starwars/LandSpeeder/Landspeeder.obj"));
      _maxSpeed = 150;
    }
  else if (player == 2)
    {
      _player = 2;
      getControle();
      _pz = 0; // -20 / 0
      _shieldMesh->setMaterialTexture(0, driver->getTexture("media/ShieldR.png"));
      if (core.getMapPath() == "media/map7/mapOvalGood6.obj")
	_node = sceneManager->addMeshSceneNode(sceneManager->getMesh("media/formule1/F1.obj"));
      else
	_node = sceneManager->addMeshSceneNode(sceneManager->getMesh("media/starwars/MillenniumFalcon/Millennium_Falcon2obj.obj"));
      _maxSpeed = 150;
    }
  if (_node && core.getMapPath() == "media/map7/mapOvalGood6.obj")
    {
      _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      _node->setPosition(irr::core::vector3df(_px, -56.4269, _pz));
      _node->setRotation(irr::core::vector3df(_rx, _ry, _rz));
      _node->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
      _node->setScale(irr::core::vector3df(2.f, 2.f, 2.f));
    }
  else if (_node && core.getMapPath() == "media/mapSW/MapSnowV4.obj")
    {
      _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      _node->setPosition(irr::core::vector3df(_px - 40, -95.3182, _pz + 30));
      _node->setRotation(irr::core::vector3df(_rx, _ry, _rz));
      _node->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
      _node->setScale(irr::core::vector3df(2.f, 2.f, 2.f));
    }
}

Cars::~Cars()
{
}

void			Cars::getControle()
{
  if (_player == 1)
    {
      std::ifstream	file("config/controle_player1.txt", std::ios::in);
      std::string	line;
      int		i(0);

      if (!file)
	{
	  _up = irr::KEY_KEY_Z;
	  _down = irr::KEY_KEY_S;
	  _right = irr::KEY_KEY_D;
	  _left = irr::KEY_KEY_Q;
	  _turbo = irr::KEY_LSHIFT;
	  _rocketkey = irr::KEY_LCONTROL;
	  _shieldkey = irr::KEY_KEY_W;
	}
      else
	while (getline(file, line, '\n'))
	  {
	    switch (i)
	      {
	      case 0:
		_up = (irr::EKEY_CODE)atoi(line.c_str());
	      case 1:
		_down = (irr::EKEY_CODE)atoi(line.c_str());
	      case 2:
		_right = (irr::EKEY_CODE)atoi(line.c_str());
	      case 3:
		_left = (irr::EKEY_CODE)atoi(line.c_str());
	      case 4:
		_turbo = (irr::EKEY_CODE)atoi(line.c_str());
	      case 5:
		_rocketkey = (irr::EKEY_CODE)atoi(line.c_str());
	      case 6:
		_shieldkey = (irr::EKEY_CODE)atoi(line.c_str());
	      }
	    i++;
	  }
    }
  else if (_player == 2)
    {
      std::ifstream     file("config/controle_player2.txt", std::ios::in);
      std::string       line;
      int               i(0);

      if (!file)
	{
	  _up = irr::KEY_UP;
	  _down = irr::KEY_DOWN;
	  _right = irr::KEY_RIGHT;
	  _left = irr::KEY_LEFT;
	  _turbo = irr::KEY_RCONTROL;
	  _rocketkey = irr::KEY_LSHIFT;
	  _shieldkey = irr::KEY_END;
	}
      else
	while (getline(file, line, '\n'))
	  {
	    switch (i)
	      {
	      case 0:
		_up = (irr::EKEY_CODE)atoi(line.c_str());
	      case 1:
		_down = (irr::EKEY_CODE)atoi(line.c_str());
	      case 2:
		_right = (irr::EKEY_CODE)atoi(line.c_str());
	      case 3:
		_left = (irr::EKEY_CODE)atoi(line.c_str());
	      case 4:
		_turbo = (irr::EKEY_CODE)atoi(line.c_str());
	      case 5:
		_rocketkey = (irr::EKEY_CODE)atoi(line.c_str());
	      case 6:
		_shieldkey = (irr::EKEY_CODE)atoi(line.c_str());
	      }
	    i++;
	  }
    }
}

void			Cars::setControle()
{
  if (_player == 1)
    {
      std::ofstream	file("config/controle_player1.txt", std::ios::out);
      file << _up << std::endl;
      file << _down << std::endl;
      file << _right << std::endl;
      file << _left << std::endl;
      file << _turbo << std::endl;
      file << _rocketkey << std::endl;
      file << _shieldkey << std::endl;
    }
  else if (_player == 2)
    {
      std::ofstream	file("config/controle_player2.txt", std::ios::out);
      file << _up << std::endl;
      file << _down << std::endl;
      file << _right << std::endl;
      file << _left << std::endl;
      file << _turbo << std::endl;
      file << _rocketkey << std::endl;
      file << _shieldkey << std::endl;
    }
}

int			Cars::controle_car(irr::scene::ISceneManager *sceneManager,
					   KeyEvent keyEvent, const irr::f32 frameDeltaTime,
					   std::vector<Cars> player, Core core,
					   std::vector<PowerUp> powerUp,
					   std::vector<irr::scene::ISceneNode*> flag)
{
  int			i(0);
  int			j(0);

  carsMouvement(keyEvent, frameDeltaTime);
  i = carsStartLine(core, flag);
  if (i == 1)
    return (1);
  else if (i == 2)
    return (2);
  if (core.getPowerUp() == true)
    {
      carsTurbo(keyEvent);
      carsGetTurbo(keyEvent, powerUp[0]);
      carsGetRocket(keyEvent, powerUp[1]);
      carsGetShield(keyEvent, powerUp[2]);
      j = carsPowerUpRocket(sceneManager, keyEvent, frameDeltaTime, player, core);
      if (j == 1)
	return (3);
      else if (j == 2)
	return (4);
      carsShield(keyEvent, sceneManager);
    }
  isUnderTheMap(keyEvent);
  if (_player == 2 && core._record == true)
    {
      std::ofstream     file("config/bot2_map2_5.txt", std::ios::out | std::ios::app);
      file << _node->getPosition().X << std::endl;
      file << _node->getPosition().Y << std::endl;
      file << _node->getPosition().Z << std::endl;
      file << _node->getRotation().X << std::endl;
      file << _node->getRotation().Y << std::endl;
      file << _node->getRotation().Z << std::endl;
    }
  return (0);
}

int			Cars::carsStartLine(Core core, std::vector<irr::scene::ISceneNode*> flag)
{
  if (collision(_node, flag[1]) == true)
    _cp = true;
  if (collision(_node, flag[0]) == true && _cp == true)
    {
      _cp = false;
      _laps++;
    }
  if (core.getLaps() == _laps)
    return (_player);
  return (0);
}

void			Cars::carsGetTurbo(KeyEvent keyEvent, PowerUp p)
{
  if (collision(_node, p._bonus) == true)
    _powerup = 200;
}

void			Cars::carsGetRocket(KeyEvent keyEvent, PowerUp p)
{
  if (collision(_node, p._bonus) == true)
    _rocketPU = 1;
}

void                    Cars::carsGetShield(KeyEvent keyEvent, PowerUp p)
{
  if (collision(_node, p._bonus) == true)
    _shield = 300;
}

void			Cars::carsShield(KeyEvent keyEvent, irr::scene::ISceneManager *sceneManager)
{
  keyEvent = keyEvent;
  if (_shield > 0)
    {
      _shieldMesh->setPosition(_node->getPosition());
      _shieldMesh->setRotation(_node->getRotation());
      _shield--;
    }
  else
    _shieldMesh->setPosition(irr::core::vector3df(0, -200, 0));
}

void			Cars::carsMouvement(KeyEvent keyEvent, const irr::f32 frameDeltaTime)
{
  irr::core::vector3df  dir;
  irr::core::matrix4    rotMatrix;

  dir = irr::core::vector3df(0.0f,0.0f,(_speed * -1) * frameDeltaTime);
  rotMatrix.setRotationDegrees(_node->getRotation());
  rotMatrix.transformVect(dir);
  _node->setPosition(_node->getPosition() + dir);
  if (keyEvent.IsKeyDown(_up))
    {
      if (_speed <= _maxSpeed / 2)
	_speed += 2;
      else if (_speed > 0 && _speed <= _maxSpeed)
        _speed += 0.5f;
    }
  else if (keyEvent.IsKeyDown(_down))
    {
      if (_speed >= 0)
        _speed -= 2.5f;
      else if (_speed < 0 && _speed >= -50)
        _speed -= 0.5f;
    }
  else
    {
      if (_speed > 0)
        _speed -= 0.5f;
      else if (_speed < 0)
        _speed += 0.5f;
    }
  if (keyEvent.IsKeyDown(_left))
    _ry -= _speed * frameDeltaTime;
  else if (keyEvent.IsKeyDown(_right))
    _ry += _speed * frameDeltaTime;
  if (_ry >= 360)
    _ry = 0;
  else if (_ry <= -1)
    _ry = 359;

  _px = _node->getPosition().X;
  _py = _node->getPosition().Y;
  _pz = _node->getPosition().Z;
  _node->setRotation(irr::core::vector3df(_rx, _ry, _rz));
}

void			Cars::carsTurbo(KeyEvent keyEvent)
{
  if (keyEvent.IsKeyDown(_turbo) && _powerup > 0)
    {
      _maxSpeed = 500;
      _powerup--;
    }
  else
    {
      _maxSpeed = 150;
      if (_speed > 150.5)
	_speed -= 5;
    }
}

int			Cars::carsPowerUpRocket(irr::scene::ISceneManager *sceneManager,
					  KeyEvent keyEvent, const irr::f32 frameDeltaTime,
					  std::vector<Cars> player, Core core)
{
  if (keyEvent.IsKeyDown(_rocketkey) && core.getButton() == 30 && _rocketPU == 1)
    {
      _rocket = true;
      _rocketMesh->setPosition(_node->getPosition());
      _rocketMesh->setRotation(_node->getRotation());
      _rocketPU = 0;
    }
  if (_rocket == true)
    {
      irr::core::vector3df  dir;
      irr::core::matrix4    rotMatrix;

      dir = irr::core::vector3df(0.0f,0.0f,(200 * -1) * frameDeltaTime);
      rotMatrix.setRotationDegrees(_rocketMesh->getRotation());
      rotMatrix.transformVect(dir);
      _rocketMesh->setPosition(_rocketMesh->getPosition() + dir);
    }
  if (core.getNbPlayer() == 2 && _player == 1)
    {
      if (collision(player[1]._node, _rocketMesh) == true && player[1]._shield == -1)
	return (2);
    }
  if (core.getNbPlayer() == 2 && _player == 2)
    {
      if (collision(player[0]._node, _rocketMesh) == true && player[0]._shield == -1)
	return (1);
    }
  return (0);
}

void			Cars::isUnderTheMap(KeyEvent keyEvent)
{
  if (_py <= -100 || keyEvent.IsKeyDown(irr::KEY_KEY_R))
    {
      _rx = 0;
      _ry = 90;
      _rz = 0;
      _px = -50;
      _py = 0;
      _pz = -40;
      _node->setRotation(irr::core::vector3df(_rx, _ry, _rz));
      _node->setPosition(irr::core::vector3df(_px, _py, _pz));
      _speed = 0;
      _powerup = 200;
    }
}

void		Cars::setSpeed(int speed)
{
  _speed = speed;
}
