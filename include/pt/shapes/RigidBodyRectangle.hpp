#pragma once
#include "pt/RigidBody.hpp"
#include "pt/helpers/vec2.hpp"
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
                     const Vec2 &velocity_ = Vec2::Zero,
                     const Vec2 &position_ = Vec2::Zero, float mass_ = 1.0f,
                     const Material &material_ = Material::STEEL,
                     const Vec2 &netForce = Vec2::Zero);

  // Value fetches

  float getWidth() const;
  float getHeight() const;
  sf::RectangleShape getRect() const;

  float getMinX() const override;
  float getMaxX() const override;
  float getMinY() const override;
  float getMaxY() const override;

  // Actions

  void update(float &dt) override;
  void draw(sf::RenderWindow &window_, const bool flipY = false,
            sf::RenderStates states_ = sf::RenderStates()) const;
};

} // namespace pt