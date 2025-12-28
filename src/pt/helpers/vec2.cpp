#include "pt/helpers/vec2.hpp"

namespace pt {

// Constructor
Vec2::Vec2(float x_, float y_) : x(x_), y(y_) {}

// Normal Vec operations
Vec2 Vec2::operator+(const Vec2 &other) const {
  return Vec2{x + other.x, y + other.y};
}
Vec2 Vec2::operator-(const Vec2 &other) const {
  return Vec2{x - other.x, y - other.y};
}
Vec2 Vec2::operator*(float k) const { return Vec2{x * k, y * k}; }
Vec2 Vec2::operator/(float k) const { return Vec2{x / k, y / k}; }

// Assignment operations
Vec2 &Vec2::operator+=(const Vec2 &other) {
  x += other.x;
  y += other.y;
  return *this;
}
Vec2 &Vec2::operator-=(const Vec2 &other) {
  x -= other.x;
  y -= other.y;
  return *this;
}
Vec2 &Vec2::operator*=(float k) {
  x *= k;
  y *= k;
  return *this;
}
Vec2 &Vec2::operator/=(float k) {
  x /= k;
  y /= k;
  return *this;
}

// Comparison
bool Vec2::operator==(const Vec2 &other) const {
  return x == other.x && y == other.y;
}
bool Vec2::operator!=(const Vec2 &other) const { return !(*this == other); }
bool Vec2::isZero() const { return x == 0 && y == 0; }

// Special operations
Vec2 Vec2::operator-() const { return Vec2{-x, -y}; }
float Vec2::dot(const Vec2 &other) const { return x * other.x + y * other.y; }
float Vec2::length() const { return std::sqrt(x * x + y * y); }
float Vec2::distanceTo(const Vec2 &other) const {
  return (*this - other).length();
}
Vec2 Vec2::normalize() const {
  if (isZero())
    return *this;
  float mag = length();
  return Vec2{x / mag, y / mag};
}

// Special vectors
const Vec2 Vec2::Zero(0.0f, 0.0f);

} // namespace pt
