#ifndef GAME_H
#define GAME_H

#define INCLUDE_SDL
#include "SDL_include.h"

#include "State.h"

#include <memory>
#include <stack>
#include <string>


class Game {

 public:

  ~Game();

  float GetDeltaTime();
  static Game& GetInstance();
  SDL_Renderer* GetRenderer();
  State& GetCurrentState();
  void Push(State* state);
  void Run();

 private:

  Game(std::string title, int width, int height);

  void CalculateDeltaTime();

  static Game* instance;
  SDL_Window* window;
  SDL_Renderer* renderer;
  static std::stack<std::unique_ptr<State>> stateStack;
  static State* storedState;
  int frameStart;
  float dt;

};
#endif /* GAME_H */
