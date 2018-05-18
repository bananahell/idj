/**
 * @file Component.h
 *
 * Component's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef BULLET_H
#define BULLET_H

#include "Component.h"

#include <string>


class Bullet : public Component {

 private:

  Vec2 speed;
  int damage;
  float distanceLeft;

 public:

  Bullet(GameObject& associated,
         float maxDistance,
         float angle,
         float speed,
         int damage,
         std::string sprite);
  ~Bullet();
  void Update(float dt);
  void Render(Vec2 cameraPos);
  bool Is(std::string type);
  int GetDamage();

};

#endif /* BULLET_H */
