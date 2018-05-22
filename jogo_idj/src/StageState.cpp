#include "StageState.h"

#include "Alien.h"
#include "Camera.h"
#include "CameraFollower.h"
#include "Collider.h"
#include "Collision.h"
#include "EndState.h"
#include "Game.h"
#include "GameData.h"
#include "InputManager.h"
#include "PenguinBody.h"
#include "Sound.h"
#include "Sprite.h"
#include "Text.h"
#include "TileMap.h"


StageState::StageState() : State(), backgroundMusic("assets/audio/stageState.ogg") {

  StageState::bg = new GameObject();
  StageState::map = new GameObject();
  StageState::set = new TileSet(*map, "assets/img/tileset.png", 64, 64);

  StageState::bg->AddComponent(new Sprite(*bg, "assets/img/ocean.jpg"));
  StageState::bg->AddComponent(new CameraFollower(*bg));
  StageState::bg->box.SetSize(Vec2());

  StageState::map->AddComponent(new TileMap(*map, "assets/map/tileMap.txt", StageState::set));
  StageState::map->box = Rect();

  for (int i = 0; i < 3; i++) {
    GameObject* go = new GameObject();
    go->AddComponentAsFirst(new Alien(*go, 2 + rand()%11));
    go->box.SetCenter(rand()%1409, rand()%1280);
    AddObject(go);
  }

  GameObject* go = new GameObject();
  go->AddComponentAsFirst(new PenguinBody(*go));
  go->box.SetCenter(704, 640);
  AddObject(go);

  Camera::Follow(go);

  backgroundMusic.Play();

}

StageState::~StageState() {

  delete StageState::set;
  delete StageState::map;
  delete StageState::bg;

}

void StageState::LoadAssets() {


}

void StageState::Start() {

  LoadAssets();
  StageState::bg->Start();
  StageState::map->Start();
  StartArray();
  StageState::started = true;

}

void StageState::Pause() {

  for (unsigned int i = 0; i < StageState::objectArray.size(); i++) {
    Sound* sound = static_cast<Sound*>(StageState::objectArray[i]->GetComponent("Sound"));
    if (sound) {
      sound->Stop();
    }
  }

}

void StageState::Resume() {

  StageState::backgroundMusic.Play();
  StageState::objectArray.clear();

  for (int i = 0; i < 3; i++) {
    GameObject* go = new GameObject();
    go->AddComponentAsFirst(new Alien(*go, 2 + rand()%11));
    go->box.SetCenter(rand()%1409, rand()%1280);
    AddObject(go);
  }

  GameObject* go = new GameObject();
  go->AddComponentAsFirst(new PenguinBody(*go));
  go->box.SetCenter(704, 640);
  AddObject(go);

  Camera::Follow(go);

}

void StageState::CollisionCheck() {

  for (unsigned int i = 0; i < StageState::objectArray.size(); i++) {
    for (unsigned int j = i + 1; j < StageState::objectArray.size(); j++) {
      if (StageState::objectArray[i]->IsActive() && StageState::objectArray[j]->IsActive()) {
        Collider* objA = static_cast<Collider*>(StageState::objectArray[i]->GetComponent("Collider"));
        Collider* objB = static_cast<Collider*>(StageState::objectArray[j]->GetComponent("Collider"));
        if (objA && objB) {
          if (Collision::IsColliding(objA->box, objB->box, objA->rotation, objB->rotation)) {
            StageState::objectArray[i]->NotifyCollision(*objectArray[j]);
            StageState::objectArray[j]->NotifyCollision(*objectArray[i]);
          }
        }
      }
    }
  }

}

void StageState::DeletionCheck() {

  for (int i = StageState::objectArray.size() - 1; i >= 0; i--) {
    if (StageState::objectArray[i]->IsDead()) {
      if (Camera::GetFocus() == StageState::objectArray[i].get()) {
        Camera::Unfollow();
      }
      StageState::objectArray.erase(StageState::objectArray.begin() + i);
    }
  }

}

void StageState::Update(float dt) {

  StageState::quitRequested = InputManager::QuitRequested();
  if (InputManager::KeyPress(ESCAPE_KEY)) {
    StageState::popRequested = true;
  }

  if (StageState::bg->IsActive()) {
    StageState::bg->Update(dt);
  }
  if (StageState::map->IsActive()) {
    StageState::map->Update(dt);
  }
  UpdateArray(dt);
  CollisionCheck();
  DeletionCheck();

  if (!PenguinBody::player) {
    GameData::playerVictory = false;
    Game::GetInstance().Push(new EndState());
  } else if (Alien::alienCount < 1) {
    GameData::playerVictory = true;
    Game::GetInstance().Push(new EndState());
  }

}

void StageState::Render() {

  TileMap* tileMap = static_cast<TileMap*>(StageState::map->GetComponent("TileMap"));

  if (StageState::bg->IsActive()) {
    StageState::bg->Render();
  }
  if (StageState::map->IsActive()) {
    tileMap->RenderLayer(0, Camera::pos.x, Camera::pos.y);
  }
  RenderArray();
  if (StageState::map->IsActive()) {
    tileMap->RenderLayer(1, Camera::pos.x * 1.5, Camera::pos.y * 1.5);
  }

}
