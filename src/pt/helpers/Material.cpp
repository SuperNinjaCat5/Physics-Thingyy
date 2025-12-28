#include "pt/helpers/Material.hpp"

// Materials
namespace pt {
// Constructor

Material::Material(float friction_, float Restitution_)
    : friction(friction_), Restitution(Restitution_) {};

// Premade mats
const Material Material::CHUCK_D_CUBE(1.0f, 0.0f); // MAX friction, NO BOUNCE
const Material Material::WOOD(0.4f, 0.3f);   // medium friction, low bounce
const Material Material::STEEL(0.2f, 0.1f);  // low friction, very low bounce
const Material Material::RUBBER(0.8f, 0.9f); // high friction, very bouncy
const Material Material::ICE(0.05f, 0.05f);  // almost no friction, tiny bounce
const Material Material::CONCRETE(0.6f, 0.2f); // high friction, low bounce

}; // namespace pt
