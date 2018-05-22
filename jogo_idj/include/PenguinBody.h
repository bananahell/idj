#ifndef PENGUINBODY_H
#define PENGUINBODY_H

#include "Component.h"

#include <string>


class PenguinBody : public Component {

 public:

  explicit PenguinBody(GameObject& associated);
  ~PenguinBody();

  void Start();
  void Damage(int damage);
  void Update(float dt);
  void Render();
  void NotifyCollision(GameObject& other);
  bool Is(std::string type);
  Vec2 GetPlayerCenter();

  static PenguinBody* player;

 private:

  int hp;
  Vec2 speed;
  float linearSpeed;
  float angle;
  std::weak_ptr<GameObject> pcannon;

};
#endif /* PENGUINBODY_H */
