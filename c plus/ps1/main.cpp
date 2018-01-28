// Copyright 2016 Emmanuel Rosario
#include <sstream>
#include <string>
#include <stdexcept>
#include "sierpinski.hpp"

using namespace std; //NOLINT

int main(int argc, char* argv[]) {
if (argc < 3) {
    std::cout << "You need to enter a depth and window size.";
    std::cout << "\nExample:\n\t./sierpinski <depth> <window width>";
    std::cout << "\n\t./Sierpinski 8 500\n";
    exit(1);
  }
    int depth, width;

      istringstream arg_depth(argv[1]);
      arg_depth >> depth;
      stringstream arg_width(argv[2]);
      arg_width >> width;

    if (depth < 0) {
        throw std::runtime_error(" depth needs to be greater than 0.");
    } else if (depth > 10) {
       throw std::runtime_error(" depth needs to be less than 10.");
    }

    if (width < 100) {
         throw std::runtime_error(" window size needs to be greater than 100.");
    }

    double height = (sqrt(3) / 2.0) * (double)width; //NOLINT
    sf::RenderWindow window(sf::VideoMode(width, height), "Sierpinski");
    window.setFramerateLimit(30);
    Sierpinski triangle_draw(depth, width);

    while (window.isOpen()) {
         sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }
        window.clear(sf::Color::White);
        window.draw(triangle_draw);
        window.display();
    }
    return 0;
} //NOLINT