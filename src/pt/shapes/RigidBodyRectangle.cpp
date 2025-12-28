#include "pt/shapes/RigidBodyRectangle.hpp"
#include "pt/PhysicsThingyy.hpp"
#include <cassert>

namespace pt {
// Constructor

RigidBodyRectangle::RigidBodyRectangle(const float width_, const float height_,
                                       sf::RenderWindow *window_,
                                       const Vec2 &velocity_,
                                       const Vec2 &position_, float mass_,
                                       const Material &material_,
                                       const Vec2 &netForce_)
    : RigidBody2d(velocity_, position_, mass_, material_,
                  netForce_), // base constructor
      width(width_), height(height_), pWindow(window_) {

  rect.setSize({width, height});
  rect.setOrigin({rect.getSize().x / 2, rect.getSize().y / 2});

  assert(mass_ > 0 && "A rigid bodies mass must be positive");
};

// Value fetches

float RigidBodyRectangle::getWidth() const { return width; }
float RigidBodyRectangle::getHeight() const { return height; }
sf::RectangleShape RigidBodyRectangle::getRect() const { return rect; }

float RigidBodyRectangle::getMinX() const { return position.x - width / 2; }
float RigidBodyRectangle::getMaxX() const { return position.x + width / 2; }
float RigidBodyRectangle::getMinY() const { return position.y - height / 2; }
float RigidBodyRectangle::getMaxY() const { return position.y + height / 2; }

// Actions

void RigidBodyRectangle::update(float &dt) { // called once per frame
  // Apply acceleration from net force
  velocity += (netForce / mass) * dt; // v = v + (a * dt)

  // Apply velocity to position
  position += (velocity * dt); // p = p + (v*dt)

  // Move on screen
  rect.setPosition(sf::Vector2f{position.x * Scale::METER_TO_PIXEL,
                                position.y * Scale::METER_TO_PIXEL});

  // Reset netForce for next frame
  netForce = Vec2::Zero;
}

void RigidBodyRectangle::draw(sf::RenderWindow &window_, const bool flipY,
                              sf::RenderStates states_) const {

  if (!flipY) { // if flip y (so if flip y is false dont do nothing)
    states_.transform.scale({1.f, -1.f});
  }

  window_.draw(rect, states_);
};

} // namespace pt
