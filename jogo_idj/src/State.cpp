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

#include "Face.h"
#include "Sound.h"
#include "Sprite.h"
#include "Vec2.h"


State::State() : music(Music()) {

  GameObject* bg = new GameObject();
  bg->box.x = 0;
  bg->box.y = 0;
  bg->AddComponent(new Sprite(*bg, "assets/img/ocean.jpg"));
  State::objectArray.emplace_back(bg);

  State::quitRequested = false;

}

void State::LoadAssets() {

  /* Music assets. */
  State::music.Open("assets/audio/stageState.ogg");
  State::music.Play();

}

void State::Update(float dt) {

  /* Call for input detection. */
  State::Input();
  /* Call for objects' update. */
  for (int i = (int)State::objectArray.size() - 1; i >= 0; i--) {
    State::objectArray.at(i)->Update(dt);
  }
  /* Sweep of dead objects around the game. */
  for (int i = (int)State::objectArray.size() - 1; i >= 0; i--) {
    if (State::objectArray.at(i)->IsDead()) {
        State::objectArray.erase(State::objectArray.begin() + i);
    }
  }

}

void State::Render() {

  /* Rendering background in top left corner. */
  for (unsigned int i = 0; i < State::objectArray.size(); i++) {
    State::objectArray.at(i).get()->Render();
  }

}

bool State::QuitRequested() {

  return State::quitRequested;

}

State::~State() {

  State::objectArray.clear();

}

void State::Input() {

  SDL_Event event;
  int mouseX, mouseY;

  /* Gets mouse coordinates. */
  SDL_GetMouseState(&mouseX, &mouseY);

  /* Gets user input events and treats them. */
  while (SDL_PollEvent(&event)) {

    /* Quit the game. */
    if (event.type == SDL_QUIT) {
      State::quitRequested = true;
    }

    /* Mouse click even - hitting a penguin. */
    if (event.type == SDL_MOUSEBUTTONDOWN) {
      /* Always clicking on upper most object with this loop. */
      for (int i = State::objectArray.size() - 1; i >= 0; --i) {
        /* Gets game object. */
        GameObject* go = (GameObject*)State::objectArray.at(i).get();
        /* Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.*
         * O propósito do unique_ptr é manter apenas uma cópia daquele        *
         * ponteiro, ao usar get(), violamos esse princípio e estamos menos   *
         * seguros. Esse código, assim como a classe Face, é provisório.      *
         * Futuramente, para chamar funções de GameObjects, use               *
         * objectArray[i]->função() direto.                                   */
        if (go->box.Contains((float)mouseX, (float)mouseY)) {
          Face* face = (Face*)go->GetComponent("Face");
          if (face != nullptr) {
            if (!(face->IsDead())) {
              face->Damage(std::rand() % 10 + 10);
              break;
            }
          }
        }
      }
    }
    if (event.type == SDL_KEYDOWN) {
      /* ESC key - quit the game. */
      if (event.key.keysym.sym == SDLK_ESCAPE) {
        State::quitRequested = true;
      }
      /* Any other key creates a penguin object. */
      else {
        Vec2 objPos = Vec2(mouseX, mouseY);
        objPos.GetRandWithDistance((float)200);
        State::AddObject((int)objPos.x, (int)objPos.y);
      }
    }
  }

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
