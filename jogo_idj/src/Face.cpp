/**
 * @file Face.cpp
 *
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Face.h"


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

  }

}

void Face::Update(float dt) {

  // TODO int Mix_PlayChannel(int channel = -1, Mix_Chunk* chunk, int loops = times - 1)

}

void Face::Render() {

  // TODO int Mix_HaltChannel(int channel) ???

}

bool Face::Is(std::string type) {

  // TODO Mix_Chunk* Mix_LoadWAV(char* file = file.c_str())

}
