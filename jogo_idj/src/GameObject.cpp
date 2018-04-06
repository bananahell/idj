/**
 * @file GameObject.cpp
 *
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "GameObject.h"

#include "Component.h"


GameObject::GameObject() : box(Rect()){

  GameObject::isDead = false;

}

GameObject::~GameObject() {

  for (int i = (int)GameObject::components.size() - 1; i >= 0; i--) {
    delete GameObject::components.at(i);
  } // TODO lembrar que só tira isso se eu usar unique_ptr direito
  GameObject::components.clear();

}

void GameObject::Update(float dt) {

  for (int i = (int)GameObject::components.size() - 1; i >= 0; i--) {
    GameObject::components.at(i)->Update(dt);
  }

}

void GameObject::Render() {

  for (int i = (int)GameObject::components.size() - 1; i >= 0; i--) {
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
    // TODO tá certo comparar dois ponteiros assim?
    // PRINCIPALMENTE PARA UNIQUE_PTR
    if (GameObject::components.at(position) == cpt) { /* .get() */
      delete GameObject::components.at(position);
      GameObject::components.erase(GameObject::components.begin() + position);
      notHere = false;
      break;
    }
  }

  if (notHere) {
    // TODO não achou o elemento no vetor.... sentar e chorar?
  }

}

Component* GameObject::GetComponent(std::string type) {

  for (int i = (int)GameObject::components.size() - 1; i >= 0; i--) {
    if (GameObject::components.at(i)->Is(type)) {
      return GameObject::components.at(i); /* .get() */
    }
  }
  return nullptr;

}
