#ifndef ALIEN_H_
#define ALIEN_H_

#include "Component.h"
#include "Timer.h"

#include <memory>
#include <string>
#include <vector>


class Alien : public Component {

 public:

  Alien(GameObject& associated, int nMinions);
  ~Alien();

  void Start();
  void Damage(int damage);
  void Update(float dt);
  void Render();
  void NotifyCollision(GameObject& other);
  bool Is(std::string type);

  static int alienCount;

 private:

  int hp;
  Vec2 speed;
  int nMinions;
  std::vector<std::weak_ptr<GameObject>> minionArray;

  enum AlienState { RESTING, MOVING };
  AlienState state;
  Timer restTimer;
  float restTime;
  Vec2 destination;

};
#endif /* ALIEN_H_ */
