/**
 * @file Component.cpp
 *
 * Parts of the game objects in the game.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Alien.h"

#include "Game.h"
#include "InputManager.h"
#include "Minion.h"
#include "Sprite.h"


Alien::Alien(GameObject& associated, int nMinions) : Component(associated) {

  Alien::hp = 10;
  Alien::speed = Vec2();
  Alien::nMinions = nMinions;

  associated.AddComponent(new Sprite(associated, "assets/img/alien.png"));

}

void Alien::Start() {

  for (int i = 0; i < nMinions; i++) {
    GameObject* go = new GameObject();
    go->AddComponent(new Minion(*go, associated, i*(360/nMinions)));
    minionArray.push_back(Game::GetInstance().GetState().AddObject(go));
  }

}

Alien::~Alien() {

  minionArray.clear();

}

void Alien::Update(float dt) {

  Rect box = Alien::associated.box;
  Vec2 mousePos = Vec2(InputManager::GetInstance().GetMouseX(),
                       InputManager::GetInstance().GetMouseY());

  if (InputManager::MousePress(LEFT_MOUSE_BUTTON)) {
    Alien::taskQueue.push(Action(Action::SHOOT, mousePos.x, mousePos.y));
  }
  if (InputManager::MousePress(RIGHT_MOUSE_BUTTON)) {
    Alien::taskQueue.push(Action(Action::MOVE,
                                 mousePos.x - box.w/2,
                                 mousePos.y - box.h/2));
  }

  if (Alien::taskQueue.size() > 0) {
    Vec2 pos = Alien::taskQueue.front().pos;
    if (taskQueue.front().type == Action::SHOOT) {
      int nearestMinion = 0;
      float minionDS = minionArray[0].lock()->box.GetCenter().GetDS(pos);
      for (int i = 1; i < minionArray.size(); i++) {
        if (minionArray[i].lock()->box.GetCenter().GetDS(pos) < minionDS) {
          nearestMinion = i;
          minionDS = minionArray[i].lock()->box.GetCenter().GetDS(pos);
        }
      }
      Minion* m = (Minion*) minionArray[nearestMinion].lock()->GetComponent("Minion");
      m->Shoot(pos);
      taskQueue.pop();
    } else if (taskQueue.front().type == Action::MOVE) {
      float cos = box.GetPos().GetCos(pos);
      if (cos != cos) {
        cos = 0;
      }
      float sin = box.GetPos().GetSin(pos);
      if (sin != sin) {
        sin = 0;
      }
      speed = Vec2(500*cos, 500*sin);
      if ((box.x+speed.x*dt > pos.x && pos.x > box.x) ||
          (box.x+speed.x*dt < pos.x && pos.x < box.x)) {
        box.x = pos.x;
      } else {
        box.x += speed.x*dt;
      }
      if ((box.y+speed.y*dt > pos.y && pos.y > box.y) ||
          (box.y+speed.y*dt < pos.y && pos.y < box.y)) {
        box.y = pos.y;
      } else {
        box.y += speed.y*dt;
      }
      if (box.x == pos.x && box.y == pos.y) {
        taskQueue.pop();
      }
      associated.box = box;
    }
  }

  if (hp < 1) {
    associated.RequestDelete();
  }

}

void Alien::Render(Vec2 cameraPos) {

}

bool Alien::Is(std::string type) {

  if (type.compare("Alien") == 0) {
    return true;
  }
  return false;

}

Alien::Action::Action(ActionType type, float x, float y) {

  Action::type = type;
  pos = Vec2(x, y);

}
