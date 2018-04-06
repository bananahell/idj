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

  /**
   * Vec2's constructor. Sets its horizontal and vertical coordinates.
   *
   * @param x1 - Vec2's horizontal coordinate.
   * @param y1 - Vec2's vertical coordinate.
   */
  Vec2(float x1, float y1);

  /**
   * Function that gets a random point in the game with distance given.
   *
   * @param distance - Distance between first Vec2 value and second random Vec2.
   */
  void GetRandWithDistance(float distance);

  /**
   * Horizontal coordinate of Vec2.
   */
  float x;
  /**
   * Vertical coordinate of Vec2.
   */
  float y;
  /**
   * The number pi manually declared.
   */
  const double PI = 3.141592653589793;

};
#endif /* VEC2_H */
