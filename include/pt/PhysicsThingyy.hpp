#pragma once

#include "pt/vec2.hpp"

// Shapes

#include "pt/RigidBody.hpp"
// <><><>
#include "pt/shapes/RigidBodyRectangle.hpp"

// Surfaces
#include "pt/Surface.hpp"
// <><><>
#include "pt/surfaces/SurfaceRectangle.hpp"

namespace pt {
struct Scale {
  static constexpr float PIXEL_TO_METER = 0.1f;
  static constexpr float METER_TO_PIXEL = 10.0f;
};
} // namespace pt