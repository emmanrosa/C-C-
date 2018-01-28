#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "nbody.hpp"

int main(int argc, char *argv[])
{
  Planet **Planets = new Planet*[4];
  int num_planets= 0;
  int num1 = 0;
  double x_y = 0;
  double num2 = 0;
  
  //time
   double time=10000;

  // Declare a new music
  sf::Music music;
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Image background;
  
  //reading from the file planets.txt
  std::cin >> num1 >> num2;
  num_planets = num1;
  //get the scale
  x_y = num2;
 
  for (int i = 0; i<num_planets; i++) {
    Planets[i]= new Planet(0.0,0.0,0.0,0.0,0.0,"o");
    std::cin >> *Planets[i];
    (*Planets[i]).setnum_planets(num_planets);
  }
  //windows set up, planets' images and background
  //loading the backgroud
  if (!background.loadFromFile("galaxy.jpg"))
    return -1;
  //set the windows size with the background image
  sf::Vector2u size = background.getSize();
  sf::RenderWindow window(sf::VideoMode(size.x, size.y), "Solar System");
  
  texture.loadFromImage(background);
  sprite.setTexture(texture);

  //music set up
  if (!music.openFromFile("2001.ogg"))
    {
      std::cout<<"can't find 2001.ogg"<< std::endl;
      return -1;
    }
  
  music.setPosition(0, 1, 10); // change its 3D position
  music.setPitch(2);           // increase the pitch
  music.setVolume(80);         // reduce the volume
  music.setLoop(true);         // make it loop
  music.play();                // play

  //window set up
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
	window.close();
    }
  
    window.setFramerateLimit(100); // Limit to 100 frames per second
  
	window.clear();
	window.draw(sprite);

	//planets animation
	(*Planets[0]).step(time,Planets,0);
	
	//drawing the planets
	for (int i=0; i<num_planets; i++)
	  {
	    (*Planets[i]).updatePosition(x_y, size.x/2, size.y/2);
	    window.draw(*Planets[i]);
	  }

    window.display();
    
  }
  return 0;
  
}
