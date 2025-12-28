#pragma once

namespace pt {
struct Material {
  float Restitution;
  float friction;

  // Constructor

  Material(float friction_, float Restitution_);

  // Premade mats

  static const Material CHUCK_D_CUBE;
  static const Material WOOD;
  static const Material STEEL;
  static const Material RUBBER;
  static const Material ICE;
  static const Material CONCRETE;
};
} // namespace pt