#ifndef COLLIDER_H
#define COLLIDER_H

#include "Component.h"

#include <string>


class Collider : public Component {

 public:

  Collider(GameObject& associated, Vec2 scale = {1, 1}, Vec2 offset = {0, 0});
  ~Collider();

  void SetScale(Vec2 scale);
  void SetOffset(Vec2 offset);
  void Update(float dt);
  void Render();
  bool Is(std::string type);

  Rect box;
  float rotation;

 private:

  Vec2 scale;
  Vec2 offset;

};
#endif /* COLLIDER_H */
