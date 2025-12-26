#include "RigidBody.hpp"
#include "vec2.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <iostream>

namespace UIConfig {
const int WIDTH = 800;
const int HEIGHT = 600;
}; // namespace UIConfig

int main() {

  // Window setup

  sf::RenderWindow window(sf::VideoMode({UIConfig::WIDTH, UIConfig::HEIGHT}),
                          "Physics Engine");

  const sf::Font font("roboto.ttf");

  // View setup

  sf::View view;

  view.setCenter({0.0f, 0.0f});

  window.setView(view);

  // Delta time setup

  sf::Clock dtClock;

  // Shapes setup

  sf::RectangleShape rect({50.0f, 50.0f});
  rect.setOrigin({rect.getSize().x / 2, rect.getSize().y / 2});
  pt::RigidBody2d rectRB = pt::RigidBody2d(pt::Vec2{50, 0});

  while (window.isOpen()) {

    // Events
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    };

    // Updates
    float dt = dtClock.restart().asSeconds();
    rectRB.update(dt);

    // Movements
    pt::Vec2 rectPos = rectRB.getPosition();
    rect.setPosition(sf::Vector2{rectPos.x, rectPos.y});

    // Display
    window.clear();
    window.draw(rect);
    window.display();
  };

  return 0;
}