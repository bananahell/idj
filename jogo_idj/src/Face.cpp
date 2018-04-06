/**
 * @file Face.cpp
 *
 * Mechanics component of a game's object.
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
  /* If the game's object dies, plays death sound and hides its texture. */
  if (Face::hitpoints <= 0) {
    static_cast<Sound*>(Face::associated.GetComponent("Sound"))->Play(1);
    Sprite* sprite =
        static_cast<Sprite*>(Face::associated.GetComponent("Sprite"));
    if (sprite != nullptr) {
      Face::associated.RemoveComponent(sprite);
    }
  }

}

void Face::Update(float dt) {

  /* If the game object dies and its death sound ends, delete it entirely. */
  if (Face::hitpoints <= 0) {
    if (!(static_cast<Sound*>(Face::associated.GetComponent("Sound"))->
                                  GetIsPlaying())) {
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
