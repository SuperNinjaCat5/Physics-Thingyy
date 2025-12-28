#include "pt/surface.hpp"
#include "pt/helpers/vec2.hpp"
#include <cassert>

namespace pt {
// Constructor

Surface2d::Surface2d(const Vec2 &position_, float mass_)
    : mass(mass_), position(position_) {
  assert(mass_ > 0 && "A rigid bodies mass must be positive");
}

// Value fetches

Vec2 Surface2d::getPosition() const { return position; }

float Surface2d::getMass() const { return mass; }

// Actions

void Surface2d::update(float &dt) { // called once per frame
  return;
}

} // namespace pt
