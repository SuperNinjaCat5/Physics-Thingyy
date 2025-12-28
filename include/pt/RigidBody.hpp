#pragma once
#include "pt/helpers/Material.hpp"
#include "pt/helpers/vec2.hpp"
#include <cmath>

namespace pt {

class RigidBody2d {
protected:
  Vec2 velocity;
  Vec2 position;
  float mass;
  Vec2 netForce;
  Material material;

public:
  // Constructor

  RigidBody2d(const Vec2 &velocity_ = Vec2::Zero,
              const Vec2 &position_ = Vec2::Zero, float mass_ = 1.0f,
              const Material &material_ = Material::STEEL,
              const Vec2 &netForce_ = Vec2::Zero);

  // Value fetches
  Vec2 getVelocity() const;
  Vec2 getPosition() const;
  float getMass() const;
  Vec2 getNetForce() const;
  Material getMaterial() const;

  virtual float getMinX() const = 0;
  virtual float getMaxX() const = 0;
  virtual float getMinY() const = 0;
  virtual float getMaxY() const = 0;

  // Forces

  virtual void move(Vec2 &delta) = 0;
  virtual void setVelocity(Vec2 &newVelocity) = 0;
  virtual void addForce(const Vec2 &force);
  virtual void applyGravity(); // could add const Vec2 direction later

  // Actions
  virtual void update(float &dt); // called once per frame
};

} // namespace pt