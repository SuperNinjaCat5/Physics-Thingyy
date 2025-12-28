#pragma once
#include "pt/helpers/vec2.hpp"
#include <cmath>

namespace pt {

class Surface2d {
protected:
  Vec2 position;
  float mass;

public:
  // Constructor

  Surface2d(const Vec2 &position_ = Vec2::Zero, float mass_ = 1.0f);

  // Value fetches
  Vec2 getPosition() const;
  float getMass() const;

  virtual float getMinX() const = 0;
  virtual float getMaxX() const = 0;
  virtual float getMinY() const = 0;
  virtual float getMaxY() const = 0;

  // Actions
  virtual void update(float &dt); // called once per frame
};

} // namespace pt