#ifndef N_BODY_HPP_
#define N_BODY_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Planet : public sf::Drawable
{

private:
  double X;
  double Y;
  double X_Speed;
  double Y_Speed;
  double Mass;
  double num_planets;
  std::string Image;
  sf::Texture texture;
  sf::Image Planet_Image;
  sf::Sprite sprite;
public:
  Planet(double x_pos, double y_pos, double x_vel, double y_vel,double mass, std::string image);
  //set position
  void setPosition(double x_pos, double y_pos);
  //set mass
  void setMass(double mass);
  //set the number of planets
  void setnum_planets(int num);
  //get x
  double get_x() const;
  //get y
  double get_y() const;
  //get mass
  double getMass();
  //get numbers of planets
  int getnum_planets();
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void updatePosition(double scale,int window_x, int window_y);
  friend std::istream& operator>> (std::istream& in, Planet& planet);
  void step(double time,Planet **Planets,int planet);
};

#endif
