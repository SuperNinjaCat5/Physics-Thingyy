#pragma once
#include "pt/helpers/Material.hpp"
#include "pt/helpers/vec2.hpp"
#include <cmath>

namespace pt {

class Surface2d {
protected:
  Vec2 position;
  Material material;

public:
  // Constructor

  Surface2d(const Vec2 &positionPixels_ = Vec2::Zero,
            Material material_ = Material::STEEL);

  // Value fetches
  Vec2 getPosition() const;
  float getMass() const;
  Material getMaterial() const;

  virtual float getMinX() const = 0;
  virtual float getMaxX() const = 0;
  virtual float getMinY() const = 0;
  virtual float getMaxY() const = 0;

  // Actions
  virtual void update(float &dt); // called once per frame
};

} // namespace pt