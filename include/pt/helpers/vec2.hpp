#pragma once
#include <cmath>

namespace pt {

struct Vec2 {
  float x, y;

  Vec2(float x_ = 0.0f, float y_ = 0.0f);

  static const Vec2 Zero;

  // Normal Vec operations
  Vec2 operator+(const Vec2 &other) const;
  Vec2 operator-(const Vec2 &other) const;
  Vec2 operator*(float k) const;
  Vec2 operator/(float k) const;

  // Assignment operations
  Vec2 &operator+=(const Vec2 &other);
  Vec2 &operator-=(const Vec2 &other);
  Vec2 &operator*=(float k);
  Vec2 &operator/=(float k);

  // Comparison
  bool operator==(const Vec2 &other) const;
  bool operator!=(const Vec2 &other) const;
  bool isZero() const;

  // Special operations
  Vec2 operator-() const;
  float dot(const Vec2 &other) const;
  float length() const;
  float distanceTo(const Vec2 &other) const;
  Vec2 normalize() const;
};

} // namespace pt
