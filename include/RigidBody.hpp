#pragma once
#include <cmath>
#include <vec2.hpp>

namespace pt {

class RigidBody2d {
protected:
  pt::Vec2 velocity;
  pt::Vec2 position;
  float mass;

public:
  // Constructor

  RigidBody2d(pt::Vec2 velocity_, pt::Vec2 position_, float mass_)
      : mass(mass_), velocity(velocity_), position(position_) {}

  // get all values
  pt::Vec2 getVelocity();
  pt::Vec2 getPosition();
  pt::Vec2 getMass();

  // More to come....
};

} // namespace pt