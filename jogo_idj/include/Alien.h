/**
 * @file Component.h
 *
 * Component's functions' declarations.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#ifndef ALIEN_H
#define ALIEN_H

#include "Component.h"

#include <memory>
#include <queue>
#include <string>
#include <vector>


class Alien : public Component {

 public:

  Alien(GameObject& associated, int nMinions);
  ~Alien();
  void Start();
  void Update(float dt);
  void Render(Vec2 cameraPos);
  bool Is(std::string type);

 private:

  class Action {

   public:

    enum ActionType { MOVE, SHOOT };
    ActionType type;
    Vec2 pos;

    Action(ActionType type, float x, float y);

  };

  Vec2 speed;
  int hp;
  std::queue<Action> taskQueue;
  std::vector<std::weak_ptr<GameObject>> minionArray;
  int nMinions;

};

#endif /* ALIEN_H */
