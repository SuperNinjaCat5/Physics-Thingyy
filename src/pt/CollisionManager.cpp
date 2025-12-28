#include "pt/PhysicsThingyy.hpp"
#include "pt/RigidBody.hpp"
#include "pt/Surface.hpp"
#include <memory>
#include <vector>

namespace pt {

CollisionManager::CollisionManager() {}

void CollisionManager::addSurface(Surface2d *pSurface) {
  pSurfaces.push_back(std::unique_ptr<Surface2d>(pSurface));
}
void CollisionManager::addRigidBody(RigidBody2d *pRigidBody) {
  pBodies.push_back(std::unique_ptr<RigidBody2d>(pRigidBody));
}

bool CollisionManager::checkCollision(RigidBody2d *pBody, Surface2d *pSurface) {

  return (!((pBody->getMaxX()) < (pSurface->getMinX()) ||
            (pBody->getMinX()) > (pSurface->getMaxX())) &&
          !((pBody->getMaxY()) < (pSurface->getMinY()) ||
            (pBody->getMinY()) > (pSurface->getMaxY())));
}

bool CollisionManager::checkCollision(RigidBody2d *pBodyA,
                                      RigidBody2d *pBodyB) {
  return false;
}

void CollisionManager::resolveCollision(RigidBody2d *pBody,
                                        Surface2d *pSurface) {
  // code to resolve w/ rigid body and surface
  return;
}

void CollisionManager::resolveCollision(RigidBody2d *pBodyA,
                                        RigidBody2d *pBodyB) {
  // code to resolve w/ 2 rigid bodies
  return;
}

void CollisionManager::update(float &dt) {

  for (auto &pBody : pBodies) {
    RigidBody2d *body = pBody.get();
    for (auto &pSurface : pSurfaces) {
      Surface2d *Surface = pSurface.get();
      if (checkCollision(body, Surface)) {
        resolveCollision(body, Surface);
      }
    }
  };

  for (auto &pBodyA : pBodies) {
    RigidBody2d *bodyB = pBodyA.get();
    for (auto &pBodyB : pBodies) {
      RigidBody2d *bodyA = pBodyB.get();
      if (checkCollision(bodyA, bodyA)) {
        resolveCollision(bodyA, bodyB);
      }
    }
  };
}

} // namespace pt