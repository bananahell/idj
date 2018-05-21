#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"


class Camera {

 public:

  static Vec2 pos;
  static Vec2 speed;

  static void Follow(GameObject* newFocus);
  static void Unfollow();
  static void Update(float dt);
  static GameObject* GetFocus();

 private:

  static  GameObject* focus;

};
#endif /* CAMERA_H */
