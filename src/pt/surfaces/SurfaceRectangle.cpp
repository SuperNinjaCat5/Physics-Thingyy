#include "pt/surfaces/SurfaceRectangle.hpp"
#include "pt/Surface.hpp"
#include "pt/vec2.hpp"
#include <cassert>

namespace pt {
// Constructor

SurfaceRectangle::SurfaceRectangle(const float width_, const float height_,
                                   sf::RenderWindow *window_,
                                   const pt::Vec2 &position_, float mass_)
    : Surface2d(position_, mass_), // base constructor
      width(width_), height(height_), pWindow(window_) {

  rect.setSize({width, height});
  rect.setOrigin({rect.getSize().x / 2, rect.getSize().y / 2});

  assert(mass_ > 0 && "A rigid bodies mass must be positive");
};

// Value fetches

pt::Vec2 SurfaceRectangle::getPosition() const { return position; }

float SurfaceRectangle::getMass() const { return mass; }

// Actions

void SurfaceRectangle::update(float &dt) { // called once per frame
  rect.setPosition(sf::Vector2f{position.x, position.y});
}

void SurfaceRectangle::draw(sf::RenderWindow &window_, const bool flipY,
                            sf::RenderStates states_) const {

  if (!flipY) { // if flip y (so if flip y is false dont do nothing)
    states_.transform.scale({1.f, -1.f});
  }

  window_.draw(rect, states_);
};

} // namespace pt
