#include "pt/PhysicsThingyy.hpp"
#include "pt/RigidBody.hpp"
#include "pt/Surface.hpp"
#include <iostream>
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
  float overlapX = std::min(pBody->getMaxX(), pSurface->getMaxX()) -
                   std::max(pBody->getMinX(), pSurface->getMinX());

  float overlapY = std::min(pBody->getMaxY(), pSurface->getMaxY()) -
                   std::max(pBody->getMinY(), pSurface->getMinY());

  Vec2 overlap{overlapX, overlapY};

  Vec2 normal;

  if (overlapX < overlapY) {
    float nx =
        (pBody->getPosition().x < pSurface->getPosition().x) ? -1.0f : 1.0f;
    normal = Vec2{nx, 0};

  } else {
    float ny =
        (pBody->getPosition().y < pSurface->getPosition().y) ? -1.0f : 1.0f;
    normal = Vec2{0, ny};
  };

  float overlapAmount = overlap.dot(normal);
  Vec2 delta = normal * overlapAmount;
  pBody->move(delta);

  Vec2 vel = pBody->getVelocity();
  float vNormal = pBody->getVelocity().dot(normal);
  Vec2 vTangent = vel - normal * vNormal;

  if (vTangent.length() < Epsilon) {
    vTangent = Vec2::Zero;
  } else {
    float muBody = pBody->getMaterial().friction;
    float muSurface = pSurface->getMaterial().friction;
    float mu = std::max(muBody, muSurface);
    vTangent *= std::max(0.0f, 1.0f - mu);
  }

  if (vNormal < -Epsilon) {
    float restitution = pBody->getMaterial().Restitution;
    vNormal *= -restitution;
  } else {
    vNormal = 0;
  }

  Vec2 newVel = vTangent + normal * vNormal;
  pBody->setVelocity(newVel);

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

  for (size_t i = 0; i < pBodies.size(); ++i) {
    RigidBody2d *bodyA = pBodies[i].get();
    for (size_t j = i + 1; j < pBodies.size(); ++j) {
      RigidBody2d *bodyB = pBodies[j].get();
      if (checkCollision(bodyA, bodyB)) {
        resolveCollision(bodyA, bodyB);
      }
    }
  };
}

} // namespace pt