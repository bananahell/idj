/**
 * @file Camera.h
 *
 * Camera's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"


/**
 * Camera class. Class that holds the tile set clipped from an image to be
 * shown in a tile map.
 */
class Camera {

 public:

  static void Follow(GameObject* newFocus);
  static void Unfollow();
  static void Update(float dt);
  static GameObject* GetFocus();

  static Vec2 pos;
  static Vec2 speed;

 private:

  static  GameObject* focus;

};
#endif /* CAMERA_H */
