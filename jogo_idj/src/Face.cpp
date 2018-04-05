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

  // TODO Primeiro, deve construir sua classe mãe
  Face::hitpoints = 30;

}

void Face::Damage(int damage) {

  Face::hitpoints -= damage;
  if (Face::hitpoints <= 0) {
    /* TODO
    Deve reduzir os hitpoints na quantidade passada. E se ficar menor
ou igual a zero, chame o RequestDelete do GO que o contém (associated),
e dê play no componente Sound de seu associated, se houver um.
*/
    // GameObject::RequestDelete(); // TODO ????
    Face::associated.RequestDelete();
    Sound* sound = (Sound*)Face::associated.GetComponent("Sound");
    sound->Play();

  }

}

void Face::Update(float dt) {

  // TODO int Mix_PlayChannel(int channel = -1, Mix_Chunk* chunk, int loops = times - 1)

}

void Face::Render() {



}

bool Face::Is(std::string type) {

  if (type.compare("Face") == 0) {
    return true;
  }
  return false;

}
