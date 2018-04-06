/**
 * @file GameObject.cpp
 *
 * Game's objects encapsulator.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "GameObject.h"

#include "Component.h"


GameObject::GameObject() : box(Rect()){

  GameObject::isDead = false;

}

GameObject::~GameObject() {

  GameObject::components.clear();

}

void GameObject::Update(float dt) {

  for (int i = (int)GameObject::components.size() - 1; i >= 0; i--) {
    GameObject::components.at(i)->Update(dt);
  }

}

void GameObject::Render() {

  for (unsigned int i = 0; i < GameObject::components.size(); i++) {
    GameObject::components.at(i)->Render();
  }

}

bool GameObject::IsDead() {

  return GameObject::isDead;

}

void GameObject::RequestDelete() {

  GameObject::isDead = true;

}

void GameObject::AddComponent(Component* cpt) {

  GameObject::components.emplace_back(cpt);

}

void GameObject::RemoveComponent(Component* cpt) {

  unsigned int position = 0;
  bool notHere = true;
  while (position != GameObject::components.size()) {
    if (GameObject::components.at(position).get() == cpt) {
      GameObject::components.erase(GameObject::components.begin() + position);
      notHere = false;
      break;
    }
  }

  if (notHere) {
  }

}

Component* GameObject::GetComponent(std::string type) {

  for (int i = (int)GameObject::components.size() - 1; i >= 0; i--) {
    if (GameObject::components.at(i)->Is(type)) {
      return GameObject::components.at(i).get();
    }
  }
  return nullptr;

}
