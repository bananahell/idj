/**
 * @file State.cpp
 *
 * Game's logic coordinator.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#define INCLUDE_SDL
#include "SDL_include.h"

#include "State.h"

#include "Alien.h"
#include "Camera.h"
#include "CameraFollower.h"
#include "InputManager.h"
#include "Sound.h"
#include "Sprite.h"
#include "TileMap.h"
#include "TileSet.h"
#include "Vec2.h"


State::State() : music(Music()) {

  State::started = false;

  /* Background's game object being made. */
  State::bg = new GameObject();
  State::bg->box.x = 0;
  State::bg->box.y = 0;
  State::bg->AddComponent(new Sprite(*bg, "assets/img/ocean.jpg"));
  State::bg->AddComponent(new CameraFollower(*bg));

  /* Tile map's game object being made. */
  State::tileMap = new GameObject();
  TileSet* tileSet = new TileSet(*tileMap, 64, 64, "assets/img/tileset.png");
  State::tileMap->box.x = 0;
  State::tileMap->box.y = 0;
  State::tileMap->AddComponent(new TileMap(*tileMap,
                               "assets/map/tileMap.txt",
                               tileSet));

  GameObject* go = new GameObject();
  go->AddComponent(new Alien(*go, 8));
  go->box.x = 512 - go->box.w/2;
  go->box.y = 300 - go->box.h/2;
  AddObject(go);

  State::quitRequested = false;

}

void State::LoadAssets() {

  /* Music assets. */
  State::music.Open("assets/audio/stageState.ogg");
  State::music.Play();

}

void State::Update(float dt) {

  State::quitRequested = InputManager::GetInstance().QuitRequested();

  Camera::Update(dt);
  State::bg->Update(dt);
  State::tileMap->Update(dt);

  /* Call for objects' update. */
  for (int i = (int)State::objectArray.size() - 1; i >= 0; i--) {
    State::objectArray.at(i)->Update(dt);
  }
  /* Sweep of dead objects around the game. */
  for (int i = (int)State::objectArray.size() - 1; i >= 0; i--) {
    if (State::objectArray.at(i)->IsDead()) {
      Camera::Unfollow();
      State::objectArray.erase(State::objectArray.begin() + i);
    }
  }

}

void State::Render() {

  State::bg->Render(Camera::pos);
  static_cast<TileMap*>(State::tileMap->GetComponent("TileMap"))->
                        RenderLayer(0, Camera::pos.x, Camera::pos.y);
  for (unsigned int i = 0; i < State::objectArray.size(); i++) {
    State::objectArray.at(i).get()->Render(Camera::pos);
  }

}

bool State::QuitRequested() {

  return State::quitRequested;

}

State::~State() {

  State::objectArray.clear();

}

std::weak_ptr<GameObject> State::AddObject(GameObject* go) {

  /* Instantiates the object. */
  std::shared_ptr<GameObject> pointer = std::shared_ptr<GameObject>(go);

  /* Placing this new object in the object vector. */
  State::objectArray.push_back(pointer);

  if (State::started) {
    pointer->Start();
  }

  return pointer;

}

void State::Start() {

  State::LoadAssets();
  for (int i = 0; i < State::objectArray.size(); i++) {
    State::objectArray[i]->Start();
  }
  State::started = true;

}

std::weak_ptr<GameObject> State::GetObjectPtr(GameObject* go) {

  for (int i = 0; i < State::objectArray.size(); i++) {
    if (State::objectArray[i].get() == go) {
      return State::objectArray[i];
    }
  }
  return std::weak_ptr<GameObject>();

}
