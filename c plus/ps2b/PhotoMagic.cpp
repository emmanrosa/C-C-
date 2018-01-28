#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "LFSR.hpp"

sf::Image transform(sf::Image picture, LFSR lfsr) {
  sf::Vector2u size = picture.getSize();
  sf::Color p;
  //x value
  for (unsigned x = 0; x < size.x; x++)
    {
      //y value
      for (unsigned y = 0; y < size.y; y++)
	{
	  //get get pixel with x and y values
	  //assing the get pixel() to p
	  p = picture.getPixel(x, y);

	  //color or component with a generated 8-bit integer
	  p.r = p.r ^ lfsr.generate(8);
	  p.g = p.g ^ lfsr.generate(8);
	  p.b = p.b ^ lfsr.generate(8);

	  //set x, y, and p to setpixel 
	  picture.setPixel(x, y, p);
	}
    }
  return picture;
}

int main(int argc, char *argv[]) {

  //loading the image
  sf::Image image;
  if (!image.loadFromFile("cat.jpg"))
    return -1;
  sf::Image imageOut;
  if (!imageOut.loadFromFile("cat.jpg"))
    return -1;
  LFSR lfsr("01101000010100010000", 16);
  imageOut = transform(imageOut, lfsr);
  sf::Vector2u size = image.getSize();
  sf::RenderWindow window(sf::VideoMode(size.x * 2, size.y), "Encrypted Image");

  //first window with the decrypted image
  sf::Texture texture;
  texture.loadFromImage(image);
  sf::Sprite sprite;
  sprite.setTexture(texture);

  //second window with the encrypted image
  sf::Texture textureOut;
  textureOut.loadFromImage(imageOut);
  sf::Sprite spriteOut;
  spriteOut.setTexture(textureOut);
  spriteOut.setPosition(size.x, 0);

  //windows event
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    window.draw(sprite);
    window.draw(spriteOut);
    window.display();
  }
  
  //save the out image
  if (!imageOut.saveToFile("encrypted-cat.bmp"))
    return -1;
  
  return 0;
}
