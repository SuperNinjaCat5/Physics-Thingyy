#pragma once
#include "pt/Surface.hpp"
#include "pt/helpers/vec2.hpp"
#include <SFML/Graphics.hpp>

namespace pt {

class SurfaceRectangle : public Surface2d {
private:
  sf::RectangleShape rect;
  sf::RenderWindow *pWindow = nullptr;
  float width;
  float height;

public:
  // Constructor

  SurfaceRectangle(const float width, const float height,
                   sf::RenderWindow *window_,
                   const pt::Vec2 &position_ = pt::Vec2::Zero,
                   float mass_ = 1.0f);

  // Value fetches
  pt::Vec2 getPosition() const;
  float getMass() const;

  float getMinX() const;
  float getMaxX() const;
  float getMinY() const;
  float getMaxY() const;

  // Actions
  void update(float &dt); // called once per frame

  void draw(sf::RenderWindow &window_, const bool flipY = false,
            sf::RenderStates states_ = sf::RenderStates()) const;
};

} // namespace pt