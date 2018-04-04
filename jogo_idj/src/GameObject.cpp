/**
 * @file GameObject.cpp
 *
 * Game's music manager.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#include "GameObject.h"

#include "Component.h"


GameObject::GameObject() {

  GameObject::isDead = false;

}

GameObject::~GameObject() {

/* TODO Sugestão melhor? Acho que não.... mais coisa pra fazer em loop
  int lastComponent = GameObject::components.size() - 1;
  while (GameObject::components.size() != 0) {
    delete GameObject::components.at(lastComponent);
    GameObject::components.pop_back();
  }
*/
  for (int i = (int)GameObject::components.size() - 1; i >= 0; i--) {
    delete GameObject::components.at(i);
  }
  GameObject::components.clear();

}

void GameObject::Update(float dt) {

  for (unsigned int i = 0; i < GameObject::components.size(); i++) {
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

  GameObject::components.push_back(cpt);

}

void GameObject::RemoveComponent(Component* cpt) {

  unsigned int position = 0;
  bool notHere = true;
  while (position != GameObject::components.size()) {
    // TODO tá certo comparar dois ponteiros assim?
    if (GameObject::components.at(position) == cpt) {
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

  // TODO wut

}
