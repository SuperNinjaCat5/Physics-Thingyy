#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vec2.hpp>

namespace UIConfig {
const int WIDTH = 800;
const int HEIGHT = 600;
}; // namespace UIConfig

int main() {

  sf::RenderWindow window(sf::VideoMode({UIConfig::WIDTH, UIConfig::HEIGHT}),
                          "Physics Engine");

  const sf::Font font("roboto.ttf");

  sf::RectangleShape rect({50.0f, 50.0f});

  while (window.isOpen()) {

    // Events
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    };

    rect.setOrigin({rect.getSize().x / 2, rect.getSize().y / 2});
    rect.setPosition(sf::Vector2f{UIConfig::WIDTH / 2, UIConfig::HEIGHT / 2});

    // Display
    window.clear();
    window.draw(rect);
    window.display();
  };

  return 0;
}