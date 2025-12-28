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

void CollisionManager::resolveCollision(pt::RigidBody2d *pBody,
                                        pt::Surface2d *pSurface) {
  // code to resolve w/ rigid body and surface
  return;
}

void CollisionManager::resolveCollision(pt::RigidBody2d *pBodyA,
                                        pt::RigidBody2d *pBodyB) {
  // code to resolve w/ 2 rigid bodies
  return;
}

void CollisionManager::update(float &dt) {

  for (auto &pBody : pBodies) {
    pt::RigidBody2d *body = pBody.get();
    for (auto &pSurface : pSurfaces) {
      pt::Surface2d *Surface = pSurface.get();
      if (checkCollision(body, Surface)) {
        resolveCollision(body, Surface);
      }
    }
  };

  for (auto &pBodyA : pBodies) {
    pt::RigidBody2d *bodyB = pBodyA.get();
    for (auto &pBodyB : pBodies) {
      pt::RigidBody2d *bodyA = pBodyB.get();
      if (checkCollision(bodyA, bodyA)) {
        resolveCollision(bodyA, bodyB);
      }
    }
  };
}

} // namespace pt