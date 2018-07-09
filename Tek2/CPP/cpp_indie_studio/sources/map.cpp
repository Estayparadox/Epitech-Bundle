//
// map.cpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
// 
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
// 
// Started on  Thu May 19 21:31:47 2016 Dylan Debernard
// Last update Mon Jun  6 23:22:45 2016 Dylan Debernard
//

#include			<hyper_sprint.h>

irr::scene::ISceneNode	*initSkyBox(irr::video::IVideoDriver *driver,
                                   irr::scene::ISceneManager *sceneManager,
				   irr::scene::ISceneNode* skybox)
{
  skybox = sceneManager->addSkyBoxSceneNode(
	driver->getTexture("media/skybox3/Top.png"),
	driver->getTexture("media/skybox3/Down.png"),
	driver->getTexture("media/skybox3/Left.png"),
        driver->getTexture("media/skybox3/Right.png"),
	driver->getTexture("media/skybox3/Front.png"),
	driver->getTexture("media/skybox3/Back.png"));
  driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);
  skybox->setVisible(true);
  return (skybox);
}

irr::scene::ISceneNode	*initMap(irr::scene::ISceneManager *sceneManager, Core core,
				 std::vector<Cars> player, std::vector<Cars> bot)
{
  std::string mapPath;

  mapPath = core.getMapPath();
  irr::scene::IMesh *mapMesh = sceneManager->getMesh(mapPath.c_str());
  irr::scene::ISceneNode *mapNode = sceneManager->addMeshSceneNode(mapMesh);
  irr::scene::ITriangleSelector* selector = 0; 
  if (mapNode && core.getMapPath() == "media/map7/mapOvalGood6.obj")
    {
      mapNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      mapNode->setPosition(irr::core::vector3df(200.f, -70.f, 0.f));
      mapNode->setScale(irr::core::vector3df(10.f, 10.f, 10.f));
      mapNode->setRotation(irr::core::vector3df(0, 0, 0));
      mapNode->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);
    }
  else if (mapNode && core.getMapPath() == "media/mapSW/MapSnowV4.obj")
    {
      mapNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      mapNode->setPosition(irr::core::vector3df(50.f, -170.f, -100.f));
      mapNode->setScale(irr::core::vector3df(10.f, 10.f, 10.f));
      mapNode->setRotation(irr::core::vector3df(0, 0, 0));
      mapNode->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);
    }
  selector = sceneManager->createOctreeTriangleSelector(mapMesh, mapNode);
  mapNode->setTriangleSelector(selector);
  irr::scene::ISceneNodeAnimatorCollisionResponse* map = 0;
  int i = 0;
  for (std::vector<Cars>::iterator it = player.begin(); it != player.end(); ++it)
    {
      map = sceneManager->createCollisionResponseAnimator(selector, player[i]._node, irr::core::vector3df(0.1, 0.1, 0.1), irr::core::vector3df(0, -10, 0), irr::core::vector3df(0, 0, 0));
      selector->drop();
      player[i]._node->addAnimator(map);
      i++;
    }
  i = 0;
  return (mapNode);
}

irr::scene::ISceneNode	*initMapDecors(irr::scene::ISceneManager *sceneManager)
{
  irr::scene::ISceneNode *map2;
  map2 = sceneManager->addMeshSceneNode(sceneManager->getMesh("media/mapSW/mapWTRoad2.obj"));
  if (map2)
    {
      map2->setPosition(irr::core::vector3df(50.f, -170.f, -100.f));
      map2->setRotation(irr::core::vector3df(0, 0, 0));
      map2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      map2->setScale(irr::core::vector3df(10.f,10.f,10.f));
    }
  return (map2);
}

irr::scene::ISceneNode	*nodePlane(irr::scene::ISceneManager *sceneManager,
				   std::string mapPath, irr::scene::ISceneNode *avion)
{
  if (mapPath == "media/mapSW/MapSnowV4.obj")
    {
      avion = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh("media/mapSW/Millennium_Falcon.obj"));
      avion->setScale(irr::core::vector3df(0.35f, 0.35f, 0.35f));
      avion->setRotation(irr::core::vector3df(-90 ,90 ,90));
    }
  else if (mapPath == "media/map7/mapOvalGood6.obj")
    {
      avion = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh("media/map7/F-35_Lightning_II.obj"));
      avion->setScale(irr::core::vector3df(4.f, 4.f, 4.f));
      avion->setRotation(irr::core::vector3df(-90 ,90, 0));
    }
  if (avion)
    {
      irr::scene::ISceneNodeAnimator *avionA;
      avionA = sceneManager->createFlyStraightAnimator(irr::core::vector3df(10000, 300, 100), irr::core::vector3df(-5000, 300, 100), 30000, true);
      if (avionA)
        {
          avion->addAnimator(avionA);
          avionA->drop();
        }
      avion->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }
  return (avion);
}

irr::scene::ISceneNode	*startFlag(Core core, irr::video::IVideoDriver *driver,
				   irr::scene::ISceneNode *start)
{
  if (start && core.getMapPath() == "media/map7/mapOvalGood6.obj")
    {
      start->setPosition(irr::core::vector3df(20, -56, -25));
      start->setRotation(irr::core::vector3df(90, 93, 0));
      start->setMaterialTexture(0, driver->getTexture("media/mapTexture/damier.png"));
      start->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      start->setScale(irr::core::vector3df(10.f,2.f,0.f));
    }
  else
    {
      start->setPosition(irr::core::vector3df(-50, -94.3f, 9));
      start->setRotation(irr::core::vector3df(90, 90, 0));
      start->setMaterialTexture(0, driver->getTexture("media/mapTexture/damier.png"));
      start->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      start->setScale(irr::core::vector3df(11.f,2.f,0.f));
    }
  return (start);
}

irr::scene::ISceneNode  *cpFlag(Core core, irr::video::IVideoDriver *driver,
                                   irr::scene::ISceneNode *cp)
{
  if (cp && core.getMapPath() == "media/map7/mapOvalGood6.obj")
    {
      cp->setPosition(irr::core::vector3df(50, -56, 232));
      cp->setRotation(irr::core::vector3df(90, 93, 0));
      cp->setMaterialTexture(0, driver->getTexture("media/mapTexture/transparent.png"));
      cp->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL);
      cp->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      cp->setScale(irr::core::vector3df(10.f,2.f,0.f));
    }
  else
    {
      cp->setPosition(irr::core::vector3df(307, -94.3f, 50));
      cp->setRotation(irr::core::vector3df(90, 0, 0));
      cp->setMaterialTexture(0, driver->getTexture("media/mapTexture/transparent.png"));
      cp->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL);
      cp->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      cp->setScale(irr::core::vector3df(11.f,2.f,0.f));
    }
  return (cp);
}
