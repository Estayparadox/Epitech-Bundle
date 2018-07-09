//
// print.cpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
// 
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
// 
// Started on  Tue May 31 18:54:20 2016 Dylan Debernard
// Last update Wed Jun  1 15:18:48 2016 Dylan Debernard
//

#include		<hyper_sprint.h>

void                    printWinner(Core core, irr::IrrlichtDevice *device,
				    irr::video::IVideoDriver *driver, int end)
{
  irr::gui::IGUIFont* font = device->getGUIEnvironment()->getFont("media/font/myfont.xml");
  irr::core::stringw win;
  if (end <= 2)
    {
      win += L"Player ";
      win += end;
    }
  else
    {
      win += L"Bot ";
      win += end - 10;
    }
  win += L" win";
  font->draw(win,irr::core::rect<irr::s32>(core.getWinX()/3+50, core.getWinY()/2-100, 0,0),
             irr::video::SColor(255,255,255,255));
  driver->endScene();
}

void                    printInfo(Core core, irr::video::IVideoDriver *driver,
                                  irr::gui::IGUIFont* font, int i,
                                  std::vector<Cars> player)
{
  irr::core::stringw str;
  str += L"Laps : ";
  str += player[i]._laps;
  str += L"/";
  str += core.getLaps();
  str += L"\nTurbo : ";
  str += player[i]._powerup;
  str += L"\nRocket : ";
  str += player[i]._rocketPU;
  str += L"\nShield : ";
  str += player[i]._shield;
  str += L"\nSpeed : ";
  str += (int)player[i]._speed;
  if (i == 0)
    {
      driver->setViewPort(irr::core::rect<irr::s32>(0, 0, core.getWinX(),core.getWinY()));
      font->draw(str,irr::core::rect<irr::s32>(0, 0, 0, 0), irr::video::SColor(255,0,255,0));
    }
  else if (i == 1)
    {
      driver->setViewPort(irr::core::rect<irr::s32>(0, 0, core.getWinX(),core.getWinY()));
      font->draw(str,irr::core::rect<irr::s32>(core.getWinX() / 2, 0, 0, 0), irr::video::SColor(255,0,255,0));
    }
}

void                    printFPS(Core core, irr::video::IVideoDriver *driver,
                                 irr::gui::IGUIFont* font)
{
  int fps = driver->getFPS();
  irr::core::stringw strFPS;
  strFPS += fps;
  driver->setViewPort(irr::core::rect<irr::s32>(0, 0, core.getWinX(),core.getWinY()));
  font->draw(strFPS,irr::core::rect<irr::s32>(core.getWinX() - 12, 0, 0, 0),
             irr::video::SColor(255,0,255,0));
}
