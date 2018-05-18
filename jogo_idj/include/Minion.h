/**
 * @file Component.h
 *
 * Component's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef MINION_H
#define MINION_H

#include "Component.h"

#include <memory>
#include <string>


class Minion : public Component {

 private:

  std::weak_ptr<GameObject> alienCenter;
  float arc;

 public:

  Minion(GameObject& associated, std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg);
  void Update(float dt);
  void Render();
  bool Is(std::string type);
  void Shoot(Vec2 target);

};

#endif /* MINION_H */
