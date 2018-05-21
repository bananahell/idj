#ifndef PENGUINCANNON_H
#define PENGUINCANNON_H

#include "Component.h"
#include "Timer.h"

#include <string>


class PenguinCannon : public Component {

 public:

  PenguinCannon(GameObject& associated, std::weak_ptr<GameObject> penguinBody);
  ~PenguinCannon();

  void Shoot();
  void Update(float dt);
  void Render();
  bool Is(std::string type);

 private:

  float angle;
  Timer cooldown;
  std::weak_ptr<GameObject> pbody;

};
#endif /* PENGUINCANNON_H */
