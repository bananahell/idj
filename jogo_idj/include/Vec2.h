/**
 * @file Vec2.h
 *
 * State's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef VEC2_H
#define VEC2_H


/**
 * State class. The class in which the game manifests its current behavior, like
 which music it's playing or if it wants to quit.
 */
class Vec2 {

 public:

  Vec2(float x1, float y1);

  void GetRandWithDistance(float distance);

  /**
   * Access to the private member quitRequested.
   *
   * @return True if game needs to quit.
   */
  float x;
  /**
   * Function that holds the assets used in the State to be pre-loaded.
   */
  float y;
  const double PI = 3.141592653589793;

};
#endif /* VEC2_H */
