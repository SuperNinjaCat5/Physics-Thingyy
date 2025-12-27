#include "pt/PhysicsThingyy.hpp"
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
void RigidBody2d::applyGravity() {
  Vec2 forceG = Vec2{0, mass * -9.8f};
  netForce += forceG;
}

// Actions

void RigidBody2d::update(float &dt) { // called once per frame
  // Apply acceleration from net force
  velocity +=
      ((netForce / mass) * dt) * Scale::METER_TO_PIXEL; // v = v + (a * dt)

  // Apply velocity to position
  position += (velocity * dt); // p = p + (v*dt)

  // Reset netForce for next frame
  netForce = pt::Vec2::Zero;
}

} // namespace pt
