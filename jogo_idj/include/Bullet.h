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

class Sprite;


class Bullet : public Component {

 private:

  std::string owner;
  Vec2 speed;
  int damage;
  float distanceLeft;

 public:

  Bullet(GameObject& associated,
         Sprite* sprite,
         std::string owner,
         float maxDistance,
         float angle,
         float speed,
         int damage);
  ~Bullet();
  void Update(float dt);
  void Render(Vec2 cameraPos);
  bool Is(std::string type);
  int GetDamage();
  bool IsOwner(std::string owner);

};
#endif /* BULLET_H */
