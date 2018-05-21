#ifndef BULLET_H
#define BULLET_H

#include "Component.h"

#include <string>


class Sprite;

class Bullet : public Component {

 public:

  Bullet(GameObject& associated, Sprite* sprite, std::string owner, float maxDistance, float angle, float speed, int damage);
  ~Bullet();

  void Update(float dt);
  void Render();
  void NotifyCollision(GameObject& other);
  bool Is(std::string type);
  bool IsOwner(std::string owner);
  int GetDamage();

 private:

  std::string owner;
  Vec2 speed;
  int damage;
  float distanceLeft;

};
#endif /* BULLET_H */
