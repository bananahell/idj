#ifndef MINION_H
#define MINION_H

#include "Component.h"

#include <memory>
#include <string>


class Minion : public Component {

 public:

  Minion(GameObject& associated, GameObject& alienCenter, float arcOffsetDeg);
  ~Minion();

  void Shoot(Vec2 target);
  void Update(float dt);
  void Render();
  bool Is(std::string type);

 private:

  std::weak_ptr<GameObject> alienCenter;
  float arc;

};
#endif /* MINION_H */
