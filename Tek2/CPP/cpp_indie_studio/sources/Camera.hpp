//
// Camera.hpp for  in /home/debern_d/2_rendu/cpp_indie_studio/sources
//
// Made by Dylan Debernard
// Login   <debern_d@epitech.net>
//
// Started on  Wed May 11 17:26:40 2016 Dylan Debernard
// Last update Wed Jun  1 22:44:48 2016 Dylan Debernard
//

#ifndef			_CAMERA_HPP_
# define		_CAMERA_HPP_

# include		"Cars.hpp"
# include		"Core.hpp"

class			Camera : public Cars, public Core
{
public:
  Camera(irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver,
	 std::vector<Cars> player, Core core);
  ~Camera();
  void			moveCamera(irr::scene::ISceneManager *sceneManager,
				   irr::video::IVideoDriver *driver,
				   std::vector<Cars> player, Core core);
  void			changeCameraToSkyview(irr::scene::ISceneManager *sceneManager,
					      Core core, std::vector<Cars> player,
					      irr::video::IVideoDriver *driver);
  void			changeCameraTo3rd(irr::scene::ISceneManager *sceneManager,
					  Core core, std::vector<Cars> player);
public:
  irr::scene::ICameraSceneNode *_camera[4];
};

#endif			/* !_CAMERA_HPP_ */
