// Copyright 2016 Emmanuel Rosario
#include <iostream>
#include <cmath>
#include "sierpinski.hpp"

Sierpinski::Sierpinski(int recursion_depth, int window_width) :
depth(recursion_depth), width(window_width) {
    double height = (sqrt(3)/2.0) * double(width); //NOLINT
    sf::Vector2f left = sf::Vector2f(0, height);
    sf::Vector2f right = sf::Vector2f(width, height);
    sf::Vector2f middle = sf::Vector2f((width/2), 0);

    makeTriangles(depth, left, right, middle);
}

sf::Vector2f Sierpinski::mid(sf::Vector2f p1, sf::Vector2f p2) {
    return sf::Vector2f((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

void Sierpinski::makeTriangles(int depth, sf::Vector2f p1,
    sf::Vector2f p2, sf::Vector2f p3) {

    if (depth == 0) {
        return;
    } else {
        sf::Vector2f mid_1 = mid(p1, p2);
        sf::Vector2f mid_2 = mid(p2, p3);
        sf::Vector2f mid_3 = mid(p1, p3);

        sf::ConvexShape tri;
        tri.setPointCount(3);
        tri.setFillColor(sf::Color::Black);
        tri.setPoint(0, mid_1);
        tri.setPoint(1, mid_2);
        tri.setPoint(2, mid_3);
        triangles.push_back(tri);

        makeTriangles((depth-1), p1, mid_1, mid_3);
        makeTriangles((depth-1), mid_1, p2, mid_2);
        makeTriangles((depth-1), mid_3, mid_2, p3);
    }
}

void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    int num = triangles.size();
    for (int i = 0; i < num; i++)
        target.draw(triangles[i]);
  } //  NOLINT