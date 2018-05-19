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
#include "Collider.h"
#include "Minion.h"
#include "Sprite.h"
#include "PenguinBody.h"


Alien::Alien(GameObject& associated, int nMinions) : Component(associated) {

  Alien::hp = 10;
  Alien::speed = Vec2();
  Alien::nMinions = nMinions;

  associated.AddComponent(new Sprite(associated, "assets/img/alien.png"));
  associated.AddComponent(new Collider(associated));

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

  associated.rotation -= 60*dt;

  if (PenguinBody::player) {
    if (state == RESTING) {
      restTimer.Update(dt);
      if (restTimer.Get() > restTime) {
        state = MOVING;
        restTimer.Restart();
        restTime = 1 + (rand()%11)/10;
        destination = PenguinBody::player->GetPlayerCenter();
      }
    } else if (state == MOVING) {
      Vec2 pos = associated.box.GetCenter();
      Vec2 dest = destination;

      float cos = pos.GetCos(dest);
      if (cos != cos) {
        cos = 0;
      }
      float sin = pos.GetSin(dest);
      if (sin != sin) {
        sin = 0;
      }
      speed = Vec2(500*cos, 500*sin);
      if ((pos.x+speed.x*dt > dest.x && dest.x > pos.x) ||
          (pos.x+speed.x*dt < dest.x && dest.x < pos.x)) {
        pos.x = dest.x;
      } else {
        pos.x += speed.x*dt;
      }
      if ((pos.y+speed.y*dt > dest.y && dest.y > pos.y) ||
          (pos.y+speed.y*dt < dest.y && dest.y < pos.y)) {
        pos.y = dest.y;
      } else {
        pos.y += speed.y*dt;
      }
      associated.box.SetCenter(pos);

      if (pos.x == dest.x && pos.y == dest.y) {
        state = RESTING;
        destination = PenguinBody::player->GetPlayerCenter();
        int nearestMinion = 0;
        float minionDS = minionArray[0].lock()->box.GetCenter().GetDS(destination);
        for (unsigned i = 1; i < minionArray.size(); i++) {
          if (minionArray[i].lock()->box.GetCenter().GetDS(destination) < minionDS) {
            nearestMinion = i;
            minionDS = minionArray[i].lock()->box.GetCenter().GetDS(destination);
          }
        }
        Minion* m = static_cast<Minion*>(minionArray[nearestMinion].lock()->GetComponent("Minion"));
        m->Shoot(destination);
      }
    }
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
