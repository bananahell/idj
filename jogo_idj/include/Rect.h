/**
 * @file Rect.h
 *
 * State's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef RECT_H
#define RECT_H


/**
 * State class. The class in which the game manifests its current behavior, like
 which music it's playing or if it wants to quit.
 */
class Rect {

 public:

  Rect();
  Rect(float w, float h);

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
  /**
   * Function that determines the behavior of the game when something happens,
   like when the player inserts an input.
   */
  float w;
  /**
   * Function that gathers Sprite's renderings and takes them to Game.
   */
  float h;

};
#endif /* RECT_H */
