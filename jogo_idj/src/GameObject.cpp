/**
 * @file GameObject.cpp
 *
 * Game's objects encapsulator.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "GameObject.h"

#include "Component.h"


GameObject::GameObject() : box (Rect()) {

  GameObject::started = false;
  GameObject::active = true;
  GameObject::isDead = false;
  GameObject::rotation = 0;

}

GameObject::~GameObject() {

  GameObject::components.clear();

}

void GameObject::Update(float dt) {

  for (int i = (int)GameObject::components.size() - 1; i >= 0; i--) {
    if (components[i]->IsActive()) {
      components[i]->Update(dt);
    }
  }

}

void GameObject::Render() {

  for (unsigned int i = 0; i < GameObject::components.size(); i++) {
    if (GameObject::components[i]->IsActive()) {
      GameObject::components[i]->Render();
    }
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
  if (GameObject::started) {
    cpt->Start();
  }

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

void GameObject::Start() {

  for (unsigned int i = 0; i < GameObject::components.size(); i++) {
    GameObject::components[i]->Start();
  }
  GameObject::started = true;

}

void GameObject::AddComponentAsFirst(Component* cpt) {

  GameObject::components.emplace(GameObject::components.begin(), cpt);
  if (GameObject::started) {
    cpt->Start();
  }

}

void GameObject::NotifyCollision(GameObject& other) {

  for (unsigned int i = 0; i < components.size(); i++) {
    if (GameObject::components[i]->IsActive()) {
      GameObject::components[i]->NotifyCollision(other);
    }
  }

}

void GameObject::Activate() {

  GameObject::active = true;

}

void GameObject::Deactivate() {

  GameObject::active = false;

}

bool GameObject::IsActive() {

  return GameObject::active;

}
