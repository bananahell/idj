#ifndef PENGUINBODY_H
#define PENGUINBODY_H

#include "Component.h"

#include <string>


class PenguinBody : public Component {

 private:

  int hp;
  Vec2 speed;
  float linearSpeed;
  float angle;
  std::weak_ptr<GameObject> pcannon;

 public:

  static PenguinBody* player;

  PenguinBody(GameObject& associated);
  ~PenguinBody();
  void Start();
  void Damage(int damage);
  void Update(float dt);
  void Render(Vec2 cameraPos);
  void NotifyCollision(GameObject& other);
  bool Is(std::string type);
  Vec2 GetPlayerCenter();

};

#endif /* PENGUINBODY_H_ */
