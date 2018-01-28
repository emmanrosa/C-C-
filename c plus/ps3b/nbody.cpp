#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "nbody.hpp"

Planet::Planet(double x,double y,double xSpeed, double ySpeed,double mass, std::string image) {

}
void Planet:: draw(sf::RenderTarget& target, sf::RenderStates 
states)
const {
target.draw(sprite,states);

}

void Planet:: setPosition(double x, double y) {
  X = x;
  Y = y;
}

void Planet:: setMass(double mass) {
  Mass = mass;
}
double Planet:: get_x() const {
  return X;
}

double Planet:: get_y() const {
  return Y;
}


double Planet::getMass() {
  return Mass;
}

void Planet::setnum_planets(int num)
{
  num_planets = num;
}

int Planet::getnum_planets()
{
  return num_planets;
}
std::istream& operator>> (std::istream& in, Planet& planet) {
  in >> planet.X
     >> planet.Y
     >> planet.X_Speed
     >> planet.Y_Speed
     >> planet.Mass
     >> planet.Image;
planet.Planet_Image.loadFromFile(planet.Image);
planet.texture.loadFromImage(planet.Planet_Image);
planet.sprite.setTexture(planet.texture);

return in;
}

void Planet:: updatePosition(double scale,int window_x, int window_y) {

sf::Vector2u size = Planet_Image.getSize();
int X_Position = window_x-size.x/2+X/scale*window_x;
int Y_Position = window_y-size.y/2+Y/scale*window_y;

sprite.setPosition(X_Position,Y_Position);
}

//step method 
void Planet:: step(double time,Planet **Planets,int planet)
{
  //the gravitational constant G (6.67 × 10-11 N m2 / kg2)
  double r;
  double F;
  double FX;
  double FY;
  
  for (int i=0;i<getnum_planets();i++)
    {
      if (planet!=i)
	{

/*all the following equations were given by princeton
  http://www.cs.princeton.edu/courses/archive/fall13/cos126/assignments/nbody.html*/
	  
	  //find the pairwise force
	  r = sqrt(pow(X-(*Planets[i]).X,2)+pow(Y-(*Planets[i]).Y,2));
	  F = (6.67e-11)*(*Planets[i]).Mass*Mass/pow(r,2);

	  //find the net force
	  FX = F*(X-(*Planets[i]).X)/r;
	  FY = F*(Y-(*Planets[i]).Y)/r;

	  //find the acceleration
	  X_Speed = X_Speed+time*FX/Mass;
	  Y_Speed = Y_Speed+time*FY/Mass;
  
	}

    }

  if (planet<getnum_planets()-1)
   
    (*Planets[planet+1]).step(time, Planets, planet+1);
  X -=(time*X_Speed);
  Y -=(time*Y_Speed);
  
}
