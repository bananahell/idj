/**
 * @file Game.cpp
 *
 * Game's basic engine functions.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_TTF

#include "Game.h"

#include "Camera.h"
#include "InputManager.h"
#include "Resources.h"

#include <stdlib.h>
#include <time.h>


Game* Game::instance;
std::stack<std::unique_ptr<State>> Game::stateStack;
State* Game::storedState;

Game::Game(std::string title, int width, int height) {

  /* Needed for singleton use of instance. */
  if (Game::instance != nullptr) {
    exit(EXIT_FAILURE);
  }

  Game::instance = this;

  /* Initialization of basic SDL functionalities. */
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0) {
    SDL_Log("Unable to initialize IMG: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  if (Mix_Init(MIX_INIT_OGG) == 0) {
    SDL_Log("Unable to initialize MIX: %s", SDL_GetError());
  }

  if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0) {
    SDL_Log("Unable to initialize OpenAudio: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  Mix_AllocateChannels(32);

  if (TTF_Init()) {
    SDL_Log("Unable to initialize TTF: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  /* Window and renderer creation. */
  Game::window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
  if (Game::window == nullptr) {
    SDL_Log("Unable to initialize window: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  Game::renderer = SDL_CreateRenderer(Game::window,
                                      -1,
                                      SDL_RENDERER_ACCELERATED |
                                      SDL_RENDERER_TARGETTEXTURE |
                                      SDL_RENDERER_PRESENTVSYNC);
  if (Game::renderer == nullptr) {
    SDL_Log("Unable to initialize renderer: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  srand(time(NULL));

}

Game::~Game() {

  if (Game::storedState) {
    delete Game::storedState;
  }
  while (!(Game::stateStack.empty())) {
    Game::stateStack.pop();
  }
  Resources::ClearFonts();
  Resources::ClearFonts();
  Resources::ClearFonts();
  Resources::ClearFonts();
  SDL_DestroyRenderer(Game::renderer);
  SDL_DestroyWindow(Game::window);
  TTF_Quit();
  Mix_CloseAudio();
  Mix_Quit();
  Resources::ClearFonts();
  Resources::ClearImages();
  Resources::ClearMusics();
  Resources::ClearSounds();
  IMG_Quit();
  SDL_Quit();

}

void Game::Run() {

  if (Game::storedState) {
    Game::stateStack.emplace(Game::storedState);
    Game::stateStack.top()->Start();
    Game::storedState = nullptr;
  }
  if (!(Game::stateStack.empty())) {
    /* Execute game's loop with its functionalities. */
    while (!stateStack.top()->QuitRequested()) {
      while (!(Game::storedState) && !(Game::stateStack.top()->PopRequested()) && !(Game::stateStack.top()->QuitRequested())) {
        if (SDL_RenderClear(Game::renderer)) {
          SDL_Log("Unable to clear renderer: %s", SDL_GetError());
        }
        CalculateDeltaTime();
        Camera::Update(GetDeltaTime());
        InputManager::Update();
        Game::stateStack.top()->Update(GetDeltaTime());
        Game::stateStack.top()->Render();
        SDL_RenderPresent(Game::renderer);
        SDL_Delay(33);
      }
      if (Game::storedState) {
        Game::stateStack.top()->Pause();
        Game::stateStack.emplace(Game::storedState);
        Game::stateStack.top()->Start();
        Game::storedState = nullptr;
      } else if (Game::stateStack.top()->PopRequested()) {
        Game::stateStack.pop();
        if (!(Game::stateStack.empty())) {
          Game::stateStack.top()->Resume();
        }
      }
    }
  }

}

SDL_Renderer* Game::GetRenderer() {

  return Game::renderer;

}

Game& Game::GetInstance() {

  /* Singleton instance. */
  if (Game::instance == nullptr) {
    Game::instance = new Game("Pedro Nogueira - 14/0065032", 1024, 600);
  }
  return *instance;

}

void Game::CalculateDeltaTime() {

  Game::dt = SDL_GetTicks() - Game::frameStart;
  Game::frameStart = Game::frameStart + Game::dt;

}

float Game::GetDeltaTime() {

  return Game::dt/1000;

}

State& Game::GetCurrentState() {

  return *stateStack.top().get();

}

void Game::Push(State* state) {

  Game::storedState = state;

}
