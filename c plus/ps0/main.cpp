#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  //setting window up
  sf::RenderWindow window(sf::VideoMode(400, 400), "Hello World!");
  
  sf::Texture texture;

  // loading the image
  if (!texture.loadFromFile("sprite.png"))
    return EXIT_FAILURE;
  
  sf::Sprite sprite(texture);

  //set the starting position for the sprite
  sprite.setOrigin(-180,-180);

  cout <<"Press F7 for a screenshot,and to move the sprite use the arrow keys please."<<endl;
  
  while(window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
	{
	  // close window
	  if (event.type == sf::Event::Closed)
	    window.close();
	}

      // 
      window.setFramerateLimit(60);
      
      //sprite respond to the keystrokess pressed 

      // move when the right key is pressed
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
	  sprite.move(1,0);
	}
      
      // move when the left key is pressed
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	  sprite.move(-1,0);
	}
      
      // move when the down key is pressed
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
	  sprite.move(0,1);
	}
      
      // move when the up key is pressed
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
	  sprite.move(0,-1);
	}

      // to take a screenshot and saved it as well.
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::F7))
	{
	  sf::Image Screen = window.capture();
	  Screen.saveToFile("windowscreenshot.png");
	}

      
      //clear the window and changed background color to red
      window.clear(sf::Color(200, 0, 0));

      //draw the sprite
      window.draw(sprite);

      //update the window
      window.display();
    }
  
  return 0;
}
