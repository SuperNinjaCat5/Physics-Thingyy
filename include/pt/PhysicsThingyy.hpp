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
  const float PIXEL_TO_METER;
  const float METER_TO_PIXEL;
};
} // namespace pt