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

#include <string.h>


/**
 * CameraFollower class. Class that holds the tile set clipped from an image to be
 * shown in a tile map.
 */
class CameraFollower : public Component {

 public:

  CameraFollower(GameObject& associated);

  void Update(float dt);
  void Render(Vec2 cameraPos);
  bool Is(std::string type);

};
#endif /* CAMERAFOLLOWER_H */
