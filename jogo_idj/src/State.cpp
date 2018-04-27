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

#include "Camera.h"
#include "CameraFollower.h"
#include "Face.h"
#include "InputManager.h"
#include "Sound.h"
#include "Sprite.h"
#include "TileMap.h"
#include "TileSet.h"
#include "Vec2.h"


State::State() : music(Music()) {

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

  if (InputManager::GetInstance().KeyPress(SPACE_KEY)) {
    Vec2 objPos = Vec2(InputManager::GetInstance().GetMouseX(),
                       InputManager::GetInstance().GetMouseY());
    objPos.GetRandWithDistance((float)200);
    State::AddObject((int)objPos.x, (int)objPos.y);
  }

  if (InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON)) {
    for (int i = State::objectArray.size() - 1; i >= 0; i--) {
      if (State::objectArray[i]->
                 box.Contains(InputManager::GetInstance().GetMouseX(),
                              InputManager::GetInstance().GetMouseY())) {

        Face* face = static_cast<Face*>(State::objectArray[i]->GetComponent("Face"));
        if (face != nullptr) {
          if (!face->IsDead()) {
            face->Damage(std::rand() % 10 + 10);
            Camera::Follow(objectArray[i].get());
            break;
          }
        }

      }
    }
  }

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

  static_cast<TileMap*>(State::tileMap->GetComponent("TileMap"))->
                        RenderLayer(0, Camera::pos.x, Camera::pos.y);
  /* Rendering background in top left corner. */
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

void State::AddObject(int mouseX, int mouseY) {

  /* Instantiates the object. */
  GameObject* newEnemy = new GameObject();

  /* Sets its Rect. */
  newEnemy->box.x = mouseX;
  newEnemy->box.y = mouseY;

  /* Adds its components to build a penguin. */
  newEnemy->AddComponent(new Sprite(*newEnemy, "assets/img/penguinface.png"));
  newEnemy->AddComponent(new Sound(*newEnemy, "assets/audio/boom.wav"));
  newEnemy->AddComponent(new Face(*newEnemy));

  /* Correction needed to surround the mouse pointer exactly. */
  newEnemy->box.x -=
      static_cast<Sprite*>(newEnemy->GetComponent("Sprite"))->GetWidth() / 2;
  newEnemy->box.y -=
      static_cast<Sprite*>(newEnemy->GetComponent("Sprite"))->GetHeight() / 2;

  /* Placing this new object in the object vector. */
  State::objectArray.emplace_back(newEnemy);

}
