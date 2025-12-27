#pragma once
#include "pt/CollisionManager.hpp"
#include "pt/RigidBody.hpp"
#include "pt/Surface.hpp"
#include <memory>
#include <vector>

namespace pt {
class CollisionManager {
private:
  std::vector<std::unique_ptr<pt::RigidBody2d>> pBodies;
  std::vector<std::unique_ptr<pt::Surface2d>> pSurfaces;

  bool checkCollision(pt::RigidBody2d *pBody, pt::Surface2d *pSurface);

  bool checkCollision(pt::RigidBody2d *pBodyA, pt::RigidBody2d *pBodyB);

  void resolveCollision();

public:
  // Constructor
  CollisionManager();

  // Actions
  void addSurface(pt::Surface2d *psSurface);
  void addRigidBody(pt::RigidBody2d *pRigidBody);

  void update(float &dt);
};

} // namespace pt