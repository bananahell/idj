#include "State.h"


State::State() {

  State::popRequested = false;
  State::quitRequested = false;
  State::started = false;

}

State::~State() {

  State::objectArray.clear();

}

std::weak_ptr<GameObject> State::AddObject(GameObject* go) {

  std::shared_ptr<GameObject> shared = std::shared_ptr<GameObject>(go);
  State::objectArray.push_back(shared);
  if (State::started) {
    shared->Start();
  }
  return shared;

}

std::weak_ptr<GameObject> State::GetObjectPtr(GameObject* go) {

  for (unsigned int i = 0; i < State::objectArray.size(); i++) {
    if (State::objectArray[i].get() == go) {
      return State::objectArray[i];
    }
  }
  return std::weak_ptr<GameObject>();

}

void State::StartArray() {

  for (unsigned int i = 0; i < State::objectArray.size(); i++) {
    State::objectArray[i]->Start();
  }

}

void State::UpdateArray(float dt) {

  for (unsigned int i = 0; i < State::objectArray.size(); i++) {
    if (State::objectArray[i]->IsActive()) {
      State::objectArray[i]->Update(dt);
    }
  }

}

void State::RenderArray() {

  for (unsigned int i = 0; i < State::objectArray.size(); i++) {
    if(State::objectArray[i]->IsActive()) {
      State::objectArray[i]->Render();
    }
  }

}

bool State::PopRequested() {

  return State::popRequested;

}

bool State::QuitRequested() {

  return State::quitRequested;

}
