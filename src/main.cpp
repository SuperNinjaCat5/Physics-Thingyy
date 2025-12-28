#include "pt/PhysicsThingyy.hpp"
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

  const sf::Font font("static/roboto.ttf");

  // View setup

  sf::View view;

  view.setCenter({0.0f, 0.0f});

  window.setView(view);

  // Delta time setup

  sf::Clock dtClock;

  // Shapes setup

  pt::RigidBodyRectangle rect = pt::RigidBodyRectangle(
      50, 50, &window, {15, 0}, pt::Vec2::Zero, 10.0f, pt::Material::RUBBER);

  pt::SurfaceRectangle floor =
      pt::SurfaceRectangle(1000, 25, &window, {0, -30}, pt::Material::CONCRETE);

  // Collision setup

  pt::CollisionManager collisionManager;

  collisionManager.addRigidBody(&rect);
  collisionManager.addSurface(&floor);

  while (window.isOpen()) {

    // Events
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    };

    // Forces -----------------------------

    rect.applyGravity();

    // rect.addForce(pt::Vec2{-50, 0});
    // rect.addForce(pt::Vec2{-10, 0});

    // Updates ----------------------------
    float dt = dtClock.restart().asSeconds();
    rect.update(dt);
    floor.update(dt);
    collisionManager.update(dt);

    // Display ----------------------------
    window.clear();

    // Draws ---
    floor.draw(window);
    rect.draw(window);

    // --
    window.display();
  };

  return 0;
}
