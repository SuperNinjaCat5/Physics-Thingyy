#include "RigidBody.hpp"
#include "RigidBodyRectangle.hpp"
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

  pt::RigidBodyRectangle rect = pt::RigidBodyRectangle(50, 50, &window);
  pt::RigidBodyRectangle rect1 =
      pt::RigidBodyRectangle(50, 50, &window, pt::Vec2::Zero, pt::Vec2{150, 0});

  while (window.isOpen()) {

    // Events
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    };

    // Forces -----------------------------
    rect.addForce(pt::Vec2{-50, 0});
    rect.addForce(pt::Vec2{0, 50});

    rect1.addForce(pt::Vec2{50, 23});

    // Updates ----------------------------
    float dt = dtClock.restart().asSeconds();
    rect.update(dt);
    rect1.update(dt);

    // Display ----------------------------
    window.clear();

    // Draws ---
    rect.draw(window);
    rect1.draw(window);

    // --
    window.display();
  };

  return 0;
}
