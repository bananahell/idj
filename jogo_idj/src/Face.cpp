/**
 * @file Face.cpp
 *
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Face.h"

#include "Sound.h"
#include "Sprite.h"


Face::Face(GameObject& associated) : Component(associated) {

  Face::hitpoints = 30;

}

void Face::Damage(int damage) {

  Face::hitpoints -= damage;
  if (Face::hitpoints <= 0) {
    static_cast<Sound*>(Face::associated.GetComponent("Sound"))->Play(1);
    Sprite* sp = static_cast<Sprite*>(Face::associated.GetComponent("Sprite"));
    if (sp != nullptr) {
      Face::associated.RemoveComponent(sp);
    }
    printf("Face::Damage\n");
  }

}

void Face::Update(float dt) {

  if (Face::hitpoints <= 0) {
    printf("Face::Update\n");
    if (!(static_cast<Sound*>(Face::associated.GetComponent("Sound"))->GetIsPlaying())) {
      Face::associated.RequestDelete();
    }
  }

}

void Face::Render() {


}

bool Face::Is(std::string type) {

  if (type.compare("Face") == 0) {
    return true;
  }
  return false;

}

bool Face::IsDead() {

  return Face::hitpoints <= 0;

}
