#pragma once
#include "pt/helpers/vec2.hpp"
#include <cmath>

namespace pt {

class RigidBody2d {
protected:
  pt::Vec2 velocity;
  pt::Vec2 position;
  float mass;
  pt::Vec2 netForce;

public:
  // Constructor

  RigidBody2d(const pt::Vec2 &velocity_ = pt::Vec2::Zero,
              const pt::Vec2 &position_ = pt::Vec2::Zero, float mass_ = 1.0f,
              const pt::Vec2 &netForce = pt::Vec2::Zero);

  // Value fetches
  pt::Vec2 getVelocity() const;
  pt::Vec2 getPosition() const;
  float getMass() const;
  pt::Vec2 getNetForce() const;

  virtual float getMinX() const = 0;
  virtual float getMaxX() const = 0;
  virtual float getMinY() const = 0;
  virtual float getMaxY() const = 0;

  // Forces

  virtual void addForce(const pt::Vec2 &force);
  virtual void applyGravity(); // could add const Vec2 direction later

  // Actions
  virtual void update(float &dt); // called once per frame
};

} // namespace pt