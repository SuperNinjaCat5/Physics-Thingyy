#include "pt/PhysicsThingyy.hpp"
#include "pt/RigidBody.hpp"
#include "pt/Surface.hpp"
#include <memory>
#include <vector>

namespace pt {

CollisionManager::CollisionManager() {}

void CollisionManager::addSurface(pt::Surface2d *pSurface) {
  pSurfaces.push_back(std::unique_ptr<pt::Surface2d>(pSurface));
}
void CollisionManager::addRigidBody(pt::RigidBody2d *pRigidBody) {
  pBodies.push_back(std::unique_ptr<pt::RigidBody2d>(pRigidBody));
}

bool CollisionManager::checkCollision(pt::RigidBody2d *pBody,
                                      pt::Surface2d *pSurface) {

  return (!((pBody->getMaxX()) < (pSurface->getMinX()) ||
            (pBody->getMinX()) > (pSurface->getMaxX())) &&
          !((pBody->getMaxY()) < (pSurface->getMinY()) ||
            (pBody->getMinY()) > (pSurface->getMaxY())));
}

bool CollisionManager::checkCollision(pt::RigidBody2d *pBodyA,
                                      pt::RigidBody2d *pBodyB) {
  return false;
}

} // namespace pt