#pragma once
#include "pt/vec2.hpp"
#include <cmath>

namespace pt {

class Surface2d {
protected:
  pt::Vec2 position;
  float mass;

public:
  // Constructor

  Surface2d(const pt::Vec2 &position_ = pt::Vec2::Zero, float mass_ = 1.0f);

  // Value fetches
  pt::Vec2 getPosition() const;
  float getMass() const;

  // Actions
  virtual void update(float &dt); // called once per frame
};

} // namespace pt