#include "pt/RigidBody.hpp"
#include "pt/PhysicsThingyy.hpp"
#include "pt/helpers/Material.hpp"
#include <cassert>

namespace pt {
// Constructor

RigidBody2d::RigidBody2d(const Vec2 &velocity_, const Vec2 &position_,
                         float mass_, const Material &material_,
                         const Vec2 &netForce_)
    : velocity(velocity_), position(position_), mass(mass_),
      material(material_), netForce(netForce_) {
  assert(mass_ > 0 && "A rigid bodies mass must be positive");
};

// Value fetches
Vec2 RigidBody2d::getVelocity() const { return velocity; }

Vec2 RigidBody2d::getPosition() const { return position; }

float RigidBody2d::getMass() const { return mass; }

Vec2 RigidBody2d::getNetForce() const { return netForce; }

Material RigidBody2d::getMaterial() const { return material; }

// Forces

void RigidBody2d::addForce(const Vec2 &force) { netForce += force; }
void RigidBody2d::applyGravity() {
  Vec2 forceG = Vec2{0, mass * -9.8f};
  netForce += forceG;
}

// Actions

void RigidBody2d::update(float &dt) { // called once per frame
  // Apply acceleration from net force
  velocity += (netForce / mass) * dt; // v = v + (a * dt)

  // Apply velocity to position
  position += (velocity * dt); // p = p + (v*dt)

  // Reset netForce for next frame
  netForce = Vec2::Zero;
}

} // namespace pt
