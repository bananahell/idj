/**
 * @file Face.cpp
 *
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Face.h"

#include "Sound.h"


Face::Face(GameObject& associated) : Component(associated) {

  Face::hitpoints = 30;

}

void Face::Damage(int damage) {

  Face::hitpoints -= damage;
  if (Face::hitpoints <= 0) {
    Face::associated.RequestDelete();
    static_cast<Sound*>(Face::associated.GetComponent("Sound"))->Play();
  }

}

void Face::Update(float dt) {


}

void Face::Render() {


}

bool Face::Is(std::string type) {

  if (type.compare("Face") == 0) {
    return true;
  }
  return false;

}
