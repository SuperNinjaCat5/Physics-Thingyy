#pragma once
#include "RigidBody.hpp"
#include "vec2.hpp"
#include <SFML/Graphics.hpp>

namespace pt {

class RigidBodyRectangle : public RigidBody2d {
private:
  sf::RectangleShape rect;
  sf::RenderWindow *pWindow = nullptr;
  float width;
  float height;

public:
  // Constructor

  RigidBodyRectangle(const float width, const float height,
                     sf::RenderWindow *window_,
                     const pt::Vec2 &velocity_ = pt::Vec2::Zero,
                     const pt::Vec2 &position_ = pt::Vec2::Zero,
                     float mass_ = 1.0f,
                     const pt::Vec2 &netForce = pt::Vec2::Zero);

  // Value fetches

  float getWidth() const;
  float getHeight() const;
  sf::RectangleShape getRect() const;

  // Actions

  void update(float &dt) override;
  void draw(sf::RenderWindow &window_, const bool flipY = false,
            sf::RenderStates states_ = sf::RenderStates()) const;
};

} // namespace pt