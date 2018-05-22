#include "Alien.h"

#include "Bullet.h"
#include "Collider.h"
#include "Game.h"
#include "Minion.h"
#include "PenguinBody.h"
#include "Sound.h"
#include "Sprite.h"


int Alien::alienCount = 0;

Alien::Alien(GameObject& associated, int nMinions) : Component(associated), speed(Vec2()) {

  Alien::hp = 10;
  Alien::nMinions = nMinions;

  Alien::state = RESTING;
  Alien::restTime = 1 + (rand()%11)/10;

  associated.AddComponent(new Sprite(associated, "assets/img/alien.png"));
  associated.AddComponent(new Collider(associated));

  Alien::alienCount++;

}

Alien::~Alien() {

  Alien::minionArray.clear();

  Alien::alienCount--;

}

void Alien::Start() {

  for (int i = 0; i < nMinions; i++) {
    GameObject* go = new GameObject();
    go->AddComponent(new Minion(*go, associated, i * (360/Alien::nMinions)));
    Alien::minionArray.push_back(Game::GetInstance().GetCurrentState().AddObject(go));
  }

}

void Alien::Damage(int damage) {

  Alien::hp -= damage;
  if (Alien::hp < 1) {
    Alien::associated.RequestDelete();
    GameObject* go = new GameObject();
    go->AddComponent(new Sprite(*go, "assets/img/aliendeath.png", 4, 0.15, false, 1.5));
    Sound* sound = new Sound(*go, "assets/audio/boom.wav");
    sound->Play();
    go->AddComponent(sound);
    go->box.SetCenter(Alien::associated.box.GetCenter());
    go->rotation = rand()%360;
    Game::GetInstance().GetCurrentState().AddObject(go);
  }

}

void Alien::Update(float dt) {

  Alien::associated.rotation -= 60 * dt;

  if (PenguinBody::player) {
    if (Alien::state == RESTING) {
      Alien::restTimer.Update(dt);
      if (Alien::restTimer.Get() > Alien::restTime) {
        Alien::state = MOVING;
        Alien::restTimer.Restart();
        Alien::restTime = 1 + (rand()%11)/10;
        Alien::destination = PenguinBody::player->GetPlayerCenter();
      }
    } else if (Alien::state == MOVING) {
      Vec2 pos = Alien::associated.box.GetCenter();
      Vec2 dest = destination;

      float sin = pos.GetSin(dest);
      if (sin != sin) {
        sin = 0;
      }
      float cos = pos.GetCos(dest);
      if (cos != cos) {
        cos = 0;
      }

      Alien::speed = Vec2(500 * cos, 500 * sin);
      if ((pos.x + speed.x * dt > dest.x && dest.x > pos.x) ||
          (pos.x + speed.x * dt < dest.x && dest.x < pos.x)) {
        pos.x = dest.x;
      } else {
        pos.x += speed.x*dt;
      }
      if ((pos.y+speed.y*dt > dest.y && dest.y > pos.y) || (pos.y+speed.y*dt < dest.y && dest.y < pos.y)) {
        pos.y = dest.y;
      } else {
        pos.y += speed.y*dt;
      }
      associated.box.SetCenter(pos);

      if (pos.x == dest.x && pos.y == dest.y) {
        Alien::state = RESTING;
        Alien::destination = PenguinBody::player->GetPlayerCenter();
        if (!minionArray.empty()) {
          int nearestMinion = 0;
          float minionDS = minionArray[0].lock()->box.GetCenter().GetDS(destination);
          for (unsigned int i = 1; i < minionArray.size(); i++) {
            if (minionArray[i].lock()->box.GetCenter().GetDS(destination) < minionDS) {
              nearestMinion = i;
              minionDS = minionArray[i].lock()->box.GetCenter().GetDS(destination);
            }
          }
          Minion* minion = static_cast<Minion*>(minionArray[nearestMinion].lock()->GetComponent("Minion"));
          minion->Shoot(destination);
        }
      }
    }
  }

}

void Alien::Render() {


}

void Alien::NotifyCollision(GameObject& other) {

  Bullet* bullet = static_cast<Bullet*>(other.GetComponent("Bullet"));
  if (bullet) {
    if (!bullet->IsOwner("Alien")) {
      Damage(bullet->GetDamage());
    }
  }

}

bool Alien::Is(std::string type) {

  if (type.compare("Alien") == 0) {
    return true;
  }
  return false;

}
