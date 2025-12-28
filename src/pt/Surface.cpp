#include "pt/surface.hpp"
#include "pt/PhysicsThingyy.hpp"
#include "pt/helpers/vec2.hpp"
#include <cassert>

namespace pt {
// Constructor

Surface2d::Surface2d(const Vec2 &positionPixels_, Material material_)
    : position(positionPixels_ * Scale::PIXEL_TO_METER), material(material_) {}

// Value fetches

Vec2 Surface2d::getPosition() const { return position; }

Material Surface2d::getMaterial() const { return material; }

// Actions

void Surface2d::update(float &dt) { // called once per frame
  return;
}

} // namespace pt
