#include "pt/surfaces/SurfaceRectangle.hpp"
#include "pt/PhysicsThingyy.hpp"
#include "pt/Surface.hpp"
#include "pt/helpers/Material.hpp"
#include "pt/helpers/vec2.hpp"
#include <cassert>

namespace pt {
// Constructor

SurfaceRectangle::SurfaceRectangle(const float width_, const float height_,
                                   sf::RenderWindow *window_,
                                   const Vec2 &positionPixels_,
                                   Material material_)
    : Surface2d(positionPixels_, material_), // base constructor
      widthMeters(width_ * Scale::PIXEL_TO_METER),
      heightMeters(height_ * Scale::PIXEL_TO_METER), pWindow(window_) {

  rect.setSize({width_, height_});
  rect.setOrigin({rect.getSize().x / 2, rect.getSize().y / 2});
};

// Value fetches

Vec2 SurfaceRectangle::getPosition() const { return position; }

float SurfaceRectangle::getMinX() const { return position.x - widthMeters / 2; }
float SurfaceRectangle::getMaxX() const { return position.x + widthMeters / 2; }
float SurfaceRectangle::getMinY() const {
  return position.y - heightMeters / 2;
}
float SurfaceRectangle::getMaxY() const {
  return position.y + heightMeters / 2;
}

// Actions

void SurfaceRectangle::update(float &dt) { // called once per frame
  rect.setPosition(sf::Vector2f{position.x * Scale::METER_TO_PIXEL,
                                position.y * Scale::METER_TO_PIXEL});
}

void SurfaceRectangle::draw(sf::RenderWindow &window_, const bool flipY,
                            sf::RenderStates states_) const {

  if (!flipY) { // if flip y (so if flip y is false dont do nothing)
    states_.transform.scale({1.f, -1.f});
  }

  window_.draw(rect, states_);
};

} // namespace pt
