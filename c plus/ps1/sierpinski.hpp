// Copyright 2016 Emmanuel Rosario
#ifndef _HOME_EMMANUEL_DESKTOP_PS1_SIERPINSKI_HPP_
#define _HOME_EMMANUEL_DESKTOP_PS1_SIERPINSKI_HPP_
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector> //NOLINT

class Sierpinski : public sf::Drawable {
 public:
    Sierpinski(int depth, int width);
    sf::Vector2f mid(sf::Vector2f x, sf::Vector2f y);
    void makeTriangles(int depth, sf::Vector2f p1, sf::Vector2f p2,
        sf::Vector2f p3);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const; //NOLINT
 private:
    int depth;
    int width;
    std::vector<sf::ConvexShape> triangles;
};
#endif  // _HOME_EMMANUEL_DESKTOP_PS1_SIERPINSKI_HPP_
