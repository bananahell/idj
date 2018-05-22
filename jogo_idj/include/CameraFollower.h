/**
 * @file CameraFollower.h
 *
 * CameraFollower's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef CAMERAFOLLOWER_H
#define CAMERAFOLLOWER_H

#include "Component.h"

#include <string>


/**
 * CameraFollower class. Class that holds the tile set clipped from an image to be
 * shown in a tile map.
 */
class CameraFollower : public Component {

 public:

  CameraFollower(GameObject& associated, Vec2 truePos = Vec2());
  ~CameraFollower();

  void Update(float dt);
  void Render();
  bool Is(std::string type);
  void SetTruePos(Vec2 pos);

  Vec2 truePos;

};
#endif /* CAMERAFOLLOWER_H */
