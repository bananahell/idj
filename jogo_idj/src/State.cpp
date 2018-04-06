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
#include "Game.h"
#include "Sound.h"
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

  State::Input();
  for (int i = (int)State::objectArray.size() - 1; i >= 0; i--) {
    State::objectArray.at(i)->Update(dt);
  }
  for (int i = (int)State::objectArray.size() - 1; i >= 0; i--) {
    if (State::objectArray.at(i)->IsDead()) {
      State::objectArray.erase(State::objectArray.begin() + i);
    }
  }

}

void State::Render() {

  /* Rendering background in top left corner. */
  for (int i = (int)State::objectArray.size() - 1; i >= 0; i--) {
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

  // Obtenha as coordenadas do mouse
  SDL_GetMouseState(&mouseX, &mouseY);

  // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
  while (SDL_PollEvent(&event)) {

    // Se o evento for quit, setar a flag para terminação
    if (event.type == SDL_QUIT) {
      State::quitRequested = true;
    }
    
    // Se o evento for clique...
    if (event.type == SDL_MOUSEBUTTONDOWN) {
      // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
      for (int i = State::objectArray.size() - 1; i >= 0; --i) {
        // Obtem o ponteiro e casta pra Face.
printf("entrou %d\n", i);
        GameObject* go = (GameObject*)State::objectArray.at(i).get();
        // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
        // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
        // ao usar get(), violamos esse princípio e estamos menos seguros.
        // Esse código, assim como a classe Face, é provisório. Futuramente, para
        // chamar funções de GameObjects, use objectArray[i]->função() direto.
        if (go->box.Contains((float)mouseX, (float)mouseY)) {
          Face* face = (Face*)go->GetComponent("Face");
          if (face != nullptr) {
            // Aplica dano
            printf("Vida antes = %d\n", face->hitpoints);
            face->Damage(std::rand() % 10 + 10);
            printf("Vida depois = %d\n", face->hitpoints);
            // Sai do loop (só queremos acertar um)
            break;
          }
        }
      }
    }
    if (event.type == SDL_KEYDOWN) {
      // Se a tecla for ESC, setar a flag de quit
      if (event.key.keysym.sym == SDLK_ESCAPE) {
        State::quitRequested = true;
      }
      // Se não, crie um objeto
      else {
        Vec2 objPos = Vec2(mouseX, mouseY);
        objPos.GetRandWithDistance(200);
        printf("State::Input mouseX = %d, mouseY = %d\n", mouseX, mouseY);
        State::AddObject((int)objPos.x, (int)objPos.y);
      }
    }
  }

}

void State::AddObject(int mouseX, int mouseY) {

  GameObject* newEnemy = new GameObject();
  newEnemy->box.x = mouseX;
  newEnemy->box.y = mouseY;

  newEnemy->AddComponent(new Sprite(*newEnemy, "assets/img/penguinface.png"));
  newEnemy->AddComponent(new Sound(*newEnemy, "assets/audio/boom.wav"));
  newEnemy->AddComponent(new Face(*newEnemy));

  printf("State::AddObject Enemy x = %d, y = %d, w = %d, h = %d\n",
    (int)(newEnemy->box.x), (int)(newEnemy->box.y),
    (int)(static_cast<Sprite*>(newEnemy->GetComponent("Sprite"))->GetWidth()),
    (int)(static_cast<Sprite*>(newEnemy->GetComponent("Sprite"))->GetHeight()));
  State::objectArray.emplace_back(newEnemy);

}
