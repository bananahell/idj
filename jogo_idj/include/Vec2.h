/**
 * @file Vec2.h
 *
 * Vec2's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef VEC2_H
#define VEC2_H


/**
 * Vec2 class. Class responsible for vectorized operations in the game.
 */
class Vec2 {

 public:

  Vec2();
  /**
   * Vec2's constructor. Sets its horizontal and vertical coordinates.
   *
   * @param x1 - Vec2's horizontal coordinate.
   * @param y1 - Vec2's vertical coordinate.
   */
  Vec2(float x, float y);
  ~Vec2();

  Vec2 operator+(const Vec2& rhs) const;
  Vec2 operator+(const float rhs) const;
  Vec2 operator-(const Vec2& rhs) const;
  Vec2 operator-(const float rhs) const;
  Vec2 operator*(const Vec2& rhs) const;
  Vec2 operator*(const float rhs) const;
  Vec2 operator/(const Vec2& rhs) const;
  Vec2 operator/(const float rhs) const;

  Vec2 Rotate(float ang);
  float GetDX(float x);
  float GetDY(float y);
  float GetDS(Vec2 pos);
  float GetCos(Vec2 pos);
  float GetSin(Vec2 pos);
  float GetAngle(Vec2 pos);
  static float Cos(float ang);
  static float Sin(float ang);
  static Vec2 Project(float dist, float ang);

  /**
   * Horizontal coordinate of Vec2.
   */
  float x;
  /**
   * Vertical coordinate of Vec2.
   */
  float y;

};
#endif /* VEC2_H */
