#include "edhec.h"

void	displayImage(std::string image)
{
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
  sf::Texture texture;
  sf::Sprite sprite;
  
  if (!texture.loadFromFile(image, sf::IntRect(0, 0, 1000, 1000)))
    printf ("File not found");
      
      sprite.setTexture(texture);
      
      while (window.isOpen())
	{
	  sf::Event event;
	  while (window.pollEvent(event))
	    {
	      if (event.type == sf::Event::Closed)
                window.close();
	    }
	  window.draw(sprite);
	  window.display();
	}
}
