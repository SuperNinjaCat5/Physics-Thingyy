#include "pt/RigidBody.hpp"
#include "pt/vec2.hpp"
#include <cassert>

namespace pt {
// Constructor

RigidBody2d::RigidBody2d(const pt::Vec2 &velocity_, const pt::Vec2 &position_,
                         float mass_, const pt::Vec2 &netForce_)
    : mass(mass_), velocity(velocity_), position(position_),
      netForce(netForce_) {
  assert(mass_ > 0 && "A rigid bodies mass must be positive");
};

// Value fetches
pt::Vec2 RigidBody2d::getVelocity() const { return velocity; }

pt::Vec2 RigidBody2d::getPosition() const { return position; }

float RigidBody2d::getMass() const { return mass; }

pt::Vec2 RigidBody2d::getNetForce() const { return netForce; }

// Forces

void RigidBody2d::addForce(const pt::Vec2 &force) { netForce += force; }
// void RigidBody2d::applyGravity(const pt::Vec2 direction) {

//   Vec2 forceG = mass * 9.8;

//   switch (direction) {
//   case const Vec2::{0, -1}:
//     netForce break;

//   default:
//     break;
//   }
//   netForce += force;
// }

// Actions

void RigidBody2d::update(float &dt) { // called once per frame
  // Apply acceleration from net force
  velocity += (netForce / mass) * dt; // v = v + (a * dt)

  // Apply velocity to position
  position += (velocity * dt); // p = p + (v*dt)

  // Reset netForce for next frame
  netForce = pt::Vec2::Zero;
}

} // namespace pt
