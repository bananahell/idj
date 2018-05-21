#ifndef CAMERAFOLLOWER_H
#define CAMERAFOLLOWER_H

#include "Component.h"

#include <string>


class CameraFollower : public Component {

 public:

  CameraFollower(GameObject& associated, Vec2 truePos = Vec2());
  ~CameraFollower();

  void SetTruePos(Vec2 pos);
  void Update(float dt);
  void Render();
  bool Is(std::string type);

  Vec2 truePos;

};
#endif /* CAMERAFOLLOWER_H */
