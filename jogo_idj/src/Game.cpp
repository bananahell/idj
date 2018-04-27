/**
 * @file Game.cpp
 * 
 * Game's basic engine functions.
 *
 * @author Pedro Nogueira - 14/0065032
 */

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "Game.h"

#include "InputManager.h"
#include "Resources.h"


Game* Game::instance = nullptr;

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

  if (Mix_Init(MIX_INIT_FLAC | MIX_INIT_OGG | MIX_INIT_FLUIDSYNTH |
               MIX_INIT_MP3 | MIX_INIT_MOD | MIX_INIT_MODPLUG) == 0) {
    SDL_Log("Unable to initialize MIX: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,
                    MIX_DEFAULT_CHANNELS, 1024) != 0) {
    SDL_Log("Unable to initialize OpenAudio: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  Mix_AllocateChannels(32);

  /* Window and renderer creation. */
  Game::window = SDL_CreateWindow(title.c_str(),
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  width, height,
                                  0);

  if (Game::window == nullptr) {
    SDL_Log("Unable to initialize window: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  Game::renderer = SDL_CreateRenderer(Game::window,
                                      -1,
                                      SDL_RENDERER_ACCELERATED |
                                      SDL_RENDERER_TARGETTEXTURE |
                                      SDL_RENDERER_PRESENTVSYNC/* |
                                      SDL_RENDERER_SOFTWARE*/);

  if (Game::renderer == nullptr) {
    SDL_Log("Unable to initialize renderer: %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  /* Game's State creation. */
  Game::state = new State();

}

Game::~Game() {

  delete Game::state;

  /* Clearing every resource before quitting. */
  Resources::ClearImages();
  Resources::ClearMusics();
  Resources::ClearSounds();

  Mix_CloseAudio();
  Mix_Quit();
  IMG_Quit();
  SDL_DestroyWindow(Game::window);
  SDL_DestroyRenderer(Game::renderer);
  SDL_Quit();

}

void Game::Run() {

  /* Load assets before the game's loop. */
  Game::GetInstance().state->LoadAssets();

  /* Execute game's loop with its functionalities. */
  while (Game::state->QuitRequested() == false) {
    CalculateDeltaTime();
    InputManager::GetInstance().Update();
    Game::GetInstance().state->Update(GetDeltaTime());
    Game::GetInstance().state->Render();
    SDL_RenderPresent(Game::GetInstance().renderer);
    SDL_Delay(33);
  }

}

SDL_Renderer* Game::GetRenderer() {

  return Game::renderer;

}

State& Game::GetState() {

  return *state;

}

Game& Game::GetInstance() {

  /* Singleton instance. */
  if (Game::instance == nullptr) {
    Game::instance = new Game("Pedro Nogueira - 14/0065032", 1024, 600);
  }
  return *instance;

}

void Game::CalculateDeltaTime() {

  Game::dt = (SDL_GetTicks()/1000) - Game::frameStart;
  Game::frameStart = Game::frameStart + Game::dt;

}

float Game::GetDeltaTime() {

  return Game::dt;

}
