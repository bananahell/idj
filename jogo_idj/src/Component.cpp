/**
 * @file Component.cpp
 *
 * Parts of the game objects in the game.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "Component.h"


Component::Component(GameObject& associated) : associated(associated) {

  Component::active = true;

}

Component::~Component() {


}

void Component::Start() {


}

void Component::NotifyCollision(GameObject& other) {


}

void Component::Activate() {

  Component::active = true;

}

void Component::Deactivate() {

  Component::active = false;

}

bool Component::IsActive() {

  return Component::active;

}
