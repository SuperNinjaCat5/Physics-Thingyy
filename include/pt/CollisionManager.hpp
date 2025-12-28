#pragma once
#include "pt/CollisionManager.hpp"
#include "pt/RigidBody.hpp"
#include "pt/Surface.hpp"
#include <memory>
#include <vector>

namespace pt {
class CollisionManager {
private:
  std::vector<std::unique_ptr<RigidBody2d>> pBodies;
  std::vector<std::unique_ptr<Surface2d>> pSurfaces;

  bool checkCollision(RigidBody2d *pBody, Surface2d *pSurface);

  bool checkCollision(RigidBody2d *pBodyA, RigidBody2d *pBodyB);

  void resolveCollision(RigidBody2d *pBody, Surface2d *pSurface, float &dt);

  void resolveCollision(RigidBody2d *pBodyA, RigidBody2d *pBodyB);

public:
  // Constructor
  CollisionManager();

  // Actions
  void addSurface(Surface2d *psSurface);
  void addRigidBody(RigidBody2d *pRigidBody);

  void update(float &dt);
};

} // namespace pt